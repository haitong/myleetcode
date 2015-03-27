class Solution {
public:
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
    }
};
