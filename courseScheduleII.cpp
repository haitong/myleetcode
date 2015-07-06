/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
*/

#include <algorithm>
#include <vector>
class node {
public:
    vector<node *> prerequisite;
    vector<node *> requisite;
    int id;
    int in_degree;
    
    node(int i){
        id = i;
        in_degree = 0;
    };
    

};

struct comp {
    bool operator()( node *& a,  node *& b) {
        return a->in_degree > b->in_degree;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<node *> courses;
        for(int i = 0; i < numCourses; i ++){
            courses.push_back(new node(i));
        }
        
        for(auto t : prerequisites){
            courses[t.first]->in_degree += 1;
            courses[t.first]->prerequisite.push_back(courses[t.second]);
            courses[t.second]->requisite.push_back(courses[t.first]);
        }
        
        vector<int> res;
        
        
        node * curr;
        while(!courses.empty()){
            std::make_heap(courses.begin(), courses.end(), comp());
            curr = courses.front();
            if(curr->in_degree != 0){
                res.clear();
                for(node * tmp : courses){
                    delete(tmp);
                }
                return res;
            }
            
            std::pop_heap(courses.begin(), courses.end(), comp());
            courses.pop_back();
            res.push_back(curr->id);
            for(node * tmp : curr->requisite){
                tmp->in_degree -= 1;
            }
            delete(curr);            
        }
        return res;
    }
};
