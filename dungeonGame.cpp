/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/
class Solution {
public:
/*
    void dfs(vector<vector<int> > &d, int & res,int x, int y, int & remain, int & curr_min, map<int,int> & visited){
        if(remain + d[x][y] < res) return;  // better result has been found, no need to continue search
        if(visited.find(x * d[0].size() + y)!= visited.end() 
            && visited.find(x * d[0].size() + y)->second >= remain + d[x][y]) return;
            
        visited[x * d[0].size() + y] = remain + d[x][y];
        
        if(remain + d[x][y] < curr_min) curr_min = remain + d[x][y];
        
        if(x == d.size() - 1 && y == d[0].size() - 1){
            if(curr_min > res) res = curr_min;
            return;
        }
        
        remain += d[x][y];
        if(x + 1 < d.size()) dfs(d,res,x+1,y,remain,curr_min, visited);
        if(y + 1 < d[0].size()) dfs(d,res,x,y+1,remain,curr_min, visited);
        remain -= d[x][y];
    }
*/    

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.empty() || dungeon[0].empty()) return 0;
        int row = dungeon.size()-1;
        int col = dungeon[0].size()-1;

        dungeon[row][col] = max(1,1-dungeon[row][col]);
        for(int i = row - 1; i >=0; i--){
            dungeon[i][col] = max(1,dungeon[i+1][col] - dungeon[i][col]);
        }
        for(int j = col - 1; j >= 0; j--){
            dungeon[row][j] = max(1,dungeon[row][j+1] - dungeon[row][j]);
        }
        
        for(int i = row-1; i >= 0; i--){
            for(int j = col -1; j >=0; j--){
                dungeon[i][j] = max(1, min(dungeon[i+1][j], dungeon[i][j+1]) - dungeon[i][j]);
            }
        }
        
        return dungeon[0][0];
//        int remain = 0, curr_min = INT_MAX;
//        map<int, int> visited;
//        dfs(dungeon, res,0,0,remain,curr_min, visited);
//        return res;
    }
};



