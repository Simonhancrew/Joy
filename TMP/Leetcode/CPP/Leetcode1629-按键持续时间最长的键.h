class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int time = releaseTimes[0];
        for(int i = 1;i < releaseTimes.size();i++){
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if(t > time || (t == time && ans < keysPressed[i])) time = t,ans = keysPressed[i];
        }
        return ans;
    }
};