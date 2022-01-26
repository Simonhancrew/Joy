/**
 * @param {number[]} persons
 * @param {number[]} times
 */
 var TopVotedCandidate = function(persons, times) {
    let n = persons.length;
    this.win = new Array(n).fill(0);
    this.t = times;
    let cnt = new Array(n).fill(0);
    let mxc = 0,mxp = -1;
    for(let i = 0;i < n;i++){
        let p = persons[i];
        ++cnt[p];
        if(cnt[p] >= mxc) {
            mxp = p;
            mxc = cnt[p];
        }
        this.win[i] = mxp;
    }
    // for(let i = 0;i < n;i++) console.log(this.win[i]);
};

/** 
 * @param {number} t
 * @return {number}
 */
TopVotedCandidate.prototype.q = function(t) {
    let l = 0,r = this.t.length - 1;
    while(l < r) {
        let mid = Math.floor((l + r + 1) / 2);
        if(this.t[mid] <= t) l = mid;
        else r = mid - 1;
    }
    return this.win[l];
};
