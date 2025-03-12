class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posC = 0, negC = 0;
        for(int it: nums){
            if(it > 0) posC++;
            else if(it < 0) negC++;
        }
        return max(posC, negC);
    }
};