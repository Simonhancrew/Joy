impl Solution {
  pub fn min_operations_max_profit(customers: Vec<i32>, boarding_cost: i32, running_cost: i32) -> i32 {
    let (mut res, mut mx, mut profit, mut tot) = (0, 0, 0, 0);
    let (mut i, n) = (0, customers.len());
    while i < n || tot > 0 {
      if i < n {
        tot += customers[i];
      }
      if tot >= 4 {
        profit += boarding_cost * 4 - running_cost;
        tot -= 4;
      } else {
        profit += boarding_cost * tot - running_cost;
        tot = 0;
      }

      if mx < profit {
        mx = profit;
        res = i;
      }
      i += 1;
    }
    if mx <= 0 {
      return -1;
    }
    res as i32 + 1
  }
}
