var customSortString = function (order, s) {
  let pa = new Array(26).fill(26);
  for (let i = 0; i < order.length; i++) {
    pa[order[i].charCodeAt() - 'a'.charCodeAt()] = i;
  }
  s = [...s];
  s.sort((a, b) => {
    return pa[a.charCodeAt() - 'a'.charCodeAt()] - pa[b.charCodeAt() - 'a'.charCodeAt()];
  });
  return s.join('');
};