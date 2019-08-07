#include<bits/stdc++.h>
using namespace std;
int n;
struct Area
{
	int s;
	int e;
}a[10001];
int i,j;
int ans=1;
bool cmp(Area x,Area y)
{
	return x.e<y.e;	
} 
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i].s>>a[i].e;	
	}	
	sort(a,a+n,cmp);
	int temp=a[0].e;
	for(i=1;i<n;i++)
	{
		if(a[i].s>=temp) 
		{
			ans++;
			temp=a[i].e;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
