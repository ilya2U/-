#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#pragma once
using namespace std;

vector<string> insertTextVector() {
    cout << "Insert text (max - 50 str): " << endl;
    cout << "to stop insert \"st0p\" " << endl;
    string str;
    vector<string> str_text;
    while (str != "st0p") {
        getline(cin, str);
        str_text.push_back(str);
    }
    auto iter = str_text.cend() - 1;
    str_text.erase(iter);
    return str_text;
}
int FindStroke(string word, vector<string> str_list) {
    int wordcount = 0;
    for (int i = 0; i < str_list.size(); i++) {
        //wordcount = 0;
        int check = 0;
        int pos = 0;
        while (check != -1) {

            if (str_list[i].find(word, pos) != -1) {
                int pos_temp = (int)(str_list[i].find(word, pos));

                pos = (int)(str_list[i].find(word, pos) + 1);
                wordcount++;
            }
            else {
                check = -1;
            }

        }
    }
    return wordcount;
}
void Split(vector<string> str) {

}
void FindUnicWords(ifstream& fin) {
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
    for (int i = 0; i < word_list.size(); i++) {
        int count = FindStroke(word_list[i], str_list);
        if ((count == 1) || (word_list[i]!="}")) {
            unicWord_list.push_back(word_list[i]);
        }
    }

    for (auto& elem : unicWord_list) {
        count++;
    }
    cout << count << endl;
}
void FindAllWords(ifstream& fin) {
    if (!fin) {
        cout << "file not found! " << endl;
        exit(1);
    }
    int iter = 0;
    int count = 0;

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
    for (int i = 0; i < word_list.size(); i++) {
        int count = FindStroke(word_list[i], str_list);
        cout << word_list[i] << ":\t" << count << " times" << endl;
    }
}
vector<string> DeletePunc(ifstream& fin) {
    if (!fin) {
        cout << "file not found! " << endl;
        exit(1);
    }
    int iter = 0;
    int count = 0;

    string substr;
    string str_temp;
    vector<string> str_list;
    vector<string> word_list;
    vector<string> unicWord_list;
    while (getline(fin, str_temp)) {
        istringstream iss(str_temp);
        str_list.push_back(str_temp);
    }

    for (auto& elem: str_list) {
        for (int j = 0; j < elem.size(); j++) {
            if (ispunct(elem[j])) {
                elem[j] = ' ';
            }
        }
    }
    for (auto& elem : str_list) {
        cout << elem << endl;
    }
    return str_list;
}
void FindAllWords(vector<string> str_list) {

    int iter = 0;
    int count = 0;

    string substr;
    string str_temp;
    vector<string> word_list;
    vector<string> unicWord_list;
    for (auto& elem : str_list) {
        istringstream iss(elem);
        while (iss >> str_temp) {
            word_list.push_back(str_temp);
        }
    }
    for (int i = 0; i < word_list.size(); i++) {
        int count = FindStroke(word_list[i], str_list);
        cout << word_list[i] << ":\t" << count << " times" << endl;
    }
}


int main() {
    vector<string> text_vector = insertTextVector();
    ofstream fout;
    fout.open("text.txt");
    for (auto& elem : text_vector) {
        fout << elem;
        fout << "\n";
    }
    fout.close();
    ifstream fin;
    fin.open("text.txt");
    auto& fin1 = fin;
    FindUnicWords(fin1);
    cout << endl << "all words: " << endl;
    FindAllWords(fin1);
    FindAllWords(DeletePunc(fin1));
    cout << endl << "del punc: " << endl;
    vector<string> withoutPunct = DeletePunc(fin1);
    fout.open("text.txt");
    for (auto& elem : withoutPunct) {
        fout << elem;
        fout << "\n";
    }
}
