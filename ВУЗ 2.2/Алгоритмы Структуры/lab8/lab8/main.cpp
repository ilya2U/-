#include <iostream>
using namespace std;


template<typename T>
struct node{
public:
    node(T value){
        this->value = value;
    }

    node<T>* next;
    node<T>* prev;

    T value;
};

template<typename T>
struct List {
public:
    
//    virtual bool isEmpty(T value) {}
    virtual void insert(T value, int position) {}
    virtual void push_back(T value) {}
    virtual void push_front(T value) {}

    virtual void remove(int position) {};

    virtual void clear(){};

    virtual void print(){};
};

template<typename T>
class PtrList : List<T>{
public:
    node<T> *head = NULL;
    node<T> *tail = NULL;

    int elementsCount = 0;

    bool isEmpty(){
        if(head == tail && head == NULL){
            return true;
        }
        return false;
    }

    void push_back(T value) override{

        if(elementsCount == 0){
            this->head = new node<T>(value);
            this->head->next = NULL;
            this->head->prev = NULL;


            this->tail = this->head;
            elementsCount++;
            return;
        }

        node<T>* tmpNode = this->tail;
        tmpNode->next = NULL;
        tmpNode->prev = this->tail;

        this->tail = tmpNode;

        elementsCount++;

    }

    void push_front(T value) override{

        if(elementsCount == 0){
            this->head = new node<T>(value);
            this->head->next = NULL;
            this->head->prev = NULL;


            this->tail = this->head;
            elementsCount++;
            return;
        }

        node<T>* tmpNode = new node<T>(value);
        tmpNode->next = this->head;
        tmpNode->prev = NULL;
        this->head->prev = tmpNode;
        this->head = tmpNode;

        elementsCount++;

    }

    void remove(int position) override{

        if(position == 0) {
            this->pop_front();
            return;
        }
        if(position == elementsCount - 1) {
            this->pop_back();
            return;
        }

        node<T>* tmpNode = head;
        for(int i = 0; i < position; ++i){
            tmpNode = tmpNode->next;
        }

        node<T>* toDelete = tmpNode;
        toDelete->next->prev = toDelete->prev;
        toDelete->prev->next = toDelete->next;

        free(toDelete);
        elementsCount--;
    }

    void pop_front(){

        if(elementsCount == 1){
            free(head);
            head = NULL;
            tail = NULL;
            elementsCount--;
            return;
        }

        node<T>* nextNode = head->next;
        free(head);
        head = nextNode;
        head->prev = NULL;
        elementsCount--;
    }

    void pop_back(){

        if(elementsCount == 1){
            free(head);
            head = NULL;
            tail = NULL;
            elementsCount--;
            return;
        }

        node<T>* toDelete = this->tail;
        toDelete->prev->next = NULL;
        this->tail = toDelete->prev;
        free(toDelete);

    }

    void insert(int position, T value) override{

        if(position == 0){
            push_back(value);
        }

        node<T>* tmpNode = head;
        for(int i = 0; i < position; i++){
            tmpNode = tmpNode->next;
        }

        node<T>* newNode = new node<T>(value);
        newNode->next = tmpNode;
        newNode->prev = tmpNode->prev;
        tmpNode->prev->next = newNode;
        tmpNode->prev = newNode;

        elementsCount++;
    }

    void clear() override{
        while(!isEmpty()){
            this->pop_front();
        }
    }
    void print() override{
        std::cout << "ELEMENTS: ";
        node<T>* currentNode = this->head;
        for (int i = 0; i < elementsCount; ++i){
            std::cout << currentNode->value << ' ';
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
};

template<typename T>
class ArrayList : List<T> {
public:

    ArrayList(int size){
        this->size = size;
        this->data = new T[size];
    }

    bool isEmpty() {
        if(elementsCount == 0){
            return true;
        }
        return false;
    }

    void push_back(T value) override{

        elementsCount++;
        data[endPos] = value;
        endPos++;

    }

    void push_front(T value) override{

        for(int i = endPos; i >= startPos; i--){
            data[i+1] = data[i];
            swapCount++;
        }

        data[startPos] = value;
        elementsCount++;
        endPos++;

    }

    void remove(int position) override{
        T out = data[position];

        for(int i = position; i <= endPos; i++){
            data[i] = data[i+1];
            swapCount++;
        }

        elementsCount--;
        endPos--;

    }

    void clear() override{
        while(!isEmpty()){
            this->remove(0);
        }
    }

    void insert(int position, T value) override{
        for(int i = endPos; i >= position; i--){
            data[i+1] = data[i];
            swapCount++;
        }
        endPos++;
        elementsCount++;
        data[position] = value;
    }

    void print() override{
        std::cout << "ELEMENTS: ";
        for (int i = startPos; i < elementsCount; ++i){
            std::cout << data[i] << ' ';
        }
        std::cout << std::endl;
    }

    int elementsCount = 0;
    int swapCount = 0;

private:
    int size = 0;
    int startPos = 0;
    int endPos = 0;

    T* data;
};



int main() {
    
            PtrList<int> list;
            for (int i = 0; i < 10; i++) {
                list.push_front(i);
            }
//            list.print();
//            list.remove(4);
//
//    list.push_front(96);
//            list.print();
//            list.insert(4, 9);
//            list.print();
//            list.clear();
//            std::cout << list.isEmpty() << std::endl;
//            list.print();
            
            
            ArrayList<int> list2(0);
            for (int i = 0; i < 10; i++) {
                list2.push_front(i);
            }
//            list2.print();
//            list2.remove(2);
//    list2.push_back(69);
//    list2.push_front(96);
//            list2.print();
//            list2.insert(2, 55);
//            list2.print();
//            list2.clear();
//            std::cout << list2.isEmpty() << std::endl;
//            list2.print();
        
//            std::cout<<"Cчетчик насчитал: " << list2.swapCount << std::endl;
        
            bool works = true;
            bool wtime = true;
            int answer1=0;
            int answer2=0;
            while(works==true) {
                cout <<
                "\nВыберете способ представления линейного списка"
                "\n\t1. Сплошное представление"
                "\n\t2. Цепное представление"
                "\n\t3. Выйти" << endl;
                int answer; cout << "> "; cin >> answer;
                if (answer == 1 || answer == 2) {
                    cout <<
                    "\n\t1. Вывести"
                    "\n\t2. Добавить вперед"
                    "\n\t3. Поместить"
                    "\n\t4. Очистить"
                    "\n\t5. Удалить"
                    "\n\t6. Выйти"<< endl;

                    if (answer == 1) {

                        while(answer1!=6){
                            cout << "> "; cin >> answer1;
                           if(answer1==5){
                                int buff;
                                cout<<"Выберите элемент для удаления:";
                                cin>>buff;
                                cout<<endl;
                               list.remove(buff);
                               }
                            else if (answer1 == 3){
                                int buff;int puff;
                                cout<<"Куда ";
                                cin>>buff;
                                cout<<"Что ";
                                cin>>puff;
                                cout<<endl;
                                list.insert(buff,puff);
                                }
                            else if (answer1 == 4){ list.clear(); }
                            else if (answer1 == 1){ list.print(); }
                            else if (answer1 == 2){
                                int buff;
                                cout<<"Введите значение:";
                                cin>>buff;
                                cout<<endl;
                                list.push_front(buff); }

                            }
                        }
                    }

        if (answer == 2) {
                    while(answer2!=6){
                        cout << "> "; cin >> answer2;
                       if(answer2==5){
                            int buff;
                            cout<<"Выберите элемент для удаления (от 1):";
                            cin>>buff;
                            cout<<endl;
                           list2.remove(buff - 1);
                           }
                        else if (answer2 == 3){
                            int buff;int puff;
                            cout<<"Куда ";
                            cin>>buff;
                            cout<<"Что ";
                            cin>>puff;
                            cout<<endl;
                            list2.insert(buff,puff);
                            }
                        else if (answer2 == 4){ list2.clear(); }
                        else if (answer2 == 1){ list2.print(); }
                        else if (answer2 == 6){break;}
                        
                      
                        else if (answer2 == 2){
                            int buff;
                            cout<<"Введите значение:";
                            cin>>buff;
                            cout<<endl;
                            list2.push_front(buff); }
                        else if (answer2 == 0){
                            int buff;
                            cout<<"Введите значение:";
                            cin>>buff;
                            cout<<endl;
                            list2.push_back(buff); }
                        }
                    }
                if (answer == 3){works=false;}
                }





    

    return 0;
}


