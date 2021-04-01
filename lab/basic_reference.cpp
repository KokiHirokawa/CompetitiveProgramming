#include <iostream>
using namespace std;

struct Person {
    char name[50];
    int age;
};

// - Note: 大きなデータを値渡しにするとコピーに時間がかかりメモリを多く消費するため、引数をconst形式の参照にする
void printPersonRef(const Person &psn) {
    cout << psn.name << "さん " << psn.age << "歳" << endl;
}

void changeValue(int &num) {
    num = 1;
}

int main() {
    int num;
    int &_num = num;

    _num = 100;

    cout << "num = " << num << endl;
    cout << "_num = " << _num << endl;

    changeValue(_num);

    cout << "num = " << num << endl;
    cout << "_num = " << _num << endl;

    Person p {"Ruby", 5};
    printPersonRef(p);

    return 0;
}