#include "sort.h"

void BubbleSort(int *a, int num)
{
    for (int i = 0; i < num;i++)
    {
        for (int j = 0; i + j + i < num;j++)
        {
            if(a[j]>a[j+1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}
