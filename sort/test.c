#include <stdio.h>

int insert_sort(int data[], int length)
{
    for (int i = 0 ; i < length; i++)
    {
        printf("[%d] ", data[i]);
    }
    printf("\n");
    return 0;
}


int main()
{
    int data[]={4,3,2,10,12,1,5,6};
    int length = sizeof(data) / sizeof(*data);
    printf("%d\n", length);
    printf("123\n");
    insert_sort(data, length);
    return 0;
}