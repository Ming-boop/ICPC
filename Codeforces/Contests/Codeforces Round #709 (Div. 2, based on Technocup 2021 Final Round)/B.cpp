#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAX_T = 1e5, INF = 0x7fffffff;
int a[MAX_T];

int main()
{
    int m, n, t, pos, neg, flag;
    cin >> t;
    while (t--)
    {
        cin >> n;
        flag = 0;
        pos = INF;
        neg = -INF;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (flag == -1)
            {
                continue;
            }
            if (a[i] < 0 || flag == -1)
            {
                flag = -1;
            }
            if (i)
            {
                if (a[i] > a[i - 1])
                {
                    if (pos == INF)
                    {
                        pos = a[i] - a[i - 1];
                    }
                    else if (pos != a[i] - a[i - 1])
                    {
                        flag = -1;
                    }
                }
                else if (a[i] < a[i - 1])
                {
                    if (neg == -INF)
                    {
                        neg = a[i] - a[i - 1];
                    }
                    else if (neg != a[i] - a[i - 1])
                    {
                        flag = -1;
                    }
                }
                else
                {
                    if (pos == INF && neg == -INF)
                    {
                        pos = neg = 0;
                    }
                    else if (pos || neg)
                    {
                        flag = -1;
                    }
                }
            }
        }
        if (flag == -1)
        {
            cout << "-1\n";
        }
        else if ((!pos && !neg) || (pos == INF) || (neg == -INF))
        {
            cout << "0\n";
        }
        else
        {
            m = pos - neg;
            for (int i = 0; i < n; i++)
            {
                if (abs(a[i]) > m)
                {
                    flag = -1;
                    cout << "-1\n";
                    break;
                }
            }
            if (flag != -1)
            {
                cout << m << " " << pos << endl;
            }
        }
    }
    return 0;
}
