var maxRepeating = function(sequence, word) {
  let [l, r] = [0, parseInt(sequence.length / word.length)];
  while(l < r) {
    let mid = l + r + 1 >> 1;
    let s = word.repeat(mid);
    if(sequence.includes(s)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
};
