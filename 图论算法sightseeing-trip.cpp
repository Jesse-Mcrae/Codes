#include<bits/stdc++.h>
using namespace std;
int n,m,w[105][105],dis[105][105],pos[105][105],ans=2*1e8;
std::vector<int>path;
void getpath(int l,int r)
{
	if(!pos[l][r])return;
	getpath(l,pos[l][r]);
	path.push_back(pos[l][r]);
	getpath(pos[l][r],r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	w[i][j]=2*1e8;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		w[x][y]=w[y][x]=min(w[x][y],z);
	}
	for(int i=1;i<=n;i++)w[i][i]=0;
	memcpy(dis,w,sizeof(w));
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++)
		for(int j=i+1;j<k;j++)
		if(dis[i][j]+w[j][k]+w[k][i]<ans){
			ans=dis[i][j]+w[j][k]+w[k][i];
			path.clear();
			path.push_back(i);
			getpath(i,j);41
			path.push_back(j);
			path.push_back(k);
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(dis[i][j]>dis[i][k]+dis[k][j]){
			dis[i][j]=dis[i][k]+dis[k][j];
			pos[i][j]=k;
		}
	}
	if(ans==2*1e8)printf("No solution.");
	else{
		for(int i=0;i<path.size();i++)
		printf("%d ",path[i]);
	}
	return 0;
}
