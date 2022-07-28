var arrayRankTransform = function(arr) {
    let n = arr.length;
    let tmp = [...arr];
    tmp.sort((a,b) => a - b);
    let mp = new Map();
    for(let [i,cnt] = [0,1];i < n;i++) {
        if(!(mp.get(tmp[i]) | 0)) {
            mp.set(tmp[i],cnt);
            cnt++;
        }
    }
    let ans = new Array(n).fill(0);
    for(let i = 0;i < n;i++) {
        ans[i] = mp.get(arr[i]);
    }
    return ans;
};
