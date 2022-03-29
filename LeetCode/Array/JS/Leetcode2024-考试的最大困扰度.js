var maxConsecutiveAnswers = function(answerKey, k) {
    const n = answerKey.length;
    let ans = 1,cnt0 = 0,cnt1 = 0;
    for(let l = 0,r = 0;r < n;r++) {
        if(answerKey[r] == 'T') cnt1++;
        else cnt0++;

        while(l < r && Math.min(cnt0,cnt1) > k) {
            if(answerKey[l] == 'T') cnt1--;
            else cnt0--;
            l++;
        }

        ans = Math.max(ans,r - l + 1);
    }
    return ans;
};