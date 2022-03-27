var missingRolls = function(rolls, mean, n) {
    const m = rolls.length,suma = rolls.reduce((sum,cur)=>sum + cur,0);
    const sumb = (n + m) * mean - suma;
    const ev = Math.floor(sumb / n),lf = sumb % n;
    if(ev < 1 || ev > 6) return []
    if(ev == 6 && lf) return []
    let res = new Array(n).fill(ev);
    for(let i = 0;i < lf;i++) res[i]++;
    return res;
};