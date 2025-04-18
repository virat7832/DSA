class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long max_i=nums[0];
        long long max_diff=nums[0]-nums[1];
        long long ans=0;
        for(int k=2;k<n;k++){
            ans=max(ans,max_diff*nums[k]);
            max_i=max(max_i,(long long)nums[k-1]);
            max_diff=max(max_diff,max_i-nums[k]);
        }
        return ans;
    }
};