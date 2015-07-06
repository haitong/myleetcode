/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/
class node {
public:
    vector<node *> descendents;
    int degree;
    bool visited;
    
    node():degree(0), visited(false) {
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses < 2) return true;
        
        vector<bool> visited(numCourses, false);
//        vector<node *> vertices(numCourses, new node());
        vector<node *> vertices;
        for(int i = 0; i < numCourses; i ++){
            vertices.push_back(new node);
        }
        for(pair<int, int> tmp : prerequisites){
            vertices[tmp.first]->degree += 1;
            vertices[tmp.second]->descendents.push_back(vertices[tmp.first]);
        }
        
        queue<node *> source;
        int num = 0;
        for(node * tmp : vertices){
            if(tmp->degree == 0){
                source.push(tmp);
                num ++;
                tmp->visited = true;
            }
        }
        
        while(!source.empty()){
            node * curr = source.front();
            source.pop();
            
            for(node * tmp : curr->descendents){
                if(!tmp->visited){
                    tmp->degree --;
                    if(tmp->degree == 0){
                        source.push(tmp);
                        num ++;
                        if(num >= numCourses) return true;
                        tmp->visited = true;
                    }
                }
            }
        }
        
        if(num >= numCourses) return true;
        return false;
    }
};
