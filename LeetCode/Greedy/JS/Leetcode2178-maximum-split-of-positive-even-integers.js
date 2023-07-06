var maximumEvenSplit = function (finalSum) {
  if (finalSum & 1) {
    return [];
  }
  let ans = [];
  for (let i = 2; finalSum >= i; i += 2) {
    ans.push(i);
    finalSum -= i;
  }
  if (finalSum) {
    const n = ans.length;
    ans[n - 1] += finalSum;
  }
  return ans;
};