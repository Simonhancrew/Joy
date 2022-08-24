var canBeEqual = function(target, arr) {
    target.sort((a,b) => a - b);
    arr.sort((a,b) => a - b);
    const n = target.length;
    for(let i = 0;i < n;i++) {
        if(target[i] != arr[i]) {
            return false;
        }
    }
    return true;
};