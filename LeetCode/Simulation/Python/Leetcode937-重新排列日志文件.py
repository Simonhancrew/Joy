# sort的key的理解，key是原值,返回的value是排序的基准值
# 最后原数组替换回key
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def cmp(s):
            a, b = s.split(' ', 1)
            return (0, b, a) if b[0].isalpha() else (1, )

        logs.sort(key=cmp)
        return logs
