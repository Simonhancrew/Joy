var expressiveWords = function (s, words) {
  let rec = [];
  for (let i = 0; i < s.length; i++) {
    let j = i + 1;
    while (j < s.length && s[j] == s[i]) j++;
    rec.push([s[i], j - i]);
    i = j - 1;
  }
  let ans = 0;
  const check = (w) => {
    if (w.length > s.length) return false;
    let [n, k] = [w.length, 0];
    for (let i = 0; i < n; i++) {
      if (k == rec.length) return false;
      if (w[i] != rec[k][0]) return false;
      let j = i + 1;
      while (j < n && w[i] == w[j]) j++;
      let [difs, difw] = [rec[k][1], j - i];
      if (difs < difw) return false;
      if (difs < 3 && difw != difs) return false;
      k += 1;
      i = j - 1;
    }
    return k == rec.length;
  }
  for (const w of words) {
    if (check(w)) ans++;
  }
  return ans;
};