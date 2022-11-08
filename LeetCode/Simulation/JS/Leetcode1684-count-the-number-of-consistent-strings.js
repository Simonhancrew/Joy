var countConsistentStrings = function(allowed, words) {
    let [ans, mask] = [0, 0];
    for(const c of allowed) mask |= 1 << (c.charCodeAt() - 'a'.charCodeAt());
    for(const word of words) {
        let cur = 0;
        for(const c of word) {
            cur |= 1 << (c.charCodeAt() - 'a'.charCodeAt());
        } 
        ans += (mask | cur) == mask;
    }
    return ans;
};
