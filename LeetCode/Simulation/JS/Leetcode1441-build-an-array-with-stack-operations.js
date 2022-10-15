var buildArray = function (target, n) {
  let [ans, j] = [[], 0];
  for (let i = 1; i <= n; i++) {
    if (i == target[j]) {
      j++;
      ans.push("Push");
    } else {
      ans.push("Push");
      ans.push("Pop");
    }
    if (i == target[target.length - 1]) {
      break;
    }
  }
  return ans;
};