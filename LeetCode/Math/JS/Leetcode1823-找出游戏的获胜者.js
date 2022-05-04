var findTheWinner = function (n, k) {
    let res = 0;
    for (let i = 2; i <= n; i++) {
        res = (res + k) % i;
    }
    return res + 1;
};