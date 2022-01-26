from collections import Counter
from itertools import permutations

'''
非常pythonic的code
统计单词的频率，如果一个单词出现了freq次，那么一个串中最多有freq//k个这种单词
因此我们只需要统计s中各个字母出现的频率，进行倒序排列便于后续能够直接筛选出首字母最大的子串，然后频率满足要求的字母组合起来成为新的串hot
接着我们求出hot全部子串的全排列，然后依次判断是否属于s，第一个满足要求的即为所求
最精彩的部分就是那个if all里面的判断，in的contains的判断是会消耗迭代器的。
所以这个排列是否是属于s时的子序列，利用iter()函数生成迭代器是个非常巧妙的选择
'''

class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        num = Counter(s)
        hot = ''.join(ele * (num[ele]//k) for ele in sorted(num,reverse=True))
        for i in range(len(hot),0,-1):
            for item in permutations(hot,i):
                word = ''.join(item)
                ss = iter(s)
                if all(c in ss for c in word * k):
                    return word
        return ''