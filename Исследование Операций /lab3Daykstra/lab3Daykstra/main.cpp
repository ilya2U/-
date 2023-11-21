#include <iostream>
using namespace std;
 
int main()
{
    int temp;
    int i,j,n; //  n - количество вершин
    int visited[10]; // Временное хранилище
    
    for(i=0;i<10;i++){
        visited[i]=0;}
    
    int minimal[10]; // Временное хранилище
    for(i=0;i<=10;i++)
        minimal[i]=999;
    
    int matrix[10][10];
    cout<<"Введи количество вершин:"; cin>>n;
    cout<<"Введи матрицу смежности:"<<endl;
    int number;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        {
            cin>>matrix[i][j];
                if(matrix[i][j]==0)
                    matrix[i][j]=999; //999 -  бесконечность.
        }
    }
    int minl[10]={0}; // Матрица с каждой вершиной и минимальным расстоянием до другой
    // Первый этап.Расстояния до каждой вершины(доступной)
    cout<<endl<<"Поиска кратчайших путей для вершины:";
    cin>>number;
    cout<<endl;
  
        for(j=1;j<=n;j++)
        {
            if(matrix[number][j]!=999 )
            {
                minl[j]=matrix[number][j];
               
            }
        }
    visited[number]=1;
    cout<<endl;
    for(i=1;i<=n;i++){
        cout<<i<<"->"<<minl[i]<<endl;
    }
   // не достали - 1000 . Достали - поставили вес
            
    //Второй этап.Поиск меньшего расстояния
    
  
    for(int g=0;g<2;g++)
    {
        
        for(j=1;j<=n;j++)
        {
            if(j!=number){
            temp=minl[j];
                for(i=2;i<=n;i++)
                {
                    if(i!=number){
                    if(matrix[j][i]!=999 && (minl[i] > matrix[j][i]+temp) )
                    { minl[i]=matrix[j][i]+temp;
                        cout<<j<<"-"<<i<<"->"<<minl[i]<<endl;
//                        if(visited[i-1]==1 && ( minl[i] > matrix[j][i]+temp) ){}
                    }
                    
                    
                    else if(visited[i-1]==0 && matrix[j][i]!=999 && (minl[i] < matrix[j][i]+temp) && minl[i]!=0)
                    {
                        
                        cout<<j<<"-"<<i<<"->"<<minl[i]<<endl;
                    }
                    
                    else if(visited[i-1]==0 && matrix[j][i]!=999 && (minl[i] < matrix[j][i]+temp) && minl[i]==0)
                    {
                        minl[i]=matrix[j][i]+temp;
                        cout<<j<<"-"<<i<<"->"<<minl[i]<<endl;
                    }
                    
                   

                    
               }
            
         
            visited[j-1]=1;
                }
        }
        }
    }
   
//    cout<<endl;
    for(i=1;i<=n;i++)
    {cout<<minl[i]<<endl;}
    cout<<endl;
    
    return 0;
}
//Проверки
//0 7 9 0 0 14
//7 0 10 15 0 0
//9 10 0 11 0 2
//0 15 11 0 6 0
//0 0 0 6 0 9
//14 0 2 0 9 0
//
//
//0 40 0 0 18
//40 0 22 6 15
//0 22 0 14 0
//0 6 14 0 20
//18 15 0 20 0
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int temp;
//    int copy=0;
//    int i,j,n; //  n - количество вершин
//    int min=999;
//
//    int visited[10]; // Временное хранилище
//    for(i=0;i<10;i++){
//        visited[i]=0;}
//
//    int minimal[10]; // Временное хранилище
//    for(i=0;i<=10;i++)
//        minimal[i]=999;
//
//    int matrix[10][10];
//    cout<<"Введи количество вершин:"; cin>>n;
//    cout<<"Введи матрицу смежности:"<<endl;
//
//    for(i=1;i<=n;i++){
//        for(j=1;j<=n;j++)
//        {
//            cin>>matrix[i][j];
//                if(matrix[i][j]==0)
//                    matrix[i][j]=999; //999 -  бесконечность.
//        }
//    }
//    int minl[10]={0}; // Матрица с каждой вершиной и минимальным расстоянием до другой
//    // Первый этап.Расстояния до каждой вершины(доступной)
//    cout<<endl<<"Поиска кратчайших путей для 1 вершины:"<<endl;
//
//        for(j=2;j<=n;j++)
//        {
//
//            if(matrix[1][j]!=999 )
//            {
//                minl[j]=matrix[1][j];
//                minimal[j]=minl[j];
//            }
//        }
//    visited[0]=1;
//    cout<<endl;
//    for(i=1;i<=n;i++){
//        cout<<i<<"->"<<minl[i]<<endl;
//    }
//   // не достали - 1000 . Достали - поставили вес
//
//    //Второй этап.Поиск меньшего расстояния
//    for(j=2;j<=n;j++)
//    {
//        temp=minl[j];
//            for(i=2;i<=n;i++)
//            {
//
//                if(matrix[j][i]!=999 && (minl[i] >= matrix[j][i]+temp) )
//                { minl[i]=matrix[j][i]+temp;
//                    cout<<j<<"-"<<i<<"->"<<minl[i]<<endl;
//                }
//
//                else if(visited[i]==0 && matrix[j][i]!=999 && (minl[i] < matrix[j][i]+temp) && minl[i]!=0)
//                {
//
//                    cout<<j<<"-"<<i<<"->"<<minl[i]<<endl;
//                }
//
//                else if(visited[i]==0 && matrix[j][i]!=999 && (minl[i] < matrix[j][i]+temp) && minl[i]==0)
//                {
//                    minl[i]=matrix[j][i]+temp;
//                    cout<<j<<"-"<<i<<"->"<<minl[i]<<endl;
//                }
//
//
//
//    }
//
//        visited[j-1]=1;
//}
//
//
//    cout<<endl;
//    for(i=1;i<=n;i++)
//    {cout<<minl[i]<<endl;}
//    cout<<endl;
//
//    return 0;
//}
