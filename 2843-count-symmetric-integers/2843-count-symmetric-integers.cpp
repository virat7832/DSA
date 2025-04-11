class Solution {
public:
    int dp[5][2][45][45][5];
    int rec(int pos,string s,bool tight,int sum1,int sum2,int leadingzero){
        if(pos>=s.length()){
            return (sum1==sum2) && (pos - leadingzero)%2==0 && leadingzero!=pos; 
        }
        if(dp[pos][tight][sum1][sum2][leadingzero]!=-1)return dp[pos][tight][sum1][sum2][leadingzero];
        int limit = tight?9:(s[pos]-'0');
        int ans = 0;
        for(int i=0;i<=limit;i++){
            bool newtight = tight || (i<limit);
            if(i==0 && leadingzero==pos){
                ans = ans + rec(pos+1,s,newtight,sum1,sum2,leadingzero+1);
            }
            else{
                int lenLeft = s.length() - leadingzero;
                if(pos - leadingzero < lenLeft/2){
                    ans = ans + rec(pos+1,s,newtight,sum1 + i,sum2,leadingzero);
                }
                else{
                    ans = ans + rec(pos+1,s,newtight,sum1,sum2 + i,leadingzero);
                }
            }
        }
        return dp[pos][tight][sum1][sum2][leadingzero] = ans;
    }
    int countSymmetricIntegers(int low, int high) {
        memset(dp,-1,sizeof(dp));
        int hi = rec(0,to_string(high),false,0,0,0);
        memset(dp,-1,sizeof(dp));
        int lo = rec(0,to_string(low - 1),false,0,0,0);
        return hi - lo;
    }
};