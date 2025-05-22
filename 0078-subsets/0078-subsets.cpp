class Solution {
    void func(int ind,vector<int>&nums,int n,vector<int>ds,vector<vector<int>>&ans){
if(ind==n){
    ans.push_back(ds);
    return;
}
ds.push_back(nums[ind]);
func(ind+1,nums,n,ds,ans);
ds.pop_back();
func(ind + 1, nums, n, ds, ans);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        func(0,nums,n,ds,ans);
        return ans;
    }
};