bool bellman(int v0)
{
	int i,j;
	for(i=1;i<=nv;i++) d[i]=maxx;
	d[v0]=0;
	for(i=1;i<=nv-1;i++)
	{
		for(j=1;j<=ne;j++)
		{
			if(d[edge[j].a]+edge[j].w<d[edge[j].b])
			{
				d[edge[j].b]=d[edge[j].a]+edge[j].w;
			}
			for(j=1;j<=ne;j++)
			{
				if(d[edge[j].a]+edge[j].w<d[edge[j].b]) return false;
			}
			return true;
		}
	}
}
