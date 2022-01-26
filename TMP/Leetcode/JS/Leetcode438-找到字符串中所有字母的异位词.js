var findAnagrams = function(s, p) {
    let mp = new Map();
    for(const ch of p) mp.set(ch,(mp.get(ch) || 0) + 1);
    let arr = [];
    let n = s.length,m = p.length;
    let tot = mp.size;
    for(let i = 0,j = 0,sa = 0;j < n;j++){
        if(mp.has(s[j])){
            mp.set(s[j],mp.get(s[j]) - 1);
            if(mp.get(s[j]) == 0) sa++;
        }
        if(j - i + 1 == m){
            if(sa == tot) arr.push(i);
            if(mp.has(s[i])){
                if(mp.get(s[i]) == 0) sa--;
                mp.set(s[i],mp.get(s[i]) + 1);
            }
            i++;
        }
    }
    return arr;
};