class Solution {
public:
    int maximumSwap(int num) {
        vector<int> rec;
        while(num) {
            rec.push_back(num % 10);
            num /= 10;
        }
        int n = rec.size();
        for(int i = n - 1;i >= 0;i--) {
            int rmx = rec[i],idx = i;
            for(int j = i - 1;j >= 0;j--) {
                if(rec[j] >= rmx) {
                    rmx = rec[j];
                    idx = j;
                }
            }
            if(rmx > rec[i]) {
                swap(rec[i],rec[idx]);
                break;
            } 
        }
        int ans = 0;
        for(int i = n - 1;i >= 0;i--) {
            ans = ans * 10 + rec[i];
        }
        return ans;
    }
};
