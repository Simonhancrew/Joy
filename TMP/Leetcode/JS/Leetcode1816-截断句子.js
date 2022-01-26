var truncateSentence = function(s, k) {
    let res = "";
    for(let i = 0;i < s.length && k != 0;i++){
        if(s[i] == ' ') k--;
        if(k) res += s[i];
    }
    return res;
};
// var truncateSentence = function(s, k) {
//     let arr = s.split(' ')
//     arr = arr.slice(0,k);
//     return arr.join(' ');
// };