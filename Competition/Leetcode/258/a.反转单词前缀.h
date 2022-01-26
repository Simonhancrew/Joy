#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto pos = find(word.begin(),word.end(),ch) - word.begin();
        if(pos < word.size()){
            reverse(word.begin(),word.begin() + pos + 1);
        }
        return word;
    }
};


#if 0
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        if ch not in word:
            return word
        it = word.find(ch)
        word = list(word)
        s = word[:it + 1]
        s.reverse()
        t = word[it + 1:]
        return ''.join(s + t)
#endif