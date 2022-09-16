var maxLengthBetweenEqualCharacters = function(s) {
  const rec = new Array(26).fill(-1);
  const n = s.length;
  let ans = -1;
  for (let i = 0; i < n; i++) {
    if (rec[s[i].charCodeAt() - 'a'.charCodeAt()] < 0) {
      rec[s[i].charCodeAt() - 'a'.charCodeAt()] = i;
    } else {
      ans = Math.max(ans, i - rec[s[i].charCodeAt() - 'a'.charCodeAt()] - 1);
    }
  }
  return ans;
};
