var generateTheString = function(n) {
    if(n % 2 == 0) {
        return "a".repeat(n - 1) + "b";
    }
    if(n == 1) return "a";
    return "a".repeat(n - 2) + "b" + "c";
};
