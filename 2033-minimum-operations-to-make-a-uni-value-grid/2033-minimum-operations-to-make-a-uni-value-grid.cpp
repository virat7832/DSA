class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem=grid[0][0]%x;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>r;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]%x!=rem){
                    return -1;
                } else{
                    r.push_back(grid[i][j]);
                }
            }
        }
        sort(r.begin(),r.end());
        int s=m*n;
        int ind=s/2;
        int eq=r[ind];
        int c=0;
        for (int i=0;i<s;i++){
            if (eq!=r[i]){
                c+=abs(r[i]-eq)/x;
            }
        }
        return c;

    }
};