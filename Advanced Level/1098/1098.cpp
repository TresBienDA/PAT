#include<iostream>
#include<algorithm>
using namespace std;

int Ori[101];
int tempOri[101];
int target[101];
int n;

bool isSame(int a[],int b[])
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}

void showArray(int a[])
{
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n){
			cout<<" ";
		}
	}
	cout<<endl;
}

bool insertion()
{
	bool flag=false;
	for(int i=2;i<=n;i++)
	{	
		if(i!=2&&isSame(tempOri,target)){
			flag=true;
		}
		sort(tempOri+1,tempOri+i+1);
		if(flag==true){
			return true;
		}
	}
	return false;
}

void adjustdown(int low,int high)
{
	//堆是完全二叉树，所以i为父节点，j为左孩子结点（根节点编号为1） 
	int i=low,j=2*i;
	while(j<=high)
	{
		if(j+1<=high&&tempOri[j+1]>tempOri[j]){
			j=j+1;
		}
		if(tempOri[j]>tempOri[i]){
			swap(tempOri[j],tempOri[i]);
			i=j;
			j=2*i;
		} else {//if不满足则不用调整 
			break;
		}
	}	
} 

void heapsort()
{
	bool flag=false;
	//for(int i=n/2;i>1;i--){
	for(int i=n/2;i>=1;i--){
		adjustdown(i,n);
	}
	for(int i=n;i>1;i--)
	{
		if(i!=n&&isSame(tempOri,target)){
			flag=true;
		}
		swap(tempOri[1],tempOri[i]);
		adjustdown(1,i-1);
		if(flag==true){
			showArray(tempOri);
			return;
		}
	}
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>Ori[i];
		tempOri[i]=Ori[i];
	}
	for(int i=1;i<=n;i++){
		cin>>target[i];
	} 
	if(insertion()==true){
		cout<<"Insertion Sort"<<endl;
		showArray(tempOri);
	} else {
		cout<<"Heap Sort"<<endl;
		for(int i=1;i<=n;i++){
			tempOri[i]=Ori[i];
		}
		heapsort();
	}
	return 0;
} 
