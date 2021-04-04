#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

const std::string FILE_PREFIX = "Data/Data", FILE_SUFFIX = ".in";
const int num[] = {10, 100, 200, 500, 1000, 2000, 5000, int(1e4), int(2e4), int(5e4), int(1e5), int(2e5), int(5e5), int(1e6), int(2e6), int(5e6), int(1e7), int(2e7),int(5e7), int(1e8)};
const int MAX_GROUP = 20;

void generate_random(int num, int id)
{
    std::string file_name = FILE_PREFIX + std::to_string(id) + FILE_SUFFIX;
    freopen(file_name.c_str(), "w", stdout);
    printf("%d\n", num);
    for (int i = 0; i < num; i++)
    {
        if (i)
        {
            putchar(' ');
        }
        printf("%d", rand());
    }
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < MAX_GROUP; i++)
    {
        generate_random(num[i], i + 1);
    }
    return 0;
}
