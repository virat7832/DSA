class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = fruits.size();
        int m = baskets.size();

        vector<bool> used(m, false);

        for (int i = 0; i < n; i++) {
            bool taken = false;
            for (int j = 0; j < m; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true; 
                    taken = true;
                    break; 
                }
            }
            if (!taken) {
                count++; 
            }
        }

        return count;
    }
};


