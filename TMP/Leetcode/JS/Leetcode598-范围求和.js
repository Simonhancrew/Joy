/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
 var maxCount = function(m, n, ops) {
    for(const op of ops){
        m = Math.min(m,op[0]);
        n = Math.min(n,op[1]);
    }
    return m * n;
};