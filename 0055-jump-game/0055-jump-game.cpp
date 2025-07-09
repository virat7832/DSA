class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // agar hm waha tk pahuche hi nhi phle
            if(i>maxIndex) return false;
            maxIndex=max(maxIndex,i+nums[i]);

        }
        return true;
    }
};