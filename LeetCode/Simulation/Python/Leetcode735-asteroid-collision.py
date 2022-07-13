class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ans = []
        for ast in asteroids:
            flag = True
            while flag and ans and ans[-1] > 0 and ast < 0:
                flag = -ast > ans[-1]
                if -ast >= ans[-1]: ans.pop()
            if flag: ans.append(ast)
        return ans