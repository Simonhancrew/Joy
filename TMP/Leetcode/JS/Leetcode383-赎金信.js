var canConstruct = function(ransomNote, magazine) {
    let mp = new Array(26).fill(0);
    for(const ch of magazine){
        mp[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    for(const ch of ransomNote) {
        mp[ch.charCodeAt(0) - 'a'.charCodeAt(0)]--;
        if(mp[ch.charCodeAt(0) - 'a'.charCodeAt(0)] < 0) return false;
    }
    return true;
};