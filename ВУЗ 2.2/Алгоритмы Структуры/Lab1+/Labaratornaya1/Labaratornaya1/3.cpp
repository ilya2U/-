#include <iostream>
#include <string>
#include <set>
using namespace std;

void fillingSet(set<char> & set) {
    int n;

    cout << "Введите количество элементов множества: ";
    cin >> n;
    cout << endl;
    
    cout << "Вводить можно только буквы русского или английского алфавита и цифры." << endl;
    
    for(int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << "-ый элемент множества: ";
        char l;
        cin >> l;
        set.insert(l);
    }
}

void setSeparation(set<char> SetMain, set<char> SetRus, set<char> SetLat, set<char> SetDigits) {
    set<char>::iterator it;
    for(it = SetMain.begin(); it != SetMain.end(); it++) {
        if( isdigit(*it) ) {
            SetDigits.insert(*it);
        }
        else if (*it >= 'A' && *it <= 'Z' || *it >= 'a' && *it <= 'z') {
            SetLat.insert(*it);
        }
        else {
            SetRus.insert(*it);
        }
    }
}

void printSet(set<char> & Set){
    cout << "Количество элементов: " << Set.size() << endl;
    cout << "Множество: ";
    
    set<char>::iterator it;
    for(it = Set.begin(); it != Set.end(); it++) {
        cout << (*it) << " ";
    }
    
    cout << endl;
}

int main() {
    set<char> S;
    fillingSet(S);
    printSet(S);
    
    set<char> A;
    set<char> B;
    set<char> C;
    
    setSeparation(S, A, B, C);
    
    cout << "------------------";
    printSet(A);
    printSet(B);
    printSet(C);
    
    return 0;
}
