class Solution {
public:
    using LL = long long;
    const int P = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for(int i = 0;i < n;i++) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
            if(stk.empty()) l[i] = -1;
            else l[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int> ();
        for(int i = n - 1;i >= 0;i--) {
            while(stk.size() && arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) r[i] = n;
            else r[i] = stk.top();
            stk.push(i);
        }
        LL res = 0;
        for(int i = 0;i < n;i++) {
            res = (res + (LL)arr[i] * (i - l[i]) * (r[i] - i)) % P;
        }
        return res;
    }
};
