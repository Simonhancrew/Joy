var isOneBitCharacter = function(bits) {
    const n = bits.length;
    let i = 0;
    while(i < n - 1) {
        i += bits[i] + 1;
    }
    return i == n - 1;
};