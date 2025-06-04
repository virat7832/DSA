class Solution {
public:
    int t[201][1001];
    int n;
    int solve(int idx,vector<int>& nums,int target){
        if(target==0){
            return 1;
        } if(idx>=n || target<0){
            return 0;
        }
        if (t[idx][target]!=-1) return t[idx][target];
        int take_idx=solve(0,nums,target-nums[idx]);
        int reject_idx=solve(idx+1,nums,target);
        return t[idx][target]=take_idx+reject_idx;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,target);
    }
};