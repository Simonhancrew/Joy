/*
    可能的合法解就只有三种,
    1, 1, 1, 1, 1
    k, k, k, k, 1
    k, k, k, k, k + 1
    cnt记录每个值出现的次数，freq记录每个出现次数出现了多少次
    记录最大的出现次数，判断整体的长度是否满足就行了
*/
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> cnt,freq;
        int n = nums.size(),max_f = 0;
        int ans = 0;
        for(int i = 0;i < n;i++) {
            int num = nums[i];
            if(cnt[num] > 0) {
                freq[cnt[num]]--;
            }
            cnt[num]++;
            freq[cnt[num]]++;
            max_f = max(max_f,cnt[num]);
            if(max_f == 1 || max_f * freq[max_f] + 1 == i + 1 || (max_f - 1) * (freq[max_f - 1]+ 1) + 1 == i + 1) {
                ans = i + 1;
            }
        }
        return ans;
    }
};