#include "Source/sort.h"
#include <cstdio>
#include <ctime>
#include <string>

const std::string FILE_PREFIX = "Data/Data", FILE_SUFFIX = ".in";
const int MAX_GROUP = 20;

void Benchmark_Baseline()
{
    puts("Testing performance of std::sort()...");
    int num;
    for (int i = 0; i < MAX_GROUP; i++)
    {
        std::string file_name = FILE_PREFIX + std::to_string(i + 1) + FILE_SUFFIX;
        freopen(file_name.c_str(), "r", stdin);
        scanf("%d", &num);
        int *a = (int *)malloc(num * sizeof(int));
        for (int j = 0; j < num; j++)
        {
            scanf("%d", a + j);
        }
        clock_t begin = clock();
        std::sort(a, a + num);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time cost of sorting %d numbers using std::sort() is %lfs.\n", num, time_spent);
        free(a);
    }
    puts("");
}

void Benchmark_BubbleSort()
{
    puts("Testing performance of bubble sort...");
    int num;
    for (int i = 0; i < MAX_GROUP; i++)
    {
        std::string file_name = FILE_PREFIX + std::to_string(i + 1) + FILE_SUFFIX;
        freopen(file_name.c_str(), "r", stdin);
        scanf("%d", &num);
        if (num > 2e5)
        {
            continue;
        }
        int *a = (int *)malloc(num * sizeof(int));
        for (int j = 0; j < num; j++)
        {
            scanf("%d", a + j);
        }
        clock_t begin = clock();
        BubbleSort(a, num);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time cost of sorting %d numbers using bubble sort() is %lfs.\n", num, time_spent);
        free(a);
    }
    puts("");
}

int main()
{
    //Benchmark_Baseline();
    Benchmark_BubbleSort();
    return 0;
}
