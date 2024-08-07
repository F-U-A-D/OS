//
// Created by muhdf on 11-07-2024.
//
#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int i,j,n,current,min;
    float awt=0,atat=0;
    printf("enter number of process: ");
    scanf("%d",&n);
    int a[n][5];
    printf("enter at,bt and priority of \n");
    for(i=0;i<n;i++)
    {
        printf("process id: ");
        scanf("%d",&a[i][0]);
        printf("AT of %d: ",a[i][0]);
        scanf("%d",&a[i][1]);
        printf("BT of %d: ",a[i][0]);
        scanf("%d",&a[i][2]);
        printf("priority of %d: ",a[i][0]);
        scanf("%d",&a[i][5]);
    }
//sorting at and prio?
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j][1]>a[j+1][1])
            {
                swap(&a[j][0],&a[j+1][0]);
                swap(&a[j][1],&a[j+1][1]);
                swap(&a[j][2],&a[j+1][2]);
                swap(&a[j][5],&a[j+1][5]);
            }
            if(a[j][1]==a[j+1][1] && a[j][5]>a[j+1][5])
            {
                swap(&a[j][0],&a[j+1][0]);
                swap(&a[j][1],&a[j+1][1]);
                swap(&a[j][2],&a[j+1][2]);
                swap(&a[j][5],&a[j+1][5]);
            }
        }
    }
//calcu 1st row
    a[0][3]=a[0][1];
    a[0][4]=a[0][2]-a[0][1];
    current=a[0][4];
    awt+=a[0][3];
    atat+=a[0][4];
//sorting by min prio
    for(i=1;i<n;i++)
    {
        min=a[i][5];
        for(j=i+1;j<n;j++)
        {
            if(min>a[j][5] && current>a[j][1])
            {
                min=a[j][5];
                swap(&a[j][0],&a[i][0]);
                swap(&a[j][1],&a[i][1]);
                swap(&a[j][2],&a[i][2]);
                swap(&a[j][5],&a[i][5]);
            }
        }
//calcu
        a[i][3]=current-a[i][1];
        awt+=a[i][3];
        current+=a[i][2];
        a[i][4]=current-a[i][1];
        atat+=a[i][4];
    }
    printf("PID\tAT\tBT\tPRIO\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][5],a[i][3],a[i][4]);
    }
    printf("avg wt: %f and avg tat: %f",awt/n,atat/n);
    return 0;}