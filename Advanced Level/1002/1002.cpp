#include<stdio.h>
#define maxsize 10000 
int main()
{
    int i,k,j,count=0;
    double a;
    double p[maxsize];
    for(i=0;i<maxsize;i++){//初始化数组 
        p[i]=0;
    }
    scanf("%d",&k);//输入项数 
    for(i=0;i<k;i++){//读入指数和系数 
        scanf("%d %lf",&j,&a);
        p[j]=p[j]+a;
    }
    scanf("%d",&k);//读入第二个多项式 
    for(i=0;i<k;i++){//读入指数和系数并完成计算 
        scanf("%d %lf",&j,&a);
        p[j]=p[j]+a;
    }
    for(i=0;i<maxsize;i++){
        if(p[i]!=0){
            count++;
        }
    }
    printf("%d",count);
    //for(i=0;i<maxsize;i++) 输出格式错误要注意读题 
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
