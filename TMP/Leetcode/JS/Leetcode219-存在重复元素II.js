var containsNearbyDuplicate = function(nums, k) {
    const st = new Set();
    const n = nums.length;
    for(let i = 0;i < n;i++) {
        if(i > k) st.delete(nums[i - k - 1]);
        if(st.has(nums[i])) return true;
        st.add(nums[i]);
    }
    return false;
};