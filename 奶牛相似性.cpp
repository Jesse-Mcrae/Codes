#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[51][51],b[51][51];
int i,j;
int ans;
int main()
{
	cin>>m>>n;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];	
		} 
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>b[i][j];
			if(a[i][j]==b[i][j]) ans++;	
		} 
	}		
	cout<<ans<<endl;
	return 0;
} 
