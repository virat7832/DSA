class Solution {
public:
	bool checkValid(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if(n == 1){
			return  true;
		}
		unordered_map<int, int> mp;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(mp.count(matrix[i][j])){
					return false;
				}
				else{
					mp[matrix[i][j]]++;
				}
			}
			mp.clear();
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(mp.count(matrix[j][i])){
					return false;
				}
				else{
					mp[matrix[j][i]]++;
				}
			}
			mp.clear();
		}
		return true;
	}
};