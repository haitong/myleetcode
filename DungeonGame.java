public class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        if(dungeon.length == 0) return 0;
        
        int row = dungeon.length - 1;
        int col = dungeon[0].length - 1;
        
        dungeon[row][col] = Math.max(1,1-dungeon[row][col]);
        
        for(int i = row-1; i >= 0; i--){
            dungeon[i][col] = Math.max(1, dungeon[i+1][col]-dungeon[i][col]);
        }
        
        for(int j = col-1; j >= 0; j--){
            dungeon[row][j] = Math.max(1,dungeon[row][j+1]-dungeon[row][j]);
        }
        
        for(int i = row - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                dungeon[i][j]=Math.max(1,Math.min(dungeon[i+1][j],dungeon[i][j+1])-dungeon[i][j]);
            }
        }
        return dungeon[0][0];
    }
}
