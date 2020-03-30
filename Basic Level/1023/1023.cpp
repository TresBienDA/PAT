#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
   int numbers[10];
   int a[50];
   int sum=0;
   for(int i=0;i<10;i++)
   {
       scanf("%d",&numbers[i]);
       sum=sum+numbers[i];
   }
   int k=0;
   for(int i=0;i<10;i++)
   {
       if(numbers[i]!=0)
       {
            for(int j=0;j<numbers[i];j++)
            {
                a[k]=i;
                k++;
            }
       }
   }
   if(a[0]==0)
   {
       for(int i=0;i<sum;i++)
       {
           if(a[i]!=0)
           {
               	int temp;
               	temp=a[i];
              	a[i]=a[0];
               	a[0]=temp;
        		break;
           }

       }
   }
   for(int i=0;i<sum;i++)
   {
       printf("%d",a[i]);
   }
}
