var repeatedStringMatch = function(a, b) {
    let s = a,i = 1;
    while(s.length < b.length){
        s += a;
        i++;
    }
    if(s.indexOf(b) != -1) return i;
    else{
        s += a;
        i++;
        if(s.indexOf(b) != -1) return i;
    }
    return -1;
};