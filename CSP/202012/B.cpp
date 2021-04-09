#include <algorithm>
#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

const int MAX_M = 5e5 + 5;
typedef struct stu stu;
struct stu
{
    int score, result;
    bool operator<(const stu &stu2)
    {
        return this->score < stu2.score;
    }
} a[MAX_M];
vector<int> v[2], vt;

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].score >> a[i].result;
    }
    sort(a, a + m);
    int val_num = 0;
    for (int i = 0; i < m; i++)
    {
        if (!val_num || a[i].score != vt[val_num - 1])
        {
            vt.pb(a[i].score);
            val_num++;
            if (a[i].result)
            {
                v[0].pb(0);
                v[1].pb(1);
            }
            else
            {
                v[0].pb(1);
                v[1].pb(0);
            }
        }
        else
        {
            v[a[i].result][val_num - 1]++;
        }
    }
    int max_correct_predict = 0, theta = vt[0];
    for (int i = 0; i < val_num; i++)
    {
        max_correct_predict += v[1][i];
    }
    int cur_correct_predict = max_correct_predict;
    for (int i = 1; i < val_num; i++)
    {
        cur_correct_predict += v[0][i - 1] - v[1][i - 1];
        if (cur_correct_predict >= max_correct_predict)
        {
            max_correct_predict = cur_correct_predict;
            theta = vt[i];
        }
    }
    cout << theta << endl;
    return 0;
}
