var canFormArray = function(arr, pieces) {
    let mp = new Map();
    for(let i = 0;i < pieces.length;i++) {
        mp.set(pieces[i][0],i);
    }
    for(let i = 0;i < arr.length;) {
        if(!mp.has(arr[i])) return false;
        let t = pieces[mp.get(arr[i])];
        let len = t.length
        for(let j = 0;j < len;j++) {
          if(arr[i] != t[j]) return false;
          i++;
        }
    }
    return true;
};
