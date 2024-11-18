#include<stdio.h>
#define size 5
int q[size];
int f=-1;
int r=-1;
int value;
int isEmpty()
{
    if(f==-1 && r==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if(f==(r+1)%size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insertq(int value)
{
    if(isEmpty())
    {
        f=r=0;
        q[r]=value;
    }
    else
    {
        r=(r+1)%size;
        q[r]=value;
    }
}
int deleteq()
{
    value=q[f];
    if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f=(f+1)%size;
    }
    return(value);
}
void display()
{
    int i;
    if(f<=r)
    {
        for(i=f;i<=r;i++)
        {
            printf("%d\t",q[i]);
        }
    }
    else if(r<f)
    {
        for(i=0;i<size;i++)
        {
            printf("%d\t",q[i]);
        }
    }
    else if(r==-1 && f==-1)
    {
        printf("q is empty");
    }
}
void main()
{
    int ch,del,value;
    do{
        printf("enter u r choice");
        printf("\n1.insert  2.delete  3.display  4.exit");
        printf("\nchoice");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1 : if(isFull())
                     {
                        printf("q is full");
                     }
                     else
                     {
                        printf("enter the value");
                        scanf("%d",&value);
                        insertq(value);
                     }
                     break;
            case 2 : if(isEmpty())
                     {
                        printf("q is empty");
                     }
                     else
                     {
                        del=deleteq();
                        printf("%d deleted",del);
                     }
                     break;
            case 3 : display();
                     break;
            case 4 : printf("exited");
                     break;
            default : printf("wrong choice");
                      break;
        
        }
    } while (ch!=4);
    
}