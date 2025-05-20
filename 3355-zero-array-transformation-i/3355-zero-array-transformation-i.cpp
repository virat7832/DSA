class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> arr(nums.size()+1,0);
        for(auto q:queries){
            
            arr[q[0]]+=1;
            arr[q[1]+1]-=1;
        }
        vector<int> prefixSum;
        int count=0;
        for(auto val:arr){
            count+=val;
            prefixSum.push_back(count);
        }
        for(int i=0;i<nums.size();i++){
            if(prefixSum[i]<nums[i])
            return false;
        }
        return true;
    }

};