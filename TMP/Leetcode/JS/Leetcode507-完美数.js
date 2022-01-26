var checkPerfectNumber = function(num) {
    let ans = 0;
    for(let i = 1;i <= num / i;i++){
        if(num % i == 0) {
            if(i < num) ans += i;
            if(i != Math.floor(num / i) && Math.floor(num / i) < num) ans += Math.floor(num / i);
        }
    }
    return ans == num;
};