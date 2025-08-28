class Solution {
public:
    bool isCircularSentence(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]==' ' && s[i-1]!=s[i+1]) return false;
            i++;
        }
        if(s[0]!=s[s.size()-1]) return false;
        return true;
    }
};