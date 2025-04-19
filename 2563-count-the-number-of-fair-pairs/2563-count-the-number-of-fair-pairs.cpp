class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int n = nums.size(), first=0, end= 0,ele = -1;
        for(int i=0;i<n;i++)
        {
            ele = nums[i];
            // i+1 to n-1
            // nums[j] >= lower-nums[i]
            // nums[j] <= upper-nums[i];
            first = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]) - nums.begin();
            end = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]) - nums.begin();
            ans += 1ll*(end - first);
        }
        return ans;        
    }
};