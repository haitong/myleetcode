/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/
class Solution {
public:
    void labelIsland(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        queue<pair<int, int> > frontier;
        frontier.push(make_pair(row, col));
        visited[row][col] = true;
        while(!frontier.empty()){
            pair<int, int> curr = frontier.front();
            frontier.pop();
            row = curr.first;
            col = curr.second;
            
            
            if(row-1>=0 && !visited[row-1][col] && grid[row-1][col] == '1'){
                frontier.push(make_pair(row-1, col));
                visited[row-1][col] = true;
            }
            if(row+1<grid.size() && !visited[row+1][col] && grid[row+1][col] == '1'){
                frontier.push(make_pair(row+1, col));
                visited[row+1][col] = true;
            }
            if(col-1>=0 && !visited[row][col-1] && grid[row][col-1] == '1'){
                frontier.push(make_pair(row, col-1));
                visited[row][col-1] = true;
            }
            if(col+1<grid[0].size() && !visited[row][col+1] && grid[row][col+1] == '1'){
                frontier.push(make_pair(row, col+1));
                visited[row][col+1] = true;
            }            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int res = 0;
        
        vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    res++;
                    labelIsland(grid, visited, i, j);
                }
            }
        }
        return res;
    }
};
