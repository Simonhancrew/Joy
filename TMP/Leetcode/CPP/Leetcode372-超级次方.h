class Solution {
public:
    const int p = 1337;
    int qmi(int a,int k){
        a %= p;
        int res = 1;
        while(k){
            if(k & 1) res = res * a % p;
            k >>= 1;
            a = a * a % p;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int k = b.back();
        b.pop_back();
        return qmi(superPow(a,b),10) * qmi(a,k) % p;
    }
};