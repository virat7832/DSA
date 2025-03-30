class Solution {
public:
    vector<int> getNSR(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSR(n);
        for(int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            NSR[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSR;
    }

    vector<int> getNSL(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSL(n);
        for(int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            NSL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return NSL;
    }

    int findMaxArea(vector<int>& height) {
        int n = height.size();
        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;
            maxArea = max(maxArea, width * height[i]);
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {  
        return findMaxArea(heights);
    }
};
