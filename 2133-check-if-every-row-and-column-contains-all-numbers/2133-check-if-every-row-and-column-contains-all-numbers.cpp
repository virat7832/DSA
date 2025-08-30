class Solution {
public:
    bool checkValid(vector<vector<int>>& m) {
        vector<vector<int>>temp=m;
        int n=m.size();
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                temp[i][j]=m[j][i];

            }
        }
            for(int i=0;i<m.size();i++){
            sort(m[i].begin(), m[i].end());
            sort(temp[i].begin(), temp[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                  if(m[i][j]!=j+1 || temp[i][j]!=j+1){
                    return false;
                  }
            }
        }
    return true;
    }
};