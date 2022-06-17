class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        int i, j, cnt = 0;
        for (i = 0; i < n && cnt < n; i++)
        {
            if (arr[i])
                cnt++;
            else
                cnt += 2;
        }
        i--;
        j = n - 1;
        if (cnt == n + 1)
        {
            arr[j] = 0;
            j--, i--;
        }
        while (j >= 0)
        {
            arr[j] = arr[i];
            j--;
            if (arr[i] == 0)
            {
                arr[j] = arr[i];
                j--;
            }
            i--;
        }
    }
};