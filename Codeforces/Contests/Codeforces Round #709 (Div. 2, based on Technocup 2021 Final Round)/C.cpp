#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

const int MAX_N = 1e5;
typedef vector<int> vi;
vi v[MAX_N];
int f[MAX_N], arr[MAX_N];

bool cmp(int a, int b)
{
    return f[a] < f[b];
}

int main()
{
    int t, m, n, num, d, ok;
    cin >> t;
    while (t--)
    {
        ok = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < m; i++)
        {
            cin >> f[i];
            for (int j = 0; j < f[i]; j++)
            {
                cin >> num;
                v[num - 1].pb(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            sort(v[i].begin(), v[i].end(), cmp);
            d = 0;
            for (int j = 0; j < v[i].size() && d < (m + 1) / 2; j++)
            {
                if (!arr[v[i][j]])
                {
                    arr[v[i][j]] = i + 1;
                    d++;
                }
            }
            ok += d;
        }
        if (ok == m)
        {
            cout << "YES\n";
            for (int i = 0; i < m; i++)
            {
                if (i)
                {
                    cout << " ";
                }
                cout << arr[i];
            }
            cout << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
