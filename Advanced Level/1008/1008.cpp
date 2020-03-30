#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int SumTime=0;
    int List[1000];
    for(int i=0;i<n;i++)
    {
        cin>>List[i];
    }
    int i,j;
    SumTime=SumTime+List[0]*6+5;
    for( i=0,j=1;j<n;i++,j++)
    {
	 	if(List[i]<List[j])
        {
            SumTime=SumTime+(List[j]-List[i])*6+5;
        } else {
            SumTime=SumTime+(List[i]-List[j])*4+5;
        }
    }
    cout<<SumTime;
}
