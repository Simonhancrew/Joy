var mergeAlternately = function (word1, word2) {
  const n = Math.min(word1.length, word2.length);
  let ans = "";
  for (let i = 0; i < n; i++) {
    ans += word1[i];
    ans += word2[i];
  }
  if (n != word1.length) ans += word1.substr(n);
  if (n != word2.length) ans += word2.substr(n);
  return ans;
};