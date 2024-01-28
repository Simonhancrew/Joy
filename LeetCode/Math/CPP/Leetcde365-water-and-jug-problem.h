// 等价 a * jug1Capacity + b * jug2Capacity = c, c要是targetCapacity的倍数
class Solution {
public:
  int gcd(int a, int b) {
      return b ? gcd(b, a % b) : a;
  }
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity + jug2Capacity < targetCapacity) {
      return false;
    }
    if (jug1Capacity == 0 || jug2Capacity == 0) {
      return targetCapacity == 0 ||
             targetCapacity == jug1Capacity + jug2Capacity;
    }
    return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
  }
};