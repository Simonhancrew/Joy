#if HASH
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto x : nums)
        {
            if (st.count(x))
                return x;
            st.insert(x);
        }
        return -1;
    }
};
#endif
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int n = nums.size();
        mt19937 gen(random_device{}()); // default_random_engine r(random_device{}());
        uniform_int_distribution<int> dis(0, n - 1);
        while (true)
        {
            int x = dis(gen), y = dis(gen);
            if (x != y && nums[x] == nums[y])
                return nums[x];
        }
        return -1;
    }
};