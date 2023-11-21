#include <iostream>
#include <string>

using namespace std;

enum PointerType {
    BYTE = 1,
    INT = 2,
    LONGINT = 4
};

class Fragment {
public:
    string name;
    int segmentId;
    int offset;
    PointerType fragmentSize;
};

class Segment {
    Fragment *arr[32];
public:
    Segment() {
        *arr = new Fragment[32];
    }
    int getSize() {
        int total = 0;
        for(int i = 0; i < 32; i++) {
            total += arr[i]->fragmentSize;
        }
        return total;
    }
};
class StaticSegment: Segment {};
class DynamicSegment: Segment {};

class DB {
    StaticSegment *DBStatic;
    DynamicSegment *DBDynamic;
public:
    DB() {
        DBStatic = new StaticSegment();
        DBDynamic = new DynamicSegment();
    }
    void newPointer(string name, PointerType type) {
        DBStatic[0];
    }
};


void GetBinaryInformation(){
    int n;
    cout<<"Введите нужное число симаволом"<<endl;
    cin>>n;
    cout<<endl;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Введите число"<<endl;
        cin>>arr[i];
        cout<<arr[i];
    }
}
int main() {
    DB *db = new DB();
    db->newPointer("a", BYTE);
    
    GetBinaryInformation();
    return 0;
}
