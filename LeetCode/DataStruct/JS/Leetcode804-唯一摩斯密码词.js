var uniqueMorseRepresentations = function(words) {
    const pos = [".-","-...","-.-.","-..",".","..-.","--.","....","..",
    ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
    "...-",".--","-..-","-.--","--.."];
    let st = new Set();
    for(const w of words) {
        let s = '';
        for(const x of w) {
            s += pos[x.charCodeAt(0) - 'a'.charCodeAt(0)];
        }
        st.add(s);
    }
    return st.size;
};