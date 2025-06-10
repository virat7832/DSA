class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;

        }
        int maxOdd=0;
        int minEven=n+1;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(freq[i]%2==0){
                minEven=min(minEven,freq[i]);
            }
            else{
                maxOdd=max(maxOdd,freq[i]);
            }
        }
        return  maxOdd-minEven;
    }
};