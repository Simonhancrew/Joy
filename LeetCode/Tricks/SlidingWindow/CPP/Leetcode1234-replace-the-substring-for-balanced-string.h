class Solution {
public:
    int get(char c) {
        if (c == 'Q') return 0;
        if (c == 'W') return 1;
        if (c == 'E') return 2;
        return 3;
    }
    
    bool check(const vector<int>& tot, const vector<int>& sum, int target) {
        for (int i = 0;i < 4;i++) {
            // 保证窗口外的每个字符都<= n / 4
            if (tot[i] - sum[i] > target) {
                return false;
            }
        }
        return true;
    }


    int balancedString(string s) {
        int n = s.size();
        vector<int> tot(4);
        for (const auto& c : s) {
            tot[get(c)]++;
        }
        if (tot[0] == n / 4 && tot[1] == n / 4 && tot[2] == n / 4 && tot[3] == n / 4) {
            return 0;
        }
        int res = n;
        vector<int> sum(4);
        for (int i = 0, j = 0;i < n;i++) {
            sum[get(s[i])]++;
            while (j <= i && check(tot, sum, n / 4)) {
                res = min(res, i - j + 1);
                sum[get(s[j])]--;
                j++;
            }
        }
        return res;
    }
};
