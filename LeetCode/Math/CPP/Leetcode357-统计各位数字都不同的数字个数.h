class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    if (n == 1) return 10;
    int base = 9, mul = 9, res = 10;
    for (int i = 0; i < n - 1; i++) {
      base *= (mul - i);
      res += base;
    }
    return res;
  }
};

/*
class Solution {
public:
    int res = 0;
    void dfs(int u,int st,int n) {
        if(u == n) return;
        for(int i = 0;i <= 9;i++) {
            if(!((st >> i) & 1)) {
                if(u == 0 && i == 0) continue;
                st |= 1 << i;
                res++;
                dfs(u + 1,st,n);
                st -= 1 << i;
            }
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        dfs(0,0,n);
        return res + 1;
    }
};
*/