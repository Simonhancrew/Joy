class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[5] = {0};
        for(const char& t : text)
        {
            if(t == 'a') cnt[0]++;
            else if(t == 'b') cnt[1]++;
            else if(t == 'l') cnt[2]++;
            else if(t == 'o') cnt[3]++;
            else if(t == 'n') cnt[4]++;
        }
        cnt[2] /= 2,cnt[3] /= 2;
        return *min_element(cnt,cnt + 5);
    }
};