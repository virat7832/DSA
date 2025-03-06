class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int rep, missing;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int need = (n * i) + j + 1;
                
                while(grid[i][j] != need){
                    int posx = (grid[i][j] - 1) / n;
                    int posy = (grid[i][j] - 1) % n;
                    
                    if(grid[i][j] == grid[posx][posy]){
                        rep = grid[i][j];
                        missing = need;
                        break;
                    }
                    swap(grid[i][j], grid[posx][posy]);
                }
            }
        }
        return {rep, missing};
    }
};