/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function(words) {
    let n = words.length;
    let bitmask = new Array(n).fill(0);
    for(let i = 0;i < n;i++){
        for(let ch of words[i]){
            let t = ch.charCodeAt() - 'a'.charCodeAt();
            bitmask[i] |= 1 << t;
        }
    }
    let res = 0;
    for(let i = 0;i < n;i++){
        for(let j = i + 1;j < n;j++){
            if((bitmask[i] & bitmask[j]) == 0) {
                res = Math.max(res,words[i].length * words[j].length);
            }
        }
    }
    return res;
};