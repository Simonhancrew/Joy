var maximumUnits = function (boxTypes, truckSize) {
  boxTypes.sort((a, b) => b[1] - a[1]);
  let ans = 0;
  for (const x of boxTypes) {
    if (x[0] >= truckSize) {
      ans += truckSize * x[1];
      break;
    }
    ans += x[0] * x[1];
    truckSize -= x[0];
  }
  return ans;
};