var maxChunksToSorted = function(arr) {
  const n = arr.length;
  let [mx, res] = [0, 0];
  for(let i = 0;i < n;i++) {
    mx = Math.max(mx, arr[i]);
    if(mx == i) {
      res += 1;
    }
  }
  return res;
};
