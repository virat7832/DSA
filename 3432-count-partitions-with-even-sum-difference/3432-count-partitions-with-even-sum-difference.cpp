class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int leftSum=0;
            for(int j=0;j<=i;j++){
                leftSum+=nums[j];

            }
            int rightSum=0;
            for(int j=i+1;j<=n-1;j++){
                rightSum+=nums[j];
            }
            if((leftSum-rightSum)%2==0){
                ans++;
            }
        }
        return ans;

    }
};