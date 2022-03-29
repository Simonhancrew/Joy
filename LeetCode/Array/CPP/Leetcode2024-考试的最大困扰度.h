class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int cnt0 = 0,cnt1 = 0,ans = 1;
        for(int i = 0,j = 0;j < n;j++){
            if(answerKey[j] == 'T') cnt1++;
            else cnt0++;
            
            while(i < j && min(cnt0,cnt1) > k) {
                if(answerKey[i] == 'T') cnt1--;
                else cnt0--;
                i++;
            } 

            ans = max(ans,j - i + 1);
        }
        return ans;
    }
};