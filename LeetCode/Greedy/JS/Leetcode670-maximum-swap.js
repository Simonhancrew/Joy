var maximumSwap = function(num) {
    let rec = [];
    while(num){
        rec.push(num % 10);
        num = parseInt(num / 10);
    }
    const n = rec.length;
    for(let i = n - 1;i >= 0;i--) {
        let [rmx,idx] = [rec[i],i];
        for(let j = i - 1;j >= 0;j--) {
            if(rec[j] >= rmx) {
                rmx = rec[j];
                idx = j;
            }
        }
        if(rmx > rec[i]) {
            rec[idx] = rec[i];
            rec[i] = rmx;
            break;
        }
    }
    let ans = 0;
    for(let i = n - 1;i >= 0;i--) {
        ans = ans * 10 + rec[i];
    }
    return ans;
};
