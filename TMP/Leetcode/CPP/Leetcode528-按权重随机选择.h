#include <vector>

using namespace std;

class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        s = w;
        for(int i = 1;i < s.size();i++) s[i] += s[i - 1];
    }
    
    int pickIndex() {
        int x = rand() % s.back() + 1;
        return lower_bound(s.begin(),s.end(),x) - s.begin();
    }
};