class Solution {
public:
    int numRabbits(vector<int>& answers) {
    unordered_map<int,int>hash;
    for(int i=0;i<answers.size();i++){
        hash[answers[i]]++;
    }    
    int rabbits=0;
    for(auto i:hash){
        double size=i.first+1;
        double count=i.second;
        int group=ceil(count/size);
        rabbits+=(group*size);
    }
    return rabbits;
    }
};