#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <time.h>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

template <class T>
int getBinaryFileLengthAs(string fileName) {
    ifstream rf(fileName, ios::binary);
    rf.seekg(0, ios::end);
    int fsize = rf.tellg() / sizeof(T);
    return fsize;
}

void printBinaryFileAsChars(string fileName) {
    cout <<"Имя файла:"<< fileName << ":\n";
    ifstream rf(fileName, ios::binary);
    char *letter = new char[1];
    for(int i = 0; i < getBinaryFileLengthAs<char>(fileName); i++) {
        rf.read(letter, sizeof(char));
        cout << letter;
    }
    cout << endl;
    rf.close();
}

string writeFileToTempAsChars(string fileName) {
    ifstream rf(fileName, ios::binary);
    ofstream wf("/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/temp.txt", ios::binary);
    char *letter = new char[1];
    for(int i = 0; i < getBinaryFileLengthAs<char>(fileName); i++) {
        rf.read(letter, sizeof(char));
        wf.write(letter, sizeof(char));
    }
    rf.close();
    wf.close();

    return "/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/temp.txt";
}



void task2() {
    ifstream fin;
    string temp;
    int i;
    fin.open("/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/notfile.txt");
    getline(fin,temp);
    do{
        cin>>i;
    }
    while(i > temp.size() + 1);
    temp.insert(temp.begin()+i,'#');
    fin.close();
    ofstream fout;
    fout.open("/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/temp.txt");
    fout<<temp;
    fout.close();
}

int getIndex(vector<string> words, string word) {
    for(int i = 0; i < words.size(); i++) {
        if(words[i] == word) return i;
    }
    return -1;
}

template <class T>
bool hasElem(vector<T> vect, T elem) {
    for(int i = 0; i < vect.size(); i++) {
        if (vect[i] == elem) return true;
    }
    return false;
}


void task5() {
    string fileName = "/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/temp.txt";
    printBinaryFileAsChars(fileName);

    ifstream rf(fileName, ios::binary);
    vector<string> uniqueWords;
    vector<int> repeats;
    string word = "";
    char *letter = new char[1];
    int wordIndex;
    for(int i = 0; i < getBinaryFileLengthAs<char>(fileName); i++) {
        rf.read(letter, sizeof(char));
        if(*letter == ' ' || *letter == '\n') {
            wordIndex = getIndex(uniqueWords, word);
            if(hasElem(uniqueWords, word)) {
                repeats[wordIndex]++;
            }
            else {
                uniqueWords.push_back(word);
                repeats.resize(uniqueWords.size());
                repeats[repeats.size() - 1] = 1;
            }
            word = "";
        }
        else {
            word += *letter;
        }
    }

    for(int i = 0; i < uniqueWords.size(); i++) {
        cout << "   word: " << uniqueWords[i] << endl;
        cout << "repeats: " << repeats[i] << endl;
    }
    cout << "Total unique words: " << uniqueWords.size() << endl;
    rf.close();
}

void task5_3() {
    string fileName = "/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/notfile.txt";
    string tempFileName = "/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/temp.txt";
    printBinaryFileAsChars(fileName);

    ifstream rf(fileName, ios::binary);
    ofstream wf(tempFileName, ios::binary);
    char *letter = new char[1];
    string punctuation = ",.?!-;:";
    for(int i = 0; i < getBinaryFileLengthAs<char>(fileName); i++) {
        rf.read(letter, sizeof(char));
        if(punctuation.find(*letter) == string::npos) {
            wf.write(letter, sizeof(char));
        }
    }
    rf.close();
    wf.close();

    printBinaryFileAsChars("/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/temp.txt");
//    remove("/Users/androsovilya/Desktop/Алгоритмы Структуры/lab2Final/lab2Final/temp.txt");
}

int main() {
    setlocale(LC_ALL, "");
    srand((unsigned)time(0));


//  task2();
  
    task5_3();
    task5();
    return 0;
}
