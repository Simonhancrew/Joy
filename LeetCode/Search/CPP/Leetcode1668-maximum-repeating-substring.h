#include <string>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int l = 0, r = sequence.size() / word.size();
        while (l < r) {
            int mid = l + r + 1 >> 1;
            string s;
            for(int i = 0;i < mid;i++) s += word;
            if(sequence.find(s) != string::npos) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
