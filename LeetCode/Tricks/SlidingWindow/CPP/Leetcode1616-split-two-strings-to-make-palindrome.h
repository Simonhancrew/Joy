// 考虑处理a的前缀和b的后缀， 另一种情况只需要交换函数里
// 入参的位置就可以了
// 考虑处理a, b的时候，有限考虑a-b的match对
// 如果不能match， 单独处理a的match对， 并且后续必须用a的match对
class Solution {
public:
    int n;
    bool check(const string& l, const string& r) {
        bool f = false;
        for (int i = 0, j = n - 1;i < j;i++, j--) {
            if (f) {
                if (l[i] != l[j]) return false;
            } else {
                if (l[i] != r[j]) {
                    if (l[i] != l[j]) return false;
                    f = true;
                } 
            }
        }
        return true;
    }

    bool checkPalindromeFormation(string a, string b) {
        n = a.size();
        if (check(a, b) || check(b, a)) return true;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return check(a, b) || check(b, a);
    }
};
