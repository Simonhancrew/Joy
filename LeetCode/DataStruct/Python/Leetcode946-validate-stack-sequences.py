class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        ans,n,j = [],len(popped),0
        for i in range(n):
            ans.append(pushed[i])
            while ans and ans[-1] == popped[j]:
                j += 1
                ans.pop()
        return not ans
