class Solution {
public:
vector<int> getNSL(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> getNSR(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> getNGL(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> getNGR(vector<int> &arr, int n) {
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }
     long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];
            long long right = NSR[i] - i;
            long long totalWays = left * right;
            long long totalSum = (1LL * arr[i] * totalWays);
            sum = (sum + totalSum) ;
        }
        return sum;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGL = getNGL(arr, n);
        vector<int> NGR = getNGR(arr, n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NGL[i];
            long long right = NGR[i] - i;
            long long totalWays = left * right;
            long long totalSum = (1LL * arr[i] * totalWays);
            sum = (sum + totalSum);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& arr) {
        long long sumMax = sumSubarrayMaxs(arr);
        long long sumMin = sumSubarrayMins(arr);
         return ((sumMax - sumMin));
    }
};