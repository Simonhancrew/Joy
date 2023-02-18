// 这种行列都是递增的矩阵， 一般直接看右上角就可以了
// 比较套路， 一次可以删掉一行或者是一列
impl Solution {
  pub fn find_solution(func: &CustomFunction, z: i32) -> Vec<Vec<i32>> {
      let (mut x, mut y) = (1, 1000);
      let mut res = vec![];
      while x <= 1000 && y >= 1 {
          if func.f(x, y) > z {
              y -= 1;
          } else if func.f(x, y) < z {
              x += 1;
          } else {
              res.push(vec![x, y]);
              x += 1;
              y -= 1;
          }
      }
      res
  }
}