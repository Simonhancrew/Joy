var canTransform = function (start, end) {
  const n = start.length;
  let [i, j] = [0, 0];
  while (true) {
    while (i < n && start[i] == 'X') i++;
    while (j < n && end[j] == 'X') j++;
    if (i == n || j == n) break;
    if (start[i] != end[j]) return false;
    if (start[i] == 'L' && i < j) return false;
    if (start[i] == 'R' && i > j) return false;
    i++;
    j++;
  }
  return i == n && j == n;
};