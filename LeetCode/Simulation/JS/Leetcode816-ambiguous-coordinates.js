var ambiguousCoordinates = function(s) {
  let [ans, ss] = [[], s.substr(1, s.length - 2)];
  let get = (s) => {
    res = [];
    if(s.length == 1 || s[0] != '0') res.push(s);
    for(let i = 1;i < s.length;i++) {
      const [l, r] = [s.substr(0, i), s.substr(i)];
      if(l.length > 1 && l[0] == '0') continue;
      if(r[r.length - 1] == '0') continue;
      res.push(l + '.' + r);
    }
    return res;
  }
  for(let i = 1;i < ss.length;i++) {
    const [l, r] = [get(ss.substr(0, i)), get(ss.substr(i))];
    for(const x of l) {
      for(const y of r) {
        ans.push('(' + x + ", " + y + ')');
      }
    }
  }
  return ans;
};
