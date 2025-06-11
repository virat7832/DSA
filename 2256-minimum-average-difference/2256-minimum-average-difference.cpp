class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        int minDiff=INT_MAX;
        int resultIndex=0;
        for(int i=0;i<n;i++){
            long long ls=0;
            long long rs=0;
            for(int j=0;j<=i;j++){
                ls+=nums[j];

            }
            int leftAvg=ls/(i+1);
            if(i!=n-1){
                for(int j=i+1;j<n;j++){
                    rs+=nums[j];
                }
                int rightAvg=rs/(n-i-1);
                int diff=abs(leftAvg-rightAvg);
                if(diff< minDiff){
                    minDiff=diff;
                    resultIndex=i;
                }  }else{
                    int diff=abs(leftAvg);
                    if(diff<minDiff){
                        minDiff=diff;
                        resultIndex=i;
                    }
                }
            }
            return resultIndex;

        
    }
};