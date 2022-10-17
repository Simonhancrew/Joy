var totalFruit = function(fruits) {
  let mp = new Map();
  let [res,n] = [0, fruits.length];
  for(let [i,j,s] = [0,0,0];i < n;i++) {
    mp.set(fruits[i], (mp.get(fruits[i]) | 0) + 1);
    if(mp.get(fruits[i]) == 1) s++;
    while(s > 2) {
      mp.set(fruits[j], mp.get(fruits[j]) - 1);
      if(mp.get(fruits[j]) == 0) s--;
      j++;
    }
    res = Math.max(res, i - j + 1);
  }
  return res;
};
