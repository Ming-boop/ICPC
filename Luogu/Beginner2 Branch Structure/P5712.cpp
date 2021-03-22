#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int number;
    cin >> number;
    if (!number || number == 1)
    {
        printf("Today, I ate %d apple.\n", number);
    }
    else
    {
        printf("Today, I ate %d apples.\n", number);
    }
    return 0;
}
