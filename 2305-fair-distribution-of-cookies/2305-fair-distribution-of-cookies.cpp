class Solution {
public:
int result = INT_MAX;
    int n;

        void solve(int idx, vector<int>& cookies, vector<int>& children, int k) {
                if (idx >= n) {
                            int unfairness = *max_element(children.begin(), children.end());
                                        result = min(result, unfairness);
                                                    return;
                                                            }

                                                                    for (int i = 0; i < k; ++i) {
                                                                                children[i] += cookies[idx];
                                                                                            // Prune early if current max already exceeds result
                                                                                                        if (children[i] < result) {
                                                                                                                        solve(idx + 1, cookies, children, k);
                                                                                                                                    }
                                                                                                                                                children[i] -= cookies[idx];

                                                                                                                                                            // Optimization: if a child has 0, don't give the same cookie to other zero children again
                                                                                                                                                                        if (children[i] == 0) break;
                                                                                                                                                                                }
                                                                                                                                                                                    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k, 0);
        solve(0, cookies, children, k);
         return result;
    }
};