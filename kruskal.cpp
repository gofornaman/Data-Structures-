#include<iostream>
using namespace std;
int i , j, k , a , b , u , v , n , ne = 1;
int  mincost = 0 , cost[9][9] , parent[9];
int find(int i)
{
	while(parent[i])
	{
		i = parent[i];
	}
	return i;
}
int uni(int i , int j)
{
	if(i!=j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}
int main()
{
	int min = 999;
	cout<<"\n Implementation of Kruskal \n";
	cout<<"Enter no.of vertices \n";
	cin>>n;
	cout<<"Enter cost of adjacency matrix \n";
	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j] = 999;
		}
	}
	cout<<"Edges of MST are \n";
	while(ne<n)
	{
		for(i = 1 , min = 999 ; i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if(uni(u , v))
		{
			cout<<ne++<<" edge ("<<a<<","<<b<<") = "<<min<<endl;
			mincost+=min;
		}
		cost[a][b] = 999;
		cost[b][a] = 999;
		
	}
	cout<<"Minimum cost = "<<mincost;
	return 0;
}
