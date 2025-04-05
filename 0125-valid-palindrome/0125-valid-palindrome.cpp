class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return checkPalindrome(s, 0); 
    }

public:
    bool checkPalindrome(string& s, int i) {
        int n = s.size();
        if (i >= n / 2) return true;
        if (s[i] != s[n - i - 1]) return false;
        else {
            return checkPalindrome(s, i + 1);
        }
    }
};
