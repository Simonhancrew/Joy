class Solution {
public:
    Solution() {
        get_prime(33);
    }

    void get_prime(int n) {
        st.resize(n + 1,false);
        st[1] = true;
        for(int i = 2;i <= n;i++) {
            if(!st[i]) primes.push_back(i);
            for(int j = 0;primes[j] <= n / i;j++) {
                st[primes[j] * i] = true;
                if(i % primes[j] == 0) break;
            }
        }
    }
    
    bool check(int n) {
        int cnt = 0;
        while(n) n -= (n & -n),cnt++;
        return !st[cnt];
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for(int i = left;i <= right;i++) {
            if(check(i)) ans++; 
        }
        return ans;
    }
    
private:
    vector<bool> st;
    vector<int> primes;
};