#include <iostream>

using namespace std;

int main()
{
    int n, w, s, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> w >> s;
        ans += w * s;
    }
    if (ans < 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
