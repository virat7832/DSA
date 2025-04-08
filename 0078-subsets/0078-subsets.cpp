class Solution {
public:
vector<vector<int>>ans;
void addSubsets(vector<int>&nums,int i,vector<int>temp){
    if(i<nums.size()){
 temp.push_back(nums[i]);
addSubsets(nums,i+1,temp);
temp.pop_back();
addSubsets(nums,i+1,temp);
    } else{
        return ans.push_back(temp);
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        addSubsets(nums,0,{});
        return ans;
    }
};