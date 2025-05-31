use std::collections::HashMap;
struct SnapshotArray {
  mp: HashMap<i32, Vec<(i32, i32)>>,
  snap_id: i32,
}

impl SnapshotArray {
  fn new(length: i32) -> Self {
    Self {
      mp: HashMap::new(),
      snap_id: 0,
    }
  }

  fn set(&mut self, index: i32, val: i32) {
    self.mp.entry(index).or_default().push((self.snap_id, val));
  }

  fn snap(&mut self) -> i32 {
    self.snap_id += 1;
    self.snap_id - 1
  }

  fn get(&self, index: i32, snap_id: i32) -> i32 {
    if let Some(snaps) = self.mp.get(&index) {
      let (mut l, mut r) = (-1, snaps.len() as i32);
      while l + 1 < r {
        let mid = l + r >> 1;
        if snaps[mid as usize].0 <= snap_id {
          l = mid;
        } else {
          r = mid;
        }
      }
      if l < 0 || l >= snaps.len() as i32 {
        return 0;
      }
      return snaps[l as usize].1;
    }
    0
  }
}
