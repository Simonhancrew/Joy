var hasAlternatingBits = function(n) {
    let pre = n & 1;
    n >>= 1;
    while(n) {
        if(pre == (n & 1)) return false; // 运算符优先级问题
        pre = n & 1;
        n >>= 1;
    }
    return true;
};