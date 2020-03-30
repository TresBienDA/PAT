#include<stdio.h> 
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#define Maxsize 100
using namespace std;
int main()
{
	vector<string> word;
	string str;
	string s;
	int i=0;
	//string str1="abc";
	//string str2="def";
	//str1=str2;
	//cout<<str1;
	getline(cin,str);
	 stringstream ss(str);
	 while(ss>>s){
	 	word.push_back(s);
	 }
	 reverse(word.begin(),word.end());
	 vector<string>::iterator it;
	 it=word.begin();
	 cout<<*it;
	 for(it=word.begin()+1;it!=word.end();it++)
	 {
	 	cout<<" "<<*it;
	 }
}
