#include<bits/stdc++.h>
using namespace std;
int n,m;
int i,j;
int ans=0;
struct line
{
	int b;
	int e;
	int t;	
}a[10001];
bool used[30005]={0};
bool cmp(const line &x,const line &y)
{
	return x.e<y.e;
} 
int main()
{
	cin>>n>>m;
	for(i=0;i<m;i++) 
	{
		cin>>a[i].b>>a[i].e>>a[i].t;
	}
	sort(a,a+m,cmp);
	int i,j,k,ans=0;
	for(i=0;i<m;i++)
	{
		k=0;
		for(j=a[i].b;j<=a[i].e;j++)
		{
			if(used[j]) k++;
		}
		if(k>=a[i].t) continue;
		for(j=a[i].e;j>=a[i].b;j--)
		{
			if(!used[j]) 
			{
				used[j]=1;
				k++;
				ans++;
				if(k==a[i].t) break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
