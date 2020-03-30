#include<stdio.h>
#include<iostream>
#define N 100
#define Maxsize 1000 
using namespace std;

typedef struct stu
{
	char sname[N];
	char sno[N];
	int  grade;
}stu;

int main()
{
	stu student[Maxsize];
	int n;
	int max,min;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s%s%d",student[i].sname,student[i].sno,&student[i].grade);
	}
	max=min=0;
	for(int i=0;i<n;i++)
	{
		if(student[i].grade>student[max].grade){
			max=i;
		}
		if(student[i].grade<student[min].grade) {
			min=i;
		}
	}
	printf("%s %s\n",student[max].sname,student[max].sno);
	printf("%s %s\n",student[min].sname,student[min].sno);
} 
