#include <vector>
using namespace std;
#if 0
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int i = 0,j = n-1;
        //O(m+n),所见搜索的范围
        while(i < m && j >= 0){
            if(matrix[i][j] < target) ++i;
            else if(matrix[i][j] > target) --j;
            else return true;
        }
        return false;
    }
};
#endif
// 先确定一维最大值，然后动态的修改，大了缩小，小了扩大
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int r = 0,c = m - 1;
        while(r < n && c >= 0){
            if(matrix[r][c] > target) c--;
            else if(matrix[r][c] < target) r++;
            else return true; 
        }
        return false;
    }
};