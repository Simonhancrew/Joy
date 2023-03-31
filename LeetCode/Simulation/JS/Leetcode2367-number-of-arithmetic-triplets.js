var arithmeticTriplets = function (nums, diff) {
  let st = new Set();
  for (const x of nums) {
    st.add(x);
  }
  let ans = 0;
  for (const x of nums) {
    if (st.has(x + diff) && st.has(x + 2 * diff)) {
      ans++;
    }
  }
  return ans;
};