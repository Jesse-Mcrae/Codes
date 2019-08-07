#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n;
	int data[10001];
	cin>>n;
	for(i=0;i<n;i++) cin>>data[i];
	sort(data,data+n);
	do
	{
		for(int i=0;i<n;++i)
		{
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
	while(next_permutation(data,data+n));
	return 0;
}
