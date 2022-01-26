var lastRemaining = function(n) {
    if(n == 1) return 1;
    return 2 * (Math.floor(n / 2) + 1 - lastRemaining(Math.floor(n / 2)));
};