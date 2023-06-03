var maxRepOpt1 = function (text) {
  const n = text.length;
  let f = new Array(26).fill(0).map(() => new Array());
  for (let i = 0; i < n; i++) {
    f[text[i].charCodeAt() - 'a'.charCodeAt()].push(i);
  }
  let res = 0;
  for (let p of f) {
    for (let [i, j] = [0, 0]; i < p.length; i++) {
      while (p[i] - p[j] > i - j + 1) j++;
      if (i + 1 < p.length || j) {
        res = Math.max(res, p[i] - p[j] + 1);
      }
    }
    for (let [i, j] = [0, 0]; i < p.length; i++) {
      while (p[i] - p[j] > i - j) j++;
      let t = p[i] - p[j] + 1;
      if (i + 1 < p.length || j) t++;
      res = Math.max(res, t);
    }
  }
  return res;
};
