#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

void block() {
    cout << "--- block ---\n";

    auto sum = [](int x, int y) -> int { return x + y; };

    int num = -50;
    auto printNum = [&num] { cout << num << endl; };

    printNum();

    num = 10;
    printNum();

    cout << "\n";
}

void block2() {
    cout << "--- block2 ---\n";

    int d = 42; // 10 進数
    int o = 052; // 8 進数 (octal number)
    int x = 0x2a; // 16 進数 (hexadecimal number)
    int X = 0X2A; // 16 進数

    cout << "d = " << d << endl;
    cout << "o = " << o << endl;
    cout << "x = " << x << endl;
    cout << "X = " << X << endl;

    char c = 'a';
    char16_t u16 = u'あ';
    char32_t u32 = U'🍌';

    cout << "c = " << c << " (" << typeid(c).name() << ")" << endl; // typeid operator
    cout << "u16 = " << u16 << " (" << typeid(u16).name() << ")" << endl;
    cout << "u32 = " << u32 << " (" << typeid(u32).name() << ")" << endl;

    cout << "\n";
}

void block3() {
    cout << "--- block3 ---\n";

    string str1 = "Hello";

    cout << str1 << endl;
    cout << str1.size() << endl;
    cout << str1.at(1) << endl;

    string s = "こんにちは";
    cout << s << endl;
    cout << s.at(s.size() - 1) << endl; // 文字化け

    // char c = 'あ'; // compile error

    char c = 100;
    cout << c << endl;

    cout << "\n";
}

int main() {
    block();
    block2();
    block3();
}
