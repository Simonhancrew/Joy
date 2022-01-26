var findOcurrences = function(text, first, second) {
    const rec = text.split(" ");
    const ans = [];
    for(let i = 0;i < rec.length;i++){
        if(rec[i] == first && i + 2 < rec.length){
            if(rec[i + 1] == second) ans.push(rec[i + 2]);
        }
    }
    return ans;
};