#include<iostream>
#include<queue>
using namespace std;

int main()
{
    
    int n;
    int temp;
    cout<<"Введи количество вершин:"; cin>>n;
    int gr[n][n];
    queue<int> q[n];
    int sum;
cout<<"Введите матрицу смежности:"<<endl;
    int used[99]={0};
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
    cin>>gr[i][j];
}
int number;
cout<<"Выберите вершину:";
cin>>number;
used[number+1]=1;
    int z=1;
for(int j=1;j<=n;j++)
    {
        if(gr[number][j]!=0)
        {
            q[z].push(j);
            
            cout<<"Оч 1 ->"<<j<<endl;
            used[j]=1;
            for(int m=1;m<=n;m++)
            {
                gr[m][j]=0;
                gr[m][number]=0;
            }
        }
    }
z=z+1;
    while(z<100){
for(int i=1;i<=n;i++)
 {
     temp=0;
    if(i!=number && used[i]==1)
    for(int j=1;j<=n;j++)
    {
        if(gr[i][j]!=0 && used[j]!=1)
        {
            used[j]=1;
            q[z].push(j);
            cout<<"Оч "<<z<<" ->"<<j<<endl;
            for(int m=1;m<=n;m++)
            {
                gr[m][j]=0;
            }
        }
        if(gr[i][j]==0){
            temp++;
    }
 }
        for(int k=1;k<=n;k++){
            sum=used[k]+sum;
        }
        if (sum==n)break;
     
     
    }
    //Малой связанности
    
    
    
    
    
    return 0;
}
//0 7 9 0 0 14
//7 0 10 15 0 0
//9 10 0 11 0 2
//0 15 11 0 6 0
//0 0 0 6 0 9
//14 0 2 0 9 0

//0 7 9 0 0 14
//7 0 10 15 0 0
//9 10 0 11 0 2
//0 15 11 0 6 0
//0 0 0 6 0 9
//14 0 2 0 9 0
