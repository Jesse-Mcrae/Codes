#include<bits/stdc++.h>
using namespace std;
int n,cnt,L,h,x,r;
struct SEG
{
	double x,y;
}a[20005];
bool cmp(const SEG &x,const SEG &y)
{
	return x.x<y.x;
}
inline void Read()
{
	cin>>n>>L>>h;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>r;
		if(r<=h/2)
			continue;
		cnt++;
		a[cnt].x=x-sqrt(r*r-h*h/4.0);
		a[cnt].y=x+sqrt(r*r-h*h/4.0);;
	}
}
inline void solve()
{
	double t=0;
	int ans=0,bj=1,i=1;
	while(t<L)
	{
		ans++;
		double s=t;
		for(;a[i].x<=s&&i<=cnt;i++)
		{
			if(t<a[i].y) t=a[i].y;
		}
		if(t==s&&s<L)
		{
			cout<<-1<<endl;
			bj=0;
			break;
		} 
		
	}
	if(bj) cout<<ans<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		Read();
		sort(a+1,a+cnt+1,cmp);
		solve();
	}
	return 0;
}
