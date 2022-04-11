var countNumbersWithUniqueDigits = function(n) {
    if(n == 0) return 1;
    if(n == 1) return 10;
    let [base,mul,res] = [9,9,10];
    for(let i = 0;i < n - 1;i++) {
        base *= (mul - i);
        res += base;
    }
    return res;
};