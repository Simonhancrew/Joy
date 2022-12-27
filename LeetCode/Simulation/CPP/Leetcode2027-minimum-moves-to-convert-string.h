class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0, n = s.size();
        for (int i = 0;i < n;i++) {
            if (s[i] == 'O') continue;
            i += 2;
            ans++;
        } 
        return ans;
    }
};
