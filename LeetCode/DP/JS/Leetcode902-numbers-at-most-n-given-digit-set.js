var atMostNGivenDigitSet = function (digits, n) {
  let s = n.toString()
  const m = s.length;
  let f = new Array(m).fill(-1);
  let dfs = function (idx, lead, limit) {
    if (idx == m) return !lead;
    if (!lead && !limit && f[idx] != -1) return f[idx];
    let res = 0;
    if (lead) {
      res = dfs(idx + 1, true, false);
    }
    let up = limit ? s[idx] : '9';
    for (const d of digits) {
      if (d > up) break;
      res += dfs(idx + 1, false, limit && (d === up));
    }
    if (!lead && !limit) f[idx] = res;
    return res;
  }
  return dfs(0, true, true);
};