/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
 var getHint = function(secret, guess) {
    let st = new Map();
    let bull = 0,cow = 0;
    for(let i = 0;i < secret.length;i++){
        if(guess[i] == secret[i]) bull++;
        else {
            if(st.has(secret[i])) st.set(secret[i],st.get(secret[i]) + 1);
            else st.set(secret[i],1);
        }  
    }
    for(let i = 0;i < guess.length;i++){
        if(guess[i] != secret[i] && st.get(guess[i])){
            cow++;
            st.set(guess[i],st.get(guess[i]) - 1);
        }
    }
    return String(bull) + "A" + String(cow) + "B";
};