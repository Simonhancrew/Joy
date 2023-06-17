var numberOfCuts = function (n) {
    if (n == 1) {
        return 0;
    }
    if (n & 1) {
        return n;
    }
    return n / 2;
};