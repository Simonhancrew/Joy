var detectCapitalUse = function (word) {
  let cnt = 0;
  const n = word.length;
  let first = /^[A-Z]$/.test(word.charAt(0));
  for (const x of word) {
    if (/^[A-Z]$/.test(x)) {
      cnt += 1;
    }
  }
  return cnt == 0 || cnt == n || cnt == 1 && first;
};