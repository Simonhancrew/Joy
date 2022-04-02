/*
    分情况讨论，小于6时，max(6 - n,3 - k)
    [6,20],不用删除，只用修改就可以了针对连续大于3的段做一个r / 3的删除
    大于20时，尽可能将删除用到连续的段中
    针对连续长度r mod 3余 0 1 2的三种情况，都转化成余2之后整体做一个内部删除
*/
class Solution {
public:
    int strongPasswordChecker(string password) {
        int a = 0,b = 0,c = 0,n = password.size();
        for(auto s : password) {
            if(s >= '0' && s <= '9') a = 1;
            else if(s >= 'a' && s <= 'z') b = 1;
            else if(s >= 'A' && s <= 'Z') c = 1;
        }
        int k = a + b + c;
        if(n < 6) return max(6 - n,3 - k);
        else{
            // p需要修改的连续段，del是需要删除的大小，res是一定会被删除的片段
            // del的意义是尽可能在连续段中删除，让后续修改的值最小
            int p = 0,del = n - 20,res = del;
            int d[3] = {0};
            for(int i = 0;i < n;i++) {
                int j = i;
                while(j < n && password[i] == password[j]) j++;
                int r = j - i;

                p += r / 3;
                if(r >= 3) d[r % 3]++;

                i = j - 1;
            }
            cout << p << endl;
            if(n <= 20) return max(3 - k,p);
            if(del && d[0]) {
                int t = min(d[0],del);
                del -= t;
                p -= t;
            }
            if(del && d[1]) {
                int t = min(d[1] * 2,del);
                del -= t;
                p -= t / 2;
            }
            // 剩下的全是mod 3 余2的
            if(del && p) {
                int t = min(p * 3,del);
                p -= t / 3;
            }
            cout << n << ' ' << p << endl;
            return res + max(p,3 - k);
        }
    }
};