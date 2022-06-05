class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.x = x_center
        self.y = y_center
        self.r = radius

    def randPoint(self) -> List[float]:
        a,b = random.random() * 2 - 1,random.random() * 2 - 1
        if a * a + b * b > 1: return  self.randPoint()
        return [self.x + a * self.r,self.y + b * self.r]
