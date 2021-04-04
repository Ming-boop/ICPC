#include "sort.h"

void QuickSort(int *a, int l, int r)
{
    int i = l, j = r, pivot = a[(l + r) / 2];
    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(a[i++], a[j--]);
        }
    }
    if (l < j)
    {
        QuickSort(a, l, j);
    }
    if (i < r)
    {
        QuickSort(a, i, r);
    }
}
