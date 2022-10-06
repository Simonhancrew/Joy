var threeEqualParts = function (arr) {
  let acc = arr.reduce((s, num) => s + num, 0);
  if (!acc) return [0, 2];
  if (acc % 3) return [-1, -1];
  let [n, avg] = [arr.length, parseInt(acc / 3)];
  let [s, p] = [[1, avg, avg + 1, 2 * avg, 2 * avg + 1, 3 * avg], new Array(6).fill(0)];
  for (let [i, j, c] = [0, 0, 0]; i < n; i++) {
    if (arr[i] == 0) continue;
    c += 1;
    // 可能重合
    while (j < 6 && s[j] == c) {
      p[j] = i;
      j++;
    }
  }
  let last0 = n - 1 - p[5];
  let [dis1, dis2] = [p[2] - p[1] - 1, p[4] - p[3] - 1];
  if (dis1 < last0 || dis2 < last0) return [-1, -1];
  let check = (a, b, c, d) => {
    for (let [i, j] = [a, c]; i <= b; i++, j++) {
      if (arr[i] != arr[j]) return false;
    }
    return true;
  }
  if (!check(p[0], p[1], p[2], p[3])) return [-1, -1];
  if (!check(p[2], p[3], p[4], p[5])) return [-1, -1];
  return [p[1] + last0, p[3] + last0 + 1];
};