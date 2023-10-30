#include <iostream>

using namespace std;

void block() {
    cout << "--- block ---\n" << endl;

    int x = 1;
    x = 10;

    const int y = 2;
    
    constexpr int z = 3;

    auto a = 4;
    a = 5;

    cout << "INT_MAX = " << INT_MAX << ", (1 << 31) - 1 = " << (1 << 31) - 1 << endl; // int -> 32 bit
    cout << "LONG_MAX = " << LONG_MAX << endl; // long long -> 64 bit

    cout << "\n" << endl;

    // char, short, int, long のサイズはコンパイラに依存するため、非依存にしたい場合はサイズ指定付き整数型を使う
    std::int32_t t = -10;
    std::uint64_t u = 100;
}

void block2() {
    cout << "--- block2 ---\n" << endl;

    bool ok = false;
    cout << ok << endl;

    if (ok) {
        cout << "ok is true" << endl;
    } else {
        cout << "ok is false" << endl;
    }

    ok = true;
    cout << ok << endl;

    cout << (ok ? "ok is true" : "ok is false") << endl;

    // 条件分岐は bool 値以外でも可能
    if (0) {
        cout << "🙆‍♂️" << endl;
    } else {
        cout << "🙅‍♂️" << endl;
    }
    cout << "\n" << endl;
}

void block3() {
    cout << "--- block3 ---\n" << endl;

    // enum の場合、同じ別の型でも同じ列挙子を定義できないため enum class を利用する
    enum class Day {
        Sun,
        Mon,
        Tue,
        Wed = 10,
        Thu,
        Fri,
        Sat
    };

    Day day = Day::Wed;

    cout << "Day::Wed (" << static_cast<int>(day) << ")" << endl;

    Day days[7] = {Day::Sun, Day::Mon, Day::Tue, Day::Wed, Day::Thu, Day::Fri, Day::Sat};
    for (Day day:days) {
        cout << static_cast<int>(day) << endl;
    }

    cout << "\n" << endl;
}

void block4() {
    cout << "--- block3 ---\n";

    // cout, clog, cerr are global objects.
    cout << "This is message\n";
    clog << "This is log\n";
    cerr << "This is error" << endl; // endl inserts a newline character.
}

int main() {
    block();
    block2();
    block3();
    block4();
}