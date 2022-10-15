class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans,j = [], 0
        for i in range(1,n + 1):
            if target[j] == i:
                j += 1
                ans.append("Push")
            else:
                ans.append("Push")
                ans.append("Pop")
            if i == target[-1]:
                break
        return ans