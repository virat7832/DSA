class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end() && abs (mp[nums[i]]-i)<=k){
                return true;
            }
            else{
                mp[nums[i]]=i; // aage wale index se update
            }
        }
        return false;
    }
};