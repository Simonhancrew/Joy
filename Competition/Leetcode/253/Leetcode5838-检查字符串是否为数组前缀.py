from typing import List
class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        n = len(words)
        for i in range(n):
            cur = words[:i + 1]
            ss = ''.join(cur)
            # print(ss)
            if s == ss:
                return True
        return False

# 看了0x3f的题解，返现了一个更好的解法

# class Solution {
# public:
#     bool isPrefixString(string s, vector<string>& words) {
#         int sum = 0;
#         string cur;
#         for(auto& ss:words){
#             sum += ss.size();
#             cur += ss;
#             if(sum > s.size()) return false;
#             else if(sum == s.size()){
#                 return cur == s;
#             }
#         }
#         return false;
#     }
# };