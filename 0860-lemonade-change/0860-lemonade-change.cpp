class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5) five=five+1;
            else if(bills[i]==10){
                if(five) {
                    five--;
                    ten=ten+1;
                }
                else { return false;
                }
            }
            else{
                if(ten && five ) {
                    ten=ten-1;
                    five=five-1;
                }
                else if(five>=3) five-=3;
                else{
                   return false; 
                }
            }
        }
        return true;


    }
};