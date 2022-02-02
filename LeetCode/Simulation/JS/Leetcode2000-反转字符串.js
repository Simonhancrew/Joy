var reversePrefix = function(word, ch) {
    const idx = word.indexOf(ch);
    if(idx >= 0) {
        const arr = [...word];
        let l = 0,r = idx;
        while(l < r) {
            const tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++,r--;
        }
        word = arr.join('');
    }
    return word;
};