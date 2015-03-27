class Solution:
    # @param dungeon, a list of lists of integers
    # @return a integer
    def calculateMinimumHP(self, dungeon):
        if len(dungeon) == 0:
            return 0
        
        row = len(dungeon) - 1
        col = len(dungeon[0]) - 1
        
        dungeon[row][col] = max(1,1-dungeon[row][col])
        
        for i in reversed(range(row)):
            dungeon[i][col] = max(1,dungeon[i+1][col] - dungeon[i][col])
        
        for j in reversed(range(col)):
            dungeon[row][j] = max(1,dungeon[row][j+1] - dungeon[row][j])
            
        for i in reversed(range(row)):
            for j in reversed(range(col)):
                dungeon[i][j] = max(1,min(dungeon[i+1][j],dungeon[i][j+1])-dungeon[i][j])
                
        return dungeon[0][0]
