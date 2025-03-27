class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int &a:asteroids){
            // when collision happens
            while(!st.empty() && a<0 && st.top()>0){
                // collision hua kon sa destroy hoga
                int sum=a+st.top();
                if(sum<0){ // left destroy hoga
                    st.pop();
                } else if(sum>0){ // a jo element hoga wo destroy hoga
                    a=0;
                }else{
                    st.pop();
                    a=0;
                }
            }
           if(a!=0){
            st.push(a);
           } 
        }
        int s=st.size();
        vector<int>result(s);
        // stack se niakl kr array result me return kr rh reverse order me
        int i=s-1;
        while(!st.empty()){
result[i]=st.top();
st.pop();
i--;
        }
        return result;
    }
};