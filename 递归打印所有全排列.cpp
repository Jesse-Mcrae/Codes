#include<bits/stdc++.h>
using namespace std;
#define Swap(a,b){int temp=a;a=b;b=temp;}
int n;
int data[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
long long num=0;
int Perm(int begin,int end)
{
	int i;
	if(begin==end)
	{
		num++;
	}
	else
	{
		for(i=begin;i<=end;i++)
		{
			Swap(data[begin],data[i]); 
			Perm(begin+1,end);
			Swap(data[begin],data[i]);
		}
		
	}
	for(i=0;i<n;i++) cout<<data[i]<<" ";
	cout<<endl;
}
int main()
{
	cin>>n;
	Perm(0,n-1);
	cout<<num<<endl;
	return 0;
}
