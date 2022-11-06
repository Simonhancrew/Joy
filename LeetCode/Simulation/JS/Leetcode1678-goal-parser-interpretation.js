var interpret = function(s) {
  let [res, n] = [[], s.length];
  for(let i = 0;i < n;i++) {
      if(s[i] == 'G') res.push('G');
      else {
          let j = i;
          while(s[j] != ')') j++;
          if(j - i <= 1) {
              res.push('o');
          } else {
              res.push("al");
          }
          i = j;
      }
  }
  return res.join('');
};