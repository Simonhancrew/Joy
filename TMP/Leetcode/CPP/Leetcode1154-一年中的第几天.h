class Solution {
public:
    int nums[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int f[13] = {0};
    Solution(){
        for(int i = 1;i < 13;i++) {
            f[i] = f[i - 1] + nums[i - 1];
        }
    }
    int dayOfYear(string date) {
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        int ans = 0;
        bool is_leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
        ans = m > 2 && is_leap ? f[m - 1] + 1 : f[m - 1];
        return ans + d;
    }
};