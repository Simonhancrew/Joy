var findPairs = function (nums, k) {
    nums.sort((a, b) => a - b);
    let [ans, n] = [0, nums.length];
    for (let [i, j] = [0, 0]; i < n; i++) {
        while (i < n - 1 && nums[i + 1] == nums[i]) i++;
        while (j < i && nums[i] - nums[j] > k) j++;
        if (j < i && nums[i] - nums[j] == k) ans++;
    }
    return ans;
};