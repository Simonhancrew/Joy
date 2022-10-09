var scoreOfParentheses = function(s) {
  let n = s.length;
  let stk = [0];
  for(let i = 0;i < n;i++) {
    if(s[i] == '(') stk.push(0);
    else {
      let t = stk.pop();
      if(t == 0) {
        stk[stk.length - 1] += 1;
      }else {
        stk[stk.length - 1] += 2 * t;
      }
    }
  }
  return stk.pop()
};
