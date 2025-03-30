class Solution {
public:
    string removeKdigits(string num, int k) {
        string result=""; // it will acts as a stack
        int n=num.length();
        for(int i=0;i<n;i++){
            while(result.length()>0 && result.back()>num[i] && k>0){
                result.pop_back();
                k--;
            }
            if(result.length()>0 || num[i]!='0'){
             result.push_back(num[i]); // to avoid the case when we have precceding zeros

            }
            
        }
        // already sorted i.e num=12345
        while(k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
         return result.empty() ? "0" : result;

    }
};