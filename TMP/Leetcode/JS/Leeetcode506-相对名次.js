var findRelativeRanks = function(score) {
    let n = score.length;
    let rec = ["Gold Medal", "Silver Medal", "Bronze Medal"];
    let help = new Array(n).fill(n).map(() => new Array(2).fill(0));
    for(let i = 0;i < n;i++){
        help[i][0] = score[i];
        help[i][1] = i;
    }
    help.sort((a,b) => b[0] - a[0]);
    let ans = new Array(n).fill(0);
    for(let i = 0;i < n;i++){
        if(i >= 3){
            ans[help[i][1]] = '' + (i + 1);
        }else{
            ans[help[i][1]] = rec[i];
        }
    }
    return ans;
};