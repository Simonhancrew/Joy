var numMatchingSubseq = function (s, words) {
  let [n, mp] = [s.length, new Array(26).fill(0).map(() => new Array())];
  for (let i = 0; i < n; i++) {
    mp[s[i].charCodeAt() - 'a'.charCodeAt()].push(i);
  }
  let ans = words.length;
  for (const x of words) {
    if (x.length > s.length) {
      ans--;
      continue;
    }
    let idx = -1;
    for (const c of x) {
      let arr = mp[c.charCodeAt() - 'a'.charCodeAt()];
      if (arr.length == 0 || arr[arr.length - 1] <= idx) {
        ans--;
        break;
      }
      let [l, r] = [0, arr.length - 1];
      while (l < r) {
        let mid = l + r >> 1;
        if (arr[mid] <= idx) l = mid + 1;
        else r = mid;
      }
      idx = arr[l];
    }
  }
  return ans;
}