#include<iostream>
using namespace std;
int ROW = 7 , COL = 7 , infi = 5000;
class prims
{
   int graph[7][7],nodes;
   public:
   prims();
   void createGraph();
   void primsAlgo();
};

prims :: prims()
{
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            graph[i][j]=0;
}

void prims :: createGraph()
{
    int i,j;
    cout<<"Enter Total Nodes : ";
    cin>>nodes;
    cout<<"nnEnter Adjacency Matrix : n";
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
        cin>>graph[i][j];

    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++)
    {
        if(graph[i][j]==0)
            graph[i][j]=infi;
        }
}
}


void prims :: primsAlgo()
{
    int selected[ROW],i,j,ne; //ne for no. of edges
    int min,x,y;

    for(i=0;i<nodes;i++)
        selected[i]=0;

    selected[0]=1;
    ne=0;

    while(ne < nodes-1)
    {
        min=infi;
        for(i=0;i<nodes;i++)
        {
            if(selected[i]==1){
                for(j=0;j<nodes;j++){
                    if(selected[j]==0){
                        if(min > graph[i][j])
                        {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        selected[y]=1;
        cout<<"n"<<x+1<<" --> "<<y+1;
        ne=ne+1;
    }
}

int main()
{
    prims MST;
    cout<<"nPrims Algorithm to find Minimum Spanning Treen";
    MST.createGraph();
    MST.primsAlgo();
    return 0;
}

