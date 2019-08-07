priority_queue<pair<int,int>> q;
//大根堆（优先队列），pair的第二堆为节点编号
//pair的第一堆为dist的相反数（利用相反数变成小根堆） 
void dijkstra()
{
	memset(d,ox3f,sizeof(d));//dist数组 
	memset(v,0,sizeof(v));//节点标记  
	d[1]=0;
	q.push(make_pair(0,1));
	while(q.size())
	{
		int x=q.top().second;
		q.pop;//取出堆顶 
		if(v[x]) continue;
		v[x]=1;
		for(int i=head[x];i;i=Next[i])//扫描所有出边 
		{
			int y=ver[i],z=edge[i];
		}
		if(d[y]>d[x]+z)
		{
			d[y]=d[x]+z;
			q.push(make_pair(-d[y],y));//元素插入堆 
		}
	} 
}
