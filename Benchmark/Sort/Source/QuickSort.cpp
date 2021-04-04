#include "sort.h"

void QuickSort(int *a, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int t = a[l];
    a[l] = a[(l + r) / 2];
    a[(l + r) / 2] = t;
    int pivot = a[l];
    int l0 = l, r0 = r;
    while (l < r)
    {
        while (l < r && a[r] > pivot)
        {
            r--;
        }
        if (l < r)
        {
            a[l] = a[r];
            l++;
        }
        while (l < r && a[l] < pivot)
        {
            l++;
        }
        if (l < r)
        {
            a[r] = a[l];
            r--;
        }
    }
    a[l] = pivot;
    QuickSort(a, l0, l - 1);
    QuickSort(a, l + 1, r0);
}
