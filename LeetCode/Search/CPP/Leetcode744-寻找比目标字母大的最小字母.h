class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(),letters.end());
        auto t = upper_bound(letters.begin(),letters.end(),target);
        if(t == letters.end()) return letters.front();
        return *t;
    }
};