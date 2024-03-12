const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int length = arr.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> st;
        for (int i = 0; i < length; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = length - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) 
                right[i] = st.top();
            st.push(i);
        }
        long long sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += static_cast<long long>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            sum %= MOD;
        }
        return sum;
    }
};
