class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // Use backtracking to generate all subsets and calculate their XOR sums
        int result = 0;
        generateSubSets(nums,0,0,result);
        return result;
    }
public:
    void generateSubSets(vector<int>& nums , int index , int currentXOR , int& totalSum) {
        
        if (index == nums.size()) {
            totalSum += currentXOR;
            return; 
        }

        generateSubSets(nums , index + 1 , currentXOR ^ nums[index] , totalSum);

        generateSubSets(nums , index + 1 , currentXOR , totalSum);
    }
};