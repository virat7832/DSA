class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int curr=nums2[i];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            mp[curr]=!st.empty() ? st.top():-1;
            st.push(curr);
        }
        vector<int>result;
        for(int i=0;i<m;i++){
            result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};