var smallestDistancePair = function (nums, k) {
    nums.sort((a, b) => a - b);
    let [l, r] = [0, parseInt(1e6)];
    let get = function (mid) {
        let res = 0;
        for (let [i, j] = [0, 0]; i < nums.length; i++) {
            while (nums[i] - nums[j] > mid) j++;
            res += i - j;
        }
        return res;
    }
    while (l < r) {
        let mid = (l + r) >> 1;
        if (get(mid) >= k) r = mid;
        else l = mid + 1;
    }
    return r;
};