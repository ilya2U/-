
#include <iostream>
using namespace std;
#include <string>
#include <set>
 
void FillingA(set<int> & set){
    int n;
    int l;
    cout<<"Введите количество элементов множества:";
    cin>>n;cout<<endl;
    
    for(int i=0; i<n; i++){
        cin>>l;
        set.insert(l);
        l=0;}
}

void ShowOutBunch(set<int> & Set){
    cout<<"Количество элементов: "<<Set.size()<<endl;
    cout<<"Множество: ";
    set<int>::iterator it; //создание итератора
     for(it = Set.begin(); it != Set.end(); it++) { // Вывод всех элементов
     cout << (*it);// множества
     cout<<" ";
     }

 
     cout << endl;
}
void zxc(string first, string second,set<string> & Set1, set<string> &Set2){
    string copy;
    cout<<"Введите первое предложение: ";
    getline(cin, first);
    
    cout<<"Введите второе предложение: ";
    getline(cin, second);
    cout<<endl;
    
    for(int i=0;i < first.length() ; i++){
        if(first[i]==' ' || first[i]==',' )
           {
               
               Set1.insert(copy);
               copy="";
           }
       
        else{
            copy=copy+first[i];
        }
        
        if(i+1==first.length()){
            Set1.insert(copy);
            copy="";
        }
    }
    
    for(int i=0;i < second.length() ; i++){
        if(second[i]==' ' || second[i]==',' )
           {
               
               Set2.insert(copy);
               copy="";
           }
       
        else{
            copy=copy+second[i];
        }
        
        if(i+1==second.length()){
            Set2.insert(copy);
            copy="";
        }
    }
}

void ShowOutBunchS(set<string> & Set){
    cout<<"Количество элементов: "<<Set.size()<<endl;
    cout<<"Множество: ";
    set<string>::iterator it; //создание итератора
     for(it = Set.begin(); it != Set.end(); it++) { // Вывод всех элементов
     cout << (*it);// множества
     cout<<" ";
     }

 
     cout << endl << endl;
}

int counter(set<string> & Set1, set<string> & Set2) {
    set<string>::iterator it;
    int count = 0;
    for(it = Set1.begin(); it != Set1.end(); it++) {
        if(Set2.find(*it) != Set2.end()) {
            count++;
        }
    }
    
//    string arr[count - 1];
//    int i = 0;
//    for(it = Set1.begin(); it != Set1.end(); it++) {
//        if(Set2.find(*it) != Set2.end()) {
//            arr[i] = *it;
//            i++;
//        }
//    }
    
    return count;
}

void setComparison(set<string> & Set1, set<string> & Set2, string arr[]) {
    int i = 0;
    set<string>::iterator it;
    for(it = Set1.begin(); it != Set1.end(); it++) {
        if(Set2.find(*it) != Set2.end()) {
            arr[i] = *it;
            i++;
        }
    }
}

void printArray(string arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << i + 1 << "-ый элемент массива: " << arr[i] << endl;
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    set<int> A;
    FillingA(A);
    ShowOutBunch(A);
    
//    set<string> B;
//    set<string> C;
//    string first;
//    string second;
//
//    zxc(first,second,B,C);
//    ShowOutBunchS(B);
//    ShowOutBunchS(C);
//
//    int n = counter(B, C);
//    string array[n - 1];
//    setComparison(B, C, array);
//    cout<<endl;
//    printArray(array, n);
    
    return 0;
}
