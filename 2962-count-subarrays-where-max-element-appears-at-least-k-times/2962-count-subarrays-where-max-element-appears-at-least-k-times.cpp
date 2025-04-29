class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i = 0;  
        int j = 0;  
        int maxi = *max_element(nums.begin(), nums.end());  
        long long count = 0;  

        while (j < nums.size()) {
           
            if (nums[j] == maxi) {
                k--;
            }
            j++;  

            if (k == 0) {
                
                while (nums[i] != maxi) {
                    i++;
                }
               
                count += (i + 1);
            }

            if (k < 0) {
                
                while (k != 0) {
                    i++;
                    if (nums[i] == maxi) {
                        k++; 
                    }
                }
            
                count += (i + 1);
            }
        }
        
        return count;  
    }
};