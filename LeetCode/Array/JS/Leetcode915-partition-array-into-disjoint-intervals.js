var sumSubarrayMins = function(arr) {
  const n = arr.length;
  let [l, r] = [new Array(n).fill(0), new Array(n).fill(n)];
  let stk = [];
  for(let i = 0;i < n;i++) {
    while(stk.length && arr[stk[stk.length - 1]] > arr[i]) stk.pop();
    if(stk.length == 0) l[i] = -1;
    else l[i] = stk[stk.length - 1];
    stk.push(i);
  }
  stk = [];
  for(let i = n - 1;i >= 0;i--) {
    while(stk.length && arr[stk[stk.length - 1]] >= arr[i]) stk.pop();
    if(stk.length == 0) r[i] = n;
    else r[i] = stk[stk.length - 1];
    stk.push(i);
  }
  let ans = 0;
  const P = parseInt(1e9 + 7);
  for(let i = 0;i < n;i++) {
    res = (res + arr[i] * (i - l[i]) * (r[i] - i)) % P;
  }
  return res;
};
