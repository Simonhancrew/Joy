var minAddToMakeValid = function (s) {
  let [l, r] = [0, 0];
  for (const c of s) {
    if (c == '(') l++;
    else if (c == ')') {
      if (!l) r++;
      else l--;
    }
  }
  return l + r;
};