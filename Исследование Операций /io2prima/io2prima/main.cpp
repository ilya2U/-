#include<iostream>
using namespace std;


int main()
{
    int a,b,u,v,n,ne=1;
    int visited[10]={0},min,mincost=0,cost[10][10];

    int path[100]={0}; //В этот массив будут записываться вершины, по которым составиться путь
    int path_index=0;

    
    cout<<"Введи количество вершин:"; cin>>n;
    cout<<"Введи матрицу смежности:"<<endl;
  
    int i,j=1;

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        cin>>cost[i][j];
        if(cost[i][j]==0)
            cost[i][j]=999; //999 -  бесконечности. 
    }
    visited[1]=1;
    cout<<"\n";

    while(ne < n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]< min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                        
                    }
                }
             }
        }
                    
    if(visited[u]==0 || visited[v]==0)
    {
        
        path[path_index]=b;
        path_index++;
        ne++;
        mincost+=min;
        visited[b]=1;

    }
                cost[a][b]=cost[b][a]=999;
}


    cout<<"\n";

    cout<<1<<" --> ";
    for (int i=0;i<n-1;i++)
    {
      cout<<path[i];
      if (i<n-2) cout<<" --> ";
    }

    cout<<"\n Минимальная стоимость  "<<mincost<<endl;


    cin.get();
    cin.get();
}
