// 容易观察到几个基础的规律，移除x之后,L和R的相对位置应该是不变的
// 其次，替换规律下，L只能往左移动，R只能往右移动
// 然后L和R不能互相跨过，遍历统计就行了
impl Solution {
  pub fn can_transform(start: String, end: String) -> bool {
      let n = start.len();
      let (mut i,mut j) = (0,0);
      let (start,end) = (start.as_bytes(),end.as_bytes());
      loop {
          while i < n && start[i] == b'X' {
              i += 1;
          }
          while j < n && end[j] == b'X' {
              j += 1;
          }
          if i == n || j == n {
              break;
          }
          if start[i] != end[j] {
              return false;
          } 
          if start[i] == b'L' && i < j {
              return false;
          }
          if start[i] == b'R' && i > j {
              return false;
          }
          i += 1;
          j += 1;
      }
      i == n && j == n
  }
}