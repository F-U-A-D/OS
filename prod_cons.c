//
// Created by muhdf on 11-07-2024.
//
#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=10,x=0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nproducer produces item :%d\n",x);
    ++mutex;
}
void consumer()
{
    --mutex;
    ++empty;
    --full;
    printf("\nconsumer consume item:%d\n",x);
    x--;
    ++mutex;
}
void main()
{
    int i,n;
    printf("\nenter choice 1 for produce,2 for consume and 3 for exit: ");
    for(i=1;i>0;i++)
    {
        printf("\nenter choice?");
        scanf("%d",&n);
        switch(n)
        {
            case 1:if((mutex==1)&&(empty!=0))
                {
                    producer();
                }
                else
                {
                    printf("buffer full!!! remove item asappp\n");
                }
                break;
            case 2:if((mutex==1)&&(full!=0))
                {
                    consumer();
                }
                else
                {
                    printf("buffer empty nothing to consume!");
                }
                break;
            case 3:exit(0);
                break;
            default:printf("invalid request:");break;
        }
    }
}