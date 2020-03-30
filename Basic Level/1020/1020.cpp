#include<stdio.h> 
#include<iostream>
#define Maxsize 1000

typedef struct {
	//坑点，题目说库存和总价是整数而非正整数 
    float num;
    float price;
    float perprice;
}mooncake;

int main()
{
    int n;
    int need;
    float sold=0;
    float money=0.0;
    mooncake cake[Maxsize];
    scanf("%d%d",&n,&need);
    for(int i=0;i<n;i++)
    {
        scanf("%f",&cake[i].num);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%f",&cake[i].price);
    }
    for(int i=0;i<n;i++)
    {
        cake[i].perprice=(float)cake[i].price/(float)cake[i].num;
    }
    mooncake temp;
    //按单价从大到小排序 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(cake[i].perprice<cake[j].perprice)
            {
                temp=cake[i];
                cake[i]=cake[j];
                cake[j]=temp;
            }
        }
    } 
    //根据贪心法的思想，每一步都取最好的结果
	//即从单价最高的开始卖 
    for(int i=0;i<n;i++)
    {
        if(sold+cake[i].num<need)//满足不了要求
        {
            sold=sold+cake[i].num;
            cake[i].num=0;
            money=money+cake[i].price;
        } else if(sold+cake[i].num==need)//卖完刚好满足要求
                {
                    sold=sold+cake[i].num;
                    cake[i].num=0;
                    money=money+cake[i].price;
                } else if(sold+cake[i].num>need)//卖完满足要求之后还有剩余的
                        {
                            cake[i].num=cake[i].num-(need-sold);
                            money=money+(need-sold)*cake[i].perprice;
                            sold=need;
                        } else if(sold+cake[i].num<need&&i==n-1)//全部卖完也不能满足需求
                                {
                                    money=money+cake[i].price;
                                }
    }
    printf("%.2f",money);
}
