#include<bits/stdc++.h>
using namespace std;
const int LEN=362880;//使用恒定变量定义最大值 
struct node//精妙的数据结构设置，包含当前状态和步数 
{
	int state[9];
	int dis;
};
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//定义方向数组，也就是上、下、左、右，BFS的时候使用
int visited[LEN]={0};//使用最大值LEN定义数组，从变量名就能看出来是标记有没有走过的
int start[9];//起始状态
int goal[9];//目标状态
long int factory[]={1,1,2,6,24,120,720,5040,40320,362880};
bool Cantor(int str[],int n)//用来实现康托展开的函数
{
	long result=0;//康托展开是计算cantor值的，所以要有答案变量
	for(int i=0;i<n;i++)
	{
		int counted=0;//每次循环都将counted变量置零
		for(int j=i+1;j<n;j++)//看一下当前状态前面的状态的数量，并在比较完成后加上
		{
			if(str[i]>str[j])
			{
				++counted;
			}
		}	
		result+=counted*factory[n-i-1];//计算result 
	} 
	if(!visited[result])//如果这一部没有走过 
	{
		visited[result]=1;//就把他标记为走过 
		return 1;
	}
	else return 0;
}
int bfs()//bfs函数 
{
	node head;//定义结构体：head 
	memcpy(head.state,start,sizeof(head.state));//使用memcpy函数将start数组copy到head上 
	head.dis=0;//初始值 
	queue<node> q;
	Cantor(head.state,9);
	q.push(head);
	while(!q.empty())//当队列不为空时！ 
	{
		head=q.front();//取队列的顶端一个 
		q.pop();
		int z;
		for(z=0;z<9;z++)
		{
			if(head.state[z]==0)
			{
				break;
			}
		}
		int x=z%3;
		int y=z/3;
		for(int i=0;i<4;i++)
		{
			int newx=x+dir[i][0];
			int newy=y+dir[i][1];
			int nz=newx+3*newy;
			if(newx>=0 && newx<3 && newy>=0 &&newy<3)
			{
				node newnode;
				memcpy(&newnode,&head,sizeof(struct node));
				swap(newnode.state[z],newnode.state[nz]);
				newnode.dis++;
				if(memcmp(newnode.state,goal,sizeof(goal))==0) return newnode.dis;
				if(Cantor(newnode.state,9)) q.push(newnode);
			}
		}
	}
	return -1;
} 
int main()
{
	for(int i=0;i<9;i++) cin>>start[i];//输入起始状态 
	for(int i=0;i<9;i++) cin>>goal[i];//输入重点、目标状态 
	int num=bfs();//调用bfs函数 
	if(num!=-1) cout<<num<<endl;//如果步数有效，则输出出来 
	else cout<<"Impossible"<<endl;//否则就判定为impossible 
	return 0;
}
