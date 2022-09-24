var decrypt = function(code, k) {
  const n = code.length;
  let ans = new Array(n).fill(0);
  if(k == 0) return ans;
  for(let i = 0;i < n;i++) {
      if(k > 0) {
          let acc = 0;
          for(let j = i + 1;j <= i + k;j++) {
              acc += code[j % n];
          }
          ans[i] = acc;
      }else {
          let acc = 0;
          for(let j = i - 1;j >= i + k;j--) {
              acc += code[(j + n) % n];
          }
          ans[i] = acc;
      }
  }
  return ans;
};