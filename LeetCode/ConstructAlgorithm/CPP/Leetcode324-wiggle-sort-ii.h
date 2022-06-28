/*
    快速选择 + 三数排序（大的放在最前面）
*/
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
#define A(i) nums[(1 + 2 * i) % (n | 1)]
        for (int i = 0, j = 0, k = n - 1; i <= k;)
        {
            if (A(i) > mid)
                swap(A(i++), A(j++));
            else if (A(i) < mid)
                swap(A(i++), A(k--));
            else
                j++;
        }
    }
};