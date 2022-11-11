var halvesAreAlike = function(s) {
  let [st, n, cnt] = [new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']), s.length / 2, 0];
  for(let i = 0;i < n;i++) {
      if(st.has(s[i])) cnt++;
  }
  for(let i = n;i < n * 2;i++) {
      if(st.has(s[i])) cnt--;
      if(cnt < 0) return false;
  }
  return cnt == 0;
};