var areAlmostEqual = function (s1, s2) {
  if (s1 == s2) {
    return true;
  }
  let [n, rec] = [s1.length, []];
  for (let i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      rec.push(i);
      if (rec.length > 2) {
        return false;
      }
    }
  }
  if (rec.length == 1) return false;
  return s1[rec[0]] == s2[rec[1]] && s1[rec[1]] == s2[rec[0]];
};