#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct node
{
    char id[15];
    int score;
    int location;
    int lrank;
    int frank;
} record;

bool cmp(record a, record b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

int main()
{
    record R[30001];
    int n, k, i, j, sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        for (j = 0; j < k; j++)
        {
            R[sum].location = i;
            scanf("%s %d", R[sum].id, &R[sum].score);

            sum++;
        }
        sort(R + sum - k, R + sum, cmp);
        for (j = sum - k; j < sum; j++)
        {
            R[sum - k].lrank = 1;
            if (R[j].score < R[j - 1].score)
                R[j].lrank = j - sum + k + 1;
            else
                R[j].lrank = R[j - 1].lrank;
        }
    }
    sort(R, R + sum, cmp);
    R[0].frank = 1;

    for (i = 1; i < sum; i++)
    {
        if (R[i].score < R[i - 1].score)
            R[i].frank = i + 1;
        else
            R[i].frank = R[i - 1].frank;
    }
    printf("%d\n", sum);
    for (i = 0; i < sum; i++)
    {

        printf("%s %d %d %d\n", R[i].id, R[i].frank, R[i].location, R[i].lrank);
    }

    return 0;
}
