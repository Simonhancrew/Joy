var parseBoolExpr = function (s) {
  let i = 0;
  let dfs = () => {
    if (s[i] == 't') {
      i++;
      return true;
    }
    if (s[i] == 'f') {
      i++;
      return false;
    }

    // op
    const op = s[i];
    i += 2;
    let res = true;
    if (op == '|') res = false;
    while (s[i] != ')') {
      if (s[i] == ',') i++;
      const t = dfs();
      if (op == '|') res ||= t;
      else res &= t;
    }
    i++;
    if (op == '!') res = !res;
    return res;
  }
  return dfs();
};