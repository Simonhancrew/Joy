var magicalString = function(n) {
    let s = [..."122"];
    for(let [i,k] = [2, 1];s.length < n;i++, k = 3 - k) {
        for(let j = 0;j < s[i].charCodeAt() - '0'.charCodeAt();j++) {
            s.push(String.fromCharCode('0'.charCodeAt() + k));
        }  
    }
    // console.log(s);
    let ans = 0;
    for(let i = 0;i < n;i++) ans += (s[i] == '1');
    return ans;
};
