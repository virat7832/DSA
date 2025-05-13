class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7 ; 
        vector<long long> freq(26, 0);
        for ( char c:s){
            freq[c-'a']++;
        }
        while(t){
            rotate(freq.rbegin(), freq.rbegin() + 1, freq.rend());
            freq[1]= (freq[1] + freq[0]) % MOD;
            t--;
        }
        int result = 0 ; 
        for ( int i = 0 ; i < 26 ; i++){
            result = (result + freq[i]) % MOD ; 
        }
        return result ; 

        
    
    }
};