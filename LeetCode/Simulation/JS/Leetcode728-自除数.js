var selfDividingNumbers = function(left, right) {
    const res = [];
    let check = function(num) {
        let tmp = num;
        while(tmp) {
            const t = tmp % 10;
            tmp = Math.floor(tmp / 10);
            if(t == 0 || num % t != 0) return false;
        }
        return true;
    }
    for(let i = left;i <= right;i++) {
        if(check(i)) res.push(i);
    }
    return res;
};