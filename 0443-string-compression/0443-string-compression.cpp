class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        
        for(int i=0;i<n;){
        char curr_char=chars[i];
        int count=0;
        // find count of duplicates or characters
        while(i<n && chars[i]==curr_char){
            count++;
            i++;
        }
         // assign work to index;
chars[index]=curr_char;
index++;
if(count>1){
    string count_str=to_string(count);
    for(char &ch:count_str){
        chars[index]=ch; // count ko assign kr rhe
        index++;
    }
}
        }
        return index;
    }
};