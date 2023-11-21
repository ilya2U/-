#include <iostream>
#include <stack>
#define NODE 5
using namespace std;

int graph[NODE][NODE] = {
   {0, 1, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {1, 0, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 0, 1, 0}
};
                               
int transGraph[NODE][NODE];

void transpose() {    //транспонирование графа
   for(int i = 0; i<NODE; i++)
      for(int j = 0; j<NODE; j++)
         transGraph[i][j] = graph[j][i];
}
         
void traverse(int g[NODE][NODE], int u, bool visited[]) {
   visited[u] = true;    //v отмечаем посещенным
   cout << u << " ";

   for(int v = 0; v<NODE; v++) {
      if(g[u][v]) {
         if(!visited[v])
            traverse(g, v, visited);
      }
   }
}
                                               
void topoSort(int u, bool visited[], stack<int>&stk) {
   visited[u] = true;    //тру при посещении узла v

   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {    //для всех вершин v, смежных с u
         if(!visited[v])
            topoSort(v, visited, stk);
      }
   }

   stk.push(u);    //поместить начальную вершину в стек
}

void getStrongConComponents() {
   stack<int> stk;
   bool vis[NODE];

   for(int i = 0; i<NODE; i++)
      vis[i] = false;    //изначально все узлы не посещаются
   
   for(int i = 0; i<NODE; i++)
      if(!vis[i])    //когда узел не посещается
         topoSort(i, vis, stk);
   
   for(int i = 0; i<NODE; i++)
      vis[i] = false;    //false, чтобы все узлы не посещались для обхода
   transpose();    //построить обратный граф
   
   while(!stk.empty()) {    //когда стек содержит элемент, обрабатывать в топологическом порядке
      int v = stk.top(); stk.pop();
      if(!vis[v]) {
         traverse(transGraph, v, vis);
         cout << endl;
      }
   }
}

int main() {
   cout << "Компоненты сильной связанности: "<<endl;
   getStrongConComponents();
}
//#include <iostream>
//#include <list>
//#include <stack>
//using namespace std;
//class G {
//   int m;
//   list<int> *adj;
//   //объявление функций
//   void fillOrder(int n, bool visited[], stack<int> &Stack);
//   void DFS(int n, bool visited[]);
//   public:
//   G(int N); //конструктор
//   void addEd(int v, int w);
//   int print();
//   G getTranspose();
//};
//G::G(int m) {
//   this->m = m;
//   adj = new list<int> [m];
//}
//void G::DFS(int n, bool visited[]) {
//   visited[n] = true; // Отметить  текущий узел как посещенный и вывести его
//   cout << n << " ";
//   list<int>::iterator i;
//   //Повторить для всех вершин, смежных с этой вершиной
//   for (i = adj[n].begin(); i != adj[n].end(); ++i)
//      if (!visited[*i])
//         DFS(*i, visited);
//}
//G G::getTranspose() {
//   G g(m);
//   for (int n = 0; n< m; n++) {
//      list<int>::iterator i;
//      for (i = adj[n].begin(); i != adj[n].end(); ++i) {
//         g.adj[*i].push_back(n);
//      }
//   }
//   return g;
//}
//void G::addEd(int v, int w) {
//   adj[v].push_back(w); //добавить w в v's list
//}
//void G::fillOrder(int v, bool visited[], stack<int> &Stack) {
//   visited[v] = true; // Отметить  текущий узел как посещенный и вывести его
//   list<int>::iterator i;
//   //Повторить для всех вершин, смежных с этой вершиной
//   for (i = adj[v].begin(); i != adj[v].end(); ++i)
//      if (!visited[*i])
//         fillOrder(*i, visited, Stack);
//   Stack.push(v);
//}
//int G::print() { //вывести решение
//   stack<int> Stack;
//   bool *visited = new bool[m];
//   for (int i = 0; i < m; i++)
//      visited[i] = false;
//   for (int i = 0; i < m; i++)
//      if (visited[i] == false)
//         fillOrder(i, visited, Stack);
//   G graph= getTranspose(); //Создание транспонированного графа
//   for (int i = 0; i < m; i++)//Отметить все вершины как не посещенные
//      visited[i] = false;
//   int count = 0;
//   //теперь обработайте все вершины в порядке, определенном стеком
//   while (Stack.empty() == false) {
//      int v = Stack.top();
//      Stack.pop(); //извлечь вершину из стека
//      if (visited[v] == false) {
//         graph.DFS(v, visited);
//         cout << endl;
//      }
//      count++;
//   }
//   return count;
//}
//int main() {
//    G g(5);
//      g.addEd(0, 1);
//      g.addEd(1, 1);
//      g.addEd(2, 2);
//      g.addEd(3, 1);
//    g.addEd(4, 0);
//   cout << "Компоненты:\n";
//   if (g.print() > 1) {
//      cout << "Граф мало связан."<<endl;
//   } else {
//      cout << "Граф сильно связанный."<<endl;
//   }
//   return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//
//int main() {
//    int n;
//    int gr[n][n];
//    cout<<"Введи количество вершин:"; cin>>n;
//    cout<<"Введи матрицу смежности:"<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            cin>>gr[i][j];
//                if(gr[i][j]==0)
//                    gr[i][j]=999; //999 -  бесконечность.
//        }
//    }
//
//
//}
