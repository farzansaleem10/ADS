#include <stdio.h>
void main()
{
    int a[10], n, i, u[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, j, b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("Enter the no of elements in your array(must be <=10): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the the element %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Your array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (u[j] == a[i])
            {
                b[j] = 1;
                break;
            }
        }
    }
    printf("\nBitstring representation is: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", b[i]);
    }
}
