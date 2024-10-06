/*
  1. 我们需要分别计算总的汽油量 total_gas 和总的消耗量 total_cost。如果
  total_gas < total_cost，直接返回
  -1，因为无论从哪个加油站出发，都无法完成一圈。
  2. 遍历所有加油站，逐一判断能否从该加油站出发绕行一圈。使用一个变量
  current_tank 来记录当前的油箱情况。如果在遍历过程中 current_tank
  变成负数，意味着从当前出发点到某个加油站时油箱已经不够用了，这说明从当前出发点无法完成绕圈。
  3. 因此，当 current_tank 小于 0 时，应该更新出发点到下一个加油站。如果从 start
  到 i 期间，油箱已经不足了，那么从 start 出发肯定不行。而且，假设某个加油站
  j（start < j ≤ i）能够作为起点绕一圈成功，那么从 start 出发到达 j
  时油量是正的，说明之前累积了足够的油量。因此如果 j 能作为起点，那么 start
  也应该能成功，然而我们已经发现 start 失败了，因此这些加油站 j
  都不可能是有效起点。
*/
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size(), tot = 0, mn = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      auto cur = gas[i] - cost[i];
      tot += cur;
      if (tot < mn) {
        mn = tot;
        ans = i + 1;
      }
    }
    return tot < 0 ? -1 : ans;
  }
};
