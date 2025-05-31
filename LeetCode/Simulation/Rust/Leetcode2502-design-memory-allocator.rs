use std::collections::{BTreeMap, HashMap};

type PII = (i32, i32);

struct Allocator {
  rec: HashMap<i32, Vec<PII>>,
  mp: BTreeMap<i32, i32>,
  n: i32,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Allocator {
  fn new(n: i32) -> Self {
    let mut mp = BTreeMap::new();
    mp.insert(n, n);
    Self {
      rec: HashMap::new(),
      mp: mp,
      n: n,
    }
  }

  fn allocate(&mut self, size: i32, m_id: i32) -> i32 {
    let mut rp = 0;
    for (&k, &v) in &self.mp {
      if k - rp >= size {
        self.mp.insert(rp, rp + size);
        self.rec.entry(m_id).or_default().push((rp, rp + size));
        return rp;
      }
      rp = v;
    }
    -1
  }

  fn free_memory(&mut self, m_id: i32) -> i32 {
    let mut ans = 0;
    if let Some(ranges) = self.rec.remove(&m_id) {
      for (k, v) in ranges {
        self.mp.remove(&k);
        ans += v - k;
      }
    }
    ans
  }
}
