#include <iostream>

using namespace std;

int main()
{
    const int cir = 10, bench = 30;
    int height[cir], human, ans = 0;
    for (int i = 0; i < cir; i++)
    {
        cin >> height[i];
    }
    cin >> human;
    int human_height = human + bench;
    for (int i = 0; i < cir; i++)
    {
        if (height[i] <= human_height)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
