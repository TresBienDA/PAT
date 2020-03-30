#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
	string sno;
	int d;
	int c;
}stu;

bool cmp(stu a,stu b)
{
    if(a.d+a.c!=b.d+b.c)
    {
        return a.d+a.c>b.d+b.c;
    } else if(a.d!=b.d)
    {
        return a.d>b.d;
    } else if(strcmp(a.sno.c_str(),b.sno.c_str())!=0)
    {
        return strcmp(a.sno.c_str(),b.sno.c_str())<0;
    }
}

int main()
{
    stu s[100000];
    stu A[100000];
    stu B[100000];
    stu C[100000];
    stu D[100000];
    int N;
    int L;
    int H;
    scanf("%d%d%d",&N,&L,&H);
    for(int i=0;i<N;i++)
    {
        cin>>s[i].sno>>s[i].d>>s[i].c;
    }
    int M=0;
    int j=0,k=0,l=0,m=0;
    for(int i=0;i<N;i++)
    {
        if(s[i].d>=H&&s[i].c>=H)//才德全尽
        {
            A[j]=s[i];
            j++;
            M++;
        }else if(s[i].d>=H&&s[i].c>=L&&s[i].c<H)//德胜才
            {
                B[k]=s[i];
                k++;
                M++;
            }else if(s[i].d>=L&&s[i].d<H&&s[i].c>=L&&s[i].c<H&&s[i].d>s[i].c)//德才兼亡但德胜才
                    {
                        C[l]=s[i];
                        l++;
                        M++;
                    } else //其他
                    {
                        D[m]=s[i];
                        m++;
                        M++;
                    }

    }
    printf("%d\n",M);
    sort(A,A+j,cmp);
    sort(B,B+k,cmp);
    sort(C,C+l,cmp);
    sort(D,D+m,cmp);
    for(int i=0;i<j;i++)
    {
        cout<<A[i].sno<<A[i].d<<A[i].c<<endl;
    }
    for(int i=0;i<k;i++)
    {
        cout<<B[i].sno<<B[i].d<<B[i].c<<endl;
    }
    for(int i=0;i<l;i++)
    {
        cout<<C[i].sno<<C[i].d<<C[i].c<<endl;
    }
    for(int i=0;i<m;i++)
    {
        cout<<D[i].sno<<D[i].d<<D[i].c<<endl;
    }
}
