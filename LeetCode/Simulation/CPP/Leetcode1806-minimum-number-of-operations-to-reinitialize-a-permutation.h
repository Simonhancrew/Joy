class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for (int i = 0;i < n;i++) perm[i] = i;
        int res = 0;
        auto arr = perm;
        auto trans = [&arr, n]()  {
            auto base = arr;
            for (int i = 0;i < n;i++) {
                if (i & 1) arr[i] = base[n / 2 + (i - 1) / 2];
                else arr[i] = base[i / 2];
            }
        };
        while (true) {
            res++;
            trans();
            if (perm == arr) break;
        }
        return res;
    }
};
