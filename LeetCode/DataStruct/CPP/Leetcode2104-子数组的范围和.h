#ifdef BF
/*
    数据范围1e3，直接暴力枚举
*/
class Solution
{
public:
    typedef long long LL;
    long long subArrayRanges(vector<int> &nums)
    {
        LL res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int mn = nums[i], mx = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                mn = min(nums[j], mn);
                mx = max(nums[j], mx);
                res += mx - mn;
            }
        }
        return res;
    }
};
#endif
/*
    单调栈，总计就是sumMax - sumMin
    算出每个位置的贡献就可以了，每个位置的lmx,rmx,lmn,rmn
    lmn,rmn:左侧和右侧最近的比它小的数的下标
    rmx,rmn:左侧和右侧最近的比它大的数的下标
    最后一个乘法原理结合贡献的区域就可以了
*/
class Solution
{
public:
    typedef long long LL;
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lmx(n), lmn(n), rmx(n), rmn(n);
        stack<int> minstk, maxstk;
        for (int i = 0; i < n; i++)
        {
            while (minstk.size() && nums[minstk.top()] > nums[i])
            {
                minstk.pop();
            }
            lmn[i] = minstk.empty() ? -1 : minstk.top();
            minstk.push(i);

            while (maxstk.size() && nums[maxstk.top()] <= nums[i])
            {
                maxstk.pop();
            }
            lmx[i] = maxstk.empty() ? -1 : maxstk.top();
            maxstk.push(i);
        }
        minstk = stack<int>(), maxstk = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (minstk.size() && nums[minstk.top()] >= nums[i])
            {
                minstk.pop();
            }
            rmn[i] = minstk.empty() ? n : minstk.top();
            minstk.push(i);

            while (maxstk.size() && nums[maxstk.top()] < nums[i])
            {
                maxstk.pop();
            }
            rmx[i] = maxstk.empty() ? n : maxstk.top();
            maxstk.push(i);
        }
        LL mxsum = 0, mnsum = 0;
        for (int i = 0; i < n; i++)
        {
            mxsum += (LL)(rmx[i] - i) * (i - lmx[i]) * nums[i];
            mnsum += (LL)(rmn[i] - i) * (i - lmn[i]) * nums[i];
        }
        return mxsum - mnsum;
    }
};