#include<iostream>
using namespace std;
int INFINITY = 999;
class Dijkstra
{
	int adjMatrix[15][15];
	int predecessor[15] , distance[15];
	int mark[15];
	int source;
	int numofVertices;
	public:
		void read()
		{
			cout<<"Enter number of Vertices \n";
			cin>>numofVertices;
			for(int i = 0;i<numofVertices;i++)
				for(int j = 0;j<numofVertices;j++)
					cin>>adjMatrix[i][j];
			cout<<"Enter source vertex \n";
			cin>>source;
		}
		void initialise()
		{
			for(int i = 0;i<numofVertices;i++)
			{
				mark[i] = 0;
				predecessor[i] = -1;
				distance[i] = INFINITY;
			}
			distance[source] = 0;
		}
		int getClosestUnmarkedNode()
		{
			int minDistance = INFINITY;
			int closestUnmarkedNode;
			for(int i = 0;i<numofVertices;i++)
			{
				if(mark[i]==0&&(minDistance>=distance[i]))
				{
					minDistance = distance[i];
					closestUnmarkedNode = i;
				}
			}
			return closestUnmarkedNode;
		}
		void calculateDistance()
		{
			initialise();
			int minDistance = INFINITY;
			int closestUnmarkedNode;
			int count = 0;
			while(count<numofVertices)
			{
				closestUnmarkedNode = getClosestUnmarkedNode();
				mark[closestUnmarkedNode] = 1;
				for(int i = 0;i<numofVertices;i++)
				{
					if(mark[i]==0&&adjMatrix[closestUnmarkedNode][i]>0)
					{
						if(distance[i]>distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i])
						{
							distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
							predecessor[i] = closestUnmarkedNode;
						}
					}
				}
				count++;
			}
		}
		void printPath(int node)
		{
			if(node==source)
				cout<<(char)(node +97)<<"..";
			else if(predecessor[node]==-1)
			cout<<"No path from"<<source<<"to"<<(char)(node +97)<<endl;
			else
			{
				printPath(predecessor[node]);
				cout<<(char)(node +97)<<"..";
			}
		}
		void output()
		{
			for(int i = 0;i<numofVertices;i++)
			{
				if(i==source)
					cout<<(char)(source+97)<<".."<<source;
				else
				{
					printPath(i);
					cout<<"-->"<<distance[i]<<endl;
				}
			}
		}
};
int main()
{
	Dijkstra G;
	G.read();
	G.calculateDistance();
	G.output();
	return 0;
}
