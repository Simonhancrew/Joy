class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        keysPressed = list(keysPressed)
        ans,time = keysPressed[0],releaseTimes[0]
        for i in range(1,len(releaseTimes)):
            t = releaseTimes[i] - releaseTimes[i - 1]
            if t > time or (t == time and ans < keysPressed[i]): ans,time = keysPressed[i],t
        return ans