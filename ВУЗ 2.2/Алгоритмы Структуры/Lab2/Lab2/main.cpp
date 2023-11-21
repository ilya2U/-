#include <vector>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>
 

using namespace std;


//int FindStroke(string word, vector<string> str_list) {
//    int wordcount = 0;
//    for (int i = 0; i < str_list.size(); i++) {
//        //wordcount = 0;
//        int check = 0;
//        int pos = 0;
//        while (check != -1) {
//            if (str_list[i].find(word, pos) != -1) {
//                int pos_temp = (int)(str_list[i].find(word, pos));
//                
//                pos = (int)(str_list[i].find(word, pos) + 1);
//                wordcount++;
//            }
//            else {
//                check = -1;
//            }
//
//        }
//    }
//    return wordcount;
//}
void task12(){
    string path1 = "/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/myfile.txt";
    ofstream fout1;
    fout1.open(path1);
    int counter=0;
    int n;
        cout<<"Введите количество чисел:";
            cin>>n;
                cout <<endl;
    double *mas=new double[n];
    if( !fout1.is_open() ) {
        cout << "Ошибка открытия файла!" << endl;
            }
                else {
                        for (int i=0; i < n; i++) {
                                mas[i] = -50 + rand() % 100;
                                if(mas[i]<0){counter++;}
                                fout1 << mas[i];
                                fout1 << " ";
                                }
                            }
    int abs;
    abs=rand()% n*2;
    fout1.seekp(abs); //обращается к определенному символу файла
    fout1.put('I');
    cout<<"Колличество отрицательных элементов:"<<counter<<endl;
    fout1.close();
//    fout1.seekp(rand()% n*2); //обращается к определенному символу файла
//    fout1.put('I');
//    cout<<"Колличество отрицательных элементов:"<<counter<<endl;
//    fout1.close();
    
}

//void task3(){
//    string path2="/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/notfile.txt";
//    ifstream fin(path2);
//    size_t b;
//    cout << "Введите номер строки:";
//    cin>>b;
//    cout<<endl;
//    size_t count = 1;
//    string buff;
//    while(true){
//        if(!fin){
//            cout << "Количество строк меньше числа которое вы ввели" << endl;
//            break;
//        }
//
//        getline(fin, buff);
//
//        if(count == b){
//            if(buff.length() == 0){
//                cout << "Это пустая строка" << endl;
//            }
//            cout << buff;
//            break;
//        }
//        count++;
//    }
//    cout << endl;
//
//    }
//
//void task4(){
//    string *mas=new string[100];
//    char *str = new char [1024];
//       int i=0;
//       ifstream base("/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/notfile.txt");
//       while (!base.eof())
//       {
//           base.getline(str, 1024, '\n');
//           mas[i]=str;
//
//           i++;
//       }
//       base.close();
//    string slovo;
//    cout<<"Введите слово:";
//    cin>>slovo;
//    cout<<endl;
//    int pos;
//    for(int z=0 ;z<i;z++){
//        string copy=mas[z];
//        if(copy.find(slovo) != -1) {
//            pos=copy.find(slovo);
//            cout<<"Слово находится в "<<z+1<<" строке "<<pos<<" элементом";
//        }
//        cout<<endl;
//
//
//    }
    
//          string a = "сеносеносеноиголкасеносеносеносено";
//          p = a.find("иголка");
//          cout << p << endl;
//}
//template <class T>
//int getBinaryFileLengthAs(string fileName) {
//    ifstream rf(fileName);
//    rf.seekg(0, ios::end);
//    int fsize = rf.tellg() / sizeof(T);
//    return fsize;
//}

//void task4() {
//    string fileName = "notfile.txt";
//    set<pair<size_t, size_t>> point;
//    string substring;
//    cout << "Введите искомую подстроку: ";
//    getline(cin, substring);
//
//    int substrCounter = 0;
//    ifstream rf(fileName, ios::binary);
//    char *letter = new char[1];
//    char *potentialSubstr = new char[substring.length()];
//    size_t posLine = 0, posRow = 0;
//
//    for(int i = 0; i < getBinaryFileLengthAs<char>(fileName) - substring.length() + 1; i++) {
//        rf.read(potentialSubstr, substring.size());
//        rf.seekg(-substring.length() * sizeof(char), ios::cur);
//        if(potentialSubstr == substring) {
//            point.insert(pair<size_t, size_t>(posRow, posLine));
//            substrCounter++;
//        }
//
//        rf.read(letter, sizeof(char));
//        if(*letter == '\n') {
//            posRow++;
//            posLine = 0;
//        };
//        posLine++;
//    }
//    if(substrCounter == 0) cout << "Такой подстроки нет в исходном файле\n";
//    rf.close();
//    for (auto it = point.begin(); it != point.end(); it++) {
//        cout << "(строка: " << it->first << " номер: " << it->second << ") ";
//    }
//}
//
void task5(){
    ifstream fin("/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/text.txt");
    int count = 0;
    map<string, size_t> wordsCount;
    map<string, size_t> :: iterator it;
    string buff;
    while (fin){
        getline(fin, buff);
        stringstream ss;
        ss = stringstream(buff);
        while (ss){
            string word;
            ss >> word;
            wordsCount[word];             //wordsCount[word]++
            it = wordsCount.find(word);//
            it++;                         //
        }
    }
    int i = 0;
    for (auto it = wordsCount.begin(); it != wordsCount.end(); it++){
        if(it->second > 1 && i!=0) {
            cout << "Слово '" << it->first << "' найдено " << it->second << " раз" << endl;
            count++;
        }else{
            i=1;
        }
    }
    int unique = wordsCount.size() - count;
    cout << "Количество уникальных слов: " << unique<<endl;
   }
//void task5(){
//    fstream fin("/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/notfile.txt");
//    int k;
//    vector<std::string> A;
//    while(!fin.eof())
//    {
//    string a, b;
//    getline(fin, a);
//    a = a + ' ';
//    k = 0;
//    for (int i = 0; i < a.length(); i++)
//    {
//    k++;
//    if (isalpha(a[i])) b += a[i];
//    if (a[i] == ' ')
//    {
//    k--;
//    A.push_back(b);
//    k = 0;
//    b = "";
//    }
//    }
//    }
//    fin.close();
//    cout << "Уникальные слова в файле:" << endl;
//    for (int i = 0; i < A.size(); i++)
//    {
//    k = 0;
//    for (int j = 0; j < A.size(); j++)
//    {
//    if (A[i] == A[j]) k++;
//    }
//    if (k == 1)
//    {
//    cout << A[i] << endl;
//    }
//    }
//}
void task53(){
    ifstream fin("/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/notfile1.txt");
       string s,sr;
       char a[9]={'.' , ',' , ':' , ';' , '!' , '?' , '-' , '"' , ' '};
       bool f=true;
       while(getline(fin,s))
       {
           sr="";
           for(int i=0;i<s.length();++i)
           {
               for(int j=0;j<9;j++)
               {
                   if(s[i]==a[j])
                   {
                       f=false;
                       break;
                   }
               }
               if(f)
               {
                   sr=sr+s[i];
               }
               f=true;
           }
       cout<<sr<<endl;
       }
}



void task52() {
    ifstream fin;
    fin.open("/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/notfile1.txt");
    if (!fin) {
        cout << "file not found! " << endl;
        exit(1);
    }
    int iter = 0;
    int count = 0;
    int unicCount = 0;

    string substr;
    string str_temp;
    vector<string> str_list;
    vector<string> word_list;
    vector<string> unicWord_list;
    while (getline(fin, str_temp)) {
        istringstream iss(str_temp);
        str_list.push_back(str_temp);
    }
    for (auto& elem : str_list) {
        istringstream iss(elem);
        while (iss >> str_temp) {
            word_list.push_back(str_temp);
        }
    }

    cout << "all words: " << endl;
    for (int i = 0; i < word_list.size(); i++) {
        int count = FindStroke(word_list[i], str_list);
        cout << word_list[i] << ":\t" << count << " times" << endl;
        if ((count == 1) || (word_list[i]!="}")) {
            unicWord_list.push_back(word_list[i]);
        }
    }

    for (auto& elem : unicWord_list) {
        count++;
    }
    cout << endl << count << endl;
    auto& fin1 = fin;

}


int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "ru");
    
    
    
 
  task12();
 // task3();
 //task4();
    task5();
    task52();
    task53();

    return 0;
}
  
//
//void task12(){
//    string path1 = "/Users/androsovilya/Desktop/Алгоритмы Структуры/Lab2/Lab2/myfile.txt";
//    ofstream fout1;
//    fout1.open(path1);
//    int counter=0;
//    int n;
//        cout<<"Введите количество чисел:";
//            cin>>n;
//                cout <<endl;
//    double *mas=new double[n];
//    if( !fout1.is_open() ) {
//        cout << "Ошибка открытия файла!" << endl;
//            }
//                else {
//                        for (int i=0; i < n; i++) {
//                                mas[i] = -50 + rand() % 100;
//                                if(mas[i]<0){counter++;}
//                                fout1 << mas[i];
//                                fout1 << " ";
//                                }
//                            }
//    fout1.seekp(rand()% n*2); //обращается к определенному символу файла
//    fout1.put('I');
//    cout<<"Колличество отрицательных элементов:"<<counter<<endl;
//    fout1.close();
//
//}
