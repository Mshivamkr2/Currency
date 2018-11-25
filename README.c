
/*To find minimum currency of any denominations type*/
#include<stdio.h>
int main()
{
int amt,i,j,s=0,n;
    printf("Enter your amount please!/n");
scanf("%d",&amt);
printf("enter the no. of denominations\n");
scanf("%d",&n);
int d[n];
printf("enter the denominations\n");
for(i=0;i<n;i++)
{
    scanf("%d",&d[i]);
}
int temp;
for(j=0;j<n;j++)
 {
     for(i=0;i<n;i++)
    {
    if(d[i]>d[i+1])
{
        temp=d[i];
        d[i]=d[i+1];
        d[i+1]=temp;
}
  }
  }
printf("Printing denominations in ascending order\n");
for(i=0;i<n;i++)
{
 printf("%d\n",d[i]);
}
int ch[n];
for(i=0;i<n;i++)
{
ch[i]=0;
}

for(i=n-1;i>=0;i--)
{
    while(s<amt && (amt-s)>=d[i])
    {
        s=s+d[i];
        ch[i]++;
    }


}
    for(i=0;i<n;i++)
    {
        printf("the no denominations of %d is %d\n ",d[i],ch[i]);

    }

}


