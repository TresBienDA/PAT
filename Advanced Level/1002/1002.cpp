#include<stdio.h>
#define maxsize 10000 
int main()
{
    int i,k,j,count=0;
    double a;
    double p[maxsize];
    for(i=0;i<maxsize;i++){//��ʼ������ 
        p[i]=0;
    }
    scanf("%d",&k);//�������� 
    for(i=0;i<k;i++){//����ָ����ϵ�� 
        scanf("%d %lf",&j,&a);
        p[j]=p[j]+a;
    }
    scanf("%d",&k);//����ڶ�������ʽ 
    for(i=0;i<k;i++){//����ָ����ϵ������ɼ��� 
        scanf("%d %lf",&j,&a);
        p[j]=p[j]+a;
    }
    for(i=0;i<maxsize;i++){
        if(p[i]!=0){
            count++;
        }
    }
    printf("%d",count);
    //for(i=0;i<maxsize;i++) �����ʽ����Ҫע����� 
    //{
    //	if(p[i]!=0){
    //		printf("% d %.11f",i,p[i]);
    //	}
    //}
    for(i=maxsize-1;i>-1;i--)
    {
        if(p[i]!=0){
            printf("% d %.1lf",i,p[i]);
        }
    }
    return 0;
}
