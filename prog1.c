#include <stdio.h>
#include <stdlib.h>
typedef struct hash
{
    int data;
    struct node *next;
} h;
typedef struct arr
{
    struct node *a[10]
} ar;

void in(ar *a1)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        a1->a[i] = NULL;
    }
}
void insert(int value, ar *a1)
{
    h *new = (h *)malloc(sizeof(h));
    new->data = value;
    new->next = NULL;
    int key = value % 10;

    if (a1->a[key] == NULL)
    {
        a1->a[key] = new;
    }
    else
    {
        // printf("Collision : arr[%d] has element %d already!\n", key, a[key]);
        h *temp = a1->a[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}
void print(ar *a1)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("arr [%d]: ", i);

        h *t = a1->a[i];
        if (t == NULL)
        {
            printf("NULL");
        }

        while (t != NULL)
        {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int main()
{
    ar a2;
    in(&a2);
    insert(10, &a2);
    insert(70, &a2);
    insert(32, &a2);
    insert(73, &a2);
    insert(26, &a2);
    insert(52, &a2);
    insert(88, &a2);
    insert(12, &a2);

    printf("Hash table\n");
    print(&a2);
}