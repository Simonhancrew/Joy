class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        ans, key, n = 0, 0, len(items)
        if ruleKey == "color": key = 1
        elif ruleKey == "name": key = 2
        for i in range(n):
            if items[i][key] == ruleValue: ans += 1
        return ans