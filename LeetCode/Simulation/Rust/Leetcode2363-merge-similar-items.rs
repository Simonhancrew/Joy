impl Solution {
  pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    use std::collections::BTreeMap;
    let mut mp = BTreeMap::new();
    for item in &items1 {
      let (val, wei) = (item[0], item[1]);
      mp.entry(val).and_modify(|v| *v += wei).or_insert(wei);
    }
    for item in &items2 {
      let (val, wei) = (item[0], item[1]);
      mp.entry(val).and_modify(|v| *v += wei).or_insert(wei);
    }
    let mut res = vec![];
    for (&k, &v) in &mp {
      res.push(vec![k, v]);
    }
    res
  }
}
