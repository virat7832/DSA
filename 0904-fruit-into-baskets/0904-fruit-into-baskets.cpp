class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;

        int l = 0, r = 0, res = 0;
        
        while(r < fruits.size())
        {

            mpp[fruits[r]]++;
            
            if(mpp.size() <= 2) res = max(res, r-l+1);
            
            else
            {
                mpp[fruits[l]]--;

                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);

                l++;
            }

            r++;
        }

        return res; 
    }
};