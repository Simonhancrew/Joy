#include <iostream>
#include <vector>

using namespace std;
const int N = 30;

int n, m;
int path[N];

void dfs(int u, int idx)
{
    if (n - idx + u + 1 < m)
        return;
    if (u == m)
    {
        for (int i = 0; i < m; i++)
            cout << path[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = idx; i <= n; i++)
    {
        path[u] = i;
        dfs(u + 1, i + 1);
        //         path[u] = 0;
    }
}

int main()
{
    //     freopen("input.txt","r",stdin);
    cin >> n >> m;
    dfs(0, 1);
    return 0;
}
