#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void init(int a[])
{
    for (int i = 0; i < 10; i++)
    {
        a[i] = -1;
    }
}
int hash(int value)
{
    return value % 10;
}
void insert(int value, int a[])
{
    int h, idx, i;
    h = hash(value);
    if (a[h] == -1)
    {
        a[h] = value;
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            idx = (h + i) % 10;
            if (a[idx] == -1)
            {
                a[idx] = value;
                break;
            }
        }
    }
}
void print(int a[])
{

    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d]: ", i);
        printf("%d\n", a[i]);
    }
}
int main()
{
    int a2[20];
    init(a2);
    insert(10, a2);
    insert(70, a2);
    insert(32, a2);
    insert(73, a2);
    insert(26, a2);
    insert(52, a2);
    insert(88, a2);
    insert(12, a2);

    print(a2);
    return 0;
}
