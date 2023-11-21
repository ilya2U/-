#include <iostream>
#include "Queue.h"
#include "SplashQueue.h"

using namespace std;


template<class T>
void workSplash (SplashQueue<T> & spl) {
    int answer = 0;
    while (answer != 5) {
        cout << "\n1. Добавить элемент"
                "\n2. Удалить элемент"
                "\n3. Очистить"
                "\n4. Просмотреть очередь"
                "\n5. Выйти" << endl;
        cout << "> "; cin >> answer;
        if (answer == 1) {
            T value;
            cout << "\nВведите элемент: "; cin >> value;
            spl.push(value);
        }
        else if (answer == 2) spl.pop();
        else if (answer == 3) spl.clear();
        else if (answer == 4) {
            cout << '\n';
            cout << "Ваша очередь: "; spl.print();
            cout << '\n' << '\n';
        }
        else if (answer == 5) { break; }
        else cout << "\n-----Такого пункта нет!-----\n";
    }
}

template <class T>
void workWithStackPtr (Queue<T>& stl) {
    int answer = 0;
    while (answer != 5) {
        cout << "\n1. Добавить элемент"
                "\n2. Удалить элемент"
                "\n3. Очистить"
                "\n4. Просмотреть очередь"
                "\n5. Выйти" << endl;
        cout << "> "; cin >> answer;
        if (answer == 1) {
            T value;
            cout << "\nВведите элемент: "; cin >> value;
            stl.push(value);
        }
        else if (answer == 2) stl.pop();
        else if (answer == 3) stl.clear();
        else if (answer == 4) {
            cout << '\n';
            cout << "Ваша очередь: "; stl.print();
            cout << '\n' << '\n';
        }
        else if (answer == 5) { break; }
        else cout << "\n-----Такого пункта нет!-----\n";
    }
}

void start() {
    bool works = true;
    while(works) {
        cout <<
             "\nВыберете способ представления очереди"
             "\n\t1. Сплошной"
             "\n\t2. Цепной"
             "\n\t3. Выйти" << endl;
        int answer; cout << "> "; cin >> answer;
        if (answer == 1 || answer == 2) {
            if (answer == 1) {
                int size;
                cout << "Укажите размер очереди: "; cin >> size;
                SplashQueue<int> spl(size);
                workSplash(spl);
            } else if (answer == 2) {
                Queue<int> stl;
                workWithStackPtr(stl);
            }
        }
        else if (answer == 3) works = false;
        else cout << "\n-----Такого пункта нет!-----\n";
    }
}

int main() {

    start();

//    lq.print();
}
