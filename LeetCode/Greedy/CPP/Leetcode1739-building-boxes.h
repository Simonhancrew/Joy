class Solution {
public:
    int minimumBoxes(int n) {
        int sum = 0, k = 1;
        while(sum + k * (k + 1) / 2 <= n) {
            sum += k * (k + 1) / 2;
            k++;
        }

        int res = k * (k - 1) / 2;
        k = 1;
        while (sum < n) {
            sum += k;
            res++, k++;
        }
        return res;
    }
};