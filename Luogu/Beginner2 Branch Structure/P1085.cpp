#include <iostream>

using namespace std;

int main()
{
    int unhappy = 0, time = 8;
    int school, after_school;
    for (int i = 1; i < 8; i++)
    {
        cin >> school >> after_school;
        if (school + after_school > time)
        {
            time = school + after_school;
            unhappy = i;
        }
    }
    cout << unhappy << endl;
    return 0;
}
