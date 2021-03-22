#include <iostream>

using namespace std;

const int INF = 0x7fffffff;

int main()
{
    int pencil, pack, price, cost, opt_cost = INF;
    cin >> pencil;
    for (int i = 0; i < 3; i++)
    {
        cin >> pack >> price;
        cost = price * (pencil / pack + (pencil % pack > 0));
        if (cost < opt_cost)
        {
            opt_cost = cost;
        }
    }
    cout << opt_cost << endl;
    return 0;
}
