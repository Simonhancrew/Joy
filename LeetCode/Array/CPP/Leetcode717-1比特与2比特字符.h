class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(),tag = true;
        for(int i = 0;i < n - 1;i++) {
            if(bits[i] == 1) {
                i++;
                if(i == n - 1) tag = false;
            }
        }
        return tag;
    }
};