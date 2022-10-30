const isdigit = (ch) => {
  return parseFloat(ch).toString() === "NaN" ? false : true;
}
var letterCasePermutation = function(s) {
  let [n, ans] = [s.length, []];
  s = [...s];
  let dfs = (i) => {
      if(i == n) {
          ans.push(s.join(''));
          return;
      }
      dfs(i + 1);
      if(!isdigit(s[i])) {
          s[i] = String.fromCharCode(s[i].charCodeAt() ^ 32);
          dfs(i + 1);
          s[i] = String.fromCharCode(s[i].charCodeAt() ^ 32);
      }
  }
  dfs(0);
  return ans;
};