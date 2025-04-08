class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int arr[101];
        int last = -1;
        for(int i=0; i<nums.size(); i++) {
            int a = nums[i];
            if(arr[a] == 0) arr[a] = i+1;
            else {
                last = max(last, arr[a]);
                arr[a] = i+1;
            }
        }
        return (last > 0) ? ceil(last/3.0) : 0;
    }
};