#include<bits/stdc++.h>
using namespace std;
double ask;
int main()
{
	string s;
	double Huffman;
	priority_queue<int,vector<int>,greater<int> > q;
	while(getline(cin,s) && s!="END")
	{
		ask=s.size()*8;
		int t=1;
		sort(s.begin(),s.end());
		for(int i=1;i<s.size();i++)
		{
			if(s[i]!=s[i-1])
			{
				q.push(t);
				t=1;
			}
			else t++;
		}
		q.push(t);
		Huffman=0;
		while(q.size()>1)
		{
			int ops=q.top();
			q.pop();
			int oops=q.top();
			q.pop();
			q.push(ops+oops);
			Huffman+=ops+oops;
		}
		q.pop();
	}
	double divide=ask/Huffman;
	printf("%.0lf %.0lf %.1lf",ask,Huffman,divide);
	return 0;
}
