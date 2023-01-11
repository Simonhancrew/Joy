var digitCount = function(num) {
    let mp = new Array(10).fill(0);
    for (const x of num) {
        mp[x.charCodeAt() - '0'.charCodeAt()]++;
    }
    for (let i = 0;i < num.length;i++) {
        const cnt = parseInt(num[i]);
        if (mp[i] != cnt) {
            return false;
        }
    }
    return true;
};
