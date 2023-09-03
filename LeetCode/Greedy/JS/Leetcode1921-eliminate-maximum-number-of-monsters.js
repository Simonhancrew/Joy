var eliminateMaximum = function (dist, speed) {
  const n = dist.length;
  let rec = new Array(n);
  for (let i = 0; i < n; i++) {
    rec[i] = Math.floor((dist[i] + speed[i] - 1) / speed[i]);
  }
  rec.sort((a, b) => a - b);
  for (let i = 0; i < n; i++) {
    if (rec[i] <= i) {
      return i;
    }
  }
  return n;
};