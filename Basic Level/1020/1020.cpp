#include<stdio.h> 
#include<iostream>
#define Maxsize 1000

typedef struct {
	//�ӵ㣬��Ŀ˵�����ܼ����������������� 
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
    //�����۴Ӵ�С���� 
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
    //����̰�ķ���˼�룬ÿһ����ȡ��õĽ��
	//���ӵ�����ߵĿ�ʼ�� 
    for(int i=0;i<n;i++)
    {
        if(sold+cake[i].num<need)//���㲻��Ҫ��
        {
            sold=sold+cake[i].num;
            cake[i].num=0;
            money=money+cake[i].price;
        } else if(sold+cake[i].num==need)//����պ�����Ҫ��
                {
                    sold=sold+cake[i].num;
                    cake[i].num=0;
                    money=money+cake[i].price;
                } else if(sold+cake[i].num>need)//��������Ҫ��֮����ʣ���
                        {
                            cake[i].num=cake[i].num-(need-sold);
                            money=money+(need-sold)*cake[i].perprice;
                            sold=need;
                        } else if(sold+cake[i].num<need&&i==n-1)//ȫ������Ҳ������������
                                {
                                    money=money+cake[i].price;
                                }
    }
    printf("%.2f",money);
}
