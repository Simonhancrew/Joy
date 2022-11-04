var reachNumber = function(target) {
  let [cnt, acc] = [0, 0];
  target = Math.abs(target);
  while(acc < target || (acc - target) & 1) {
    cnt++;
    acc += cnt;
  }
  return cnt;
};
