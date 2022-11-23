var countBalls = function (lowLimit, highLimit) {
  let [ans, mp] = [0, new Map()];
  let calcu = (x) => {
    let res = 0;
    while (x) {
      res += x % 10;
      x = parseInt(x / 10);
    }
    return res;
  }
  for (let i = lowLimit; i <= highLimit; i++) {
    mp.set(calcu(i), (mp.get(calcu(i)) | 0) + 1);
  }
  for (const x of mp.values()) {
    ans = Math.max(ans, x);
  }
  return ans;
};