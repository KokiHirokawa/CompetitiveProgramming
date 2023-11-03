#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 関数テンプレート

template<typename T> // Generics
T GETMAX(T a, T b) {
    return a > b ? a : b; // Comparable などの制約はない
}

/*
    func getMax<T: Comparable>(a: T, b: T) {
        a > b ? a : b
    }
*/

template<> // template の特殊化
float GETMAX(float a, float b) {
    cout << "a: " << a << ", b: " << b << endl;
    return a > b ? a : b;
}

// クラステンプレート

template<class T>
class Box {
public:
    T value;        
};

// エイリアステンプレート

// template <class T> // 関数に対してはできなさそう
// using GETMAX2 = GETMAX<T>;

template <class T>
using Vec = vector<T>;

using StringVec = vector<string>;

int main() {
    {
        cout << "--- 1 ---" << endl;

        int a = 10, b = 20;
        cout << GETMAX(a, b) << endl;
        cout << GETMAX('a', 'z') << endl;
        cout << GETMAX("Hello", "World") << endl;
        cout << GETMAX(&a, &b) << endl;

        unordered_map<int, int> m;
        unordered_map<int, int> p;
        // cout << GETMAX(m, p) << endl; // 呼び出し側でエラー

        cout << GETMAX(1.0f, 2.0f) << endl;

        cout << "\n";
    }

    {
        cout << "--- 2 ---" << endl;

        Box<int> intBox;
        cout << intBox.value << endl;

        cout << "\n";
    }

    {
        cout << "--- 3 ---" << endl;

        // cout << MYGETMAX<int>(-51, -50);

        Vec<int> v;
        v.push_back(3);
        v.push_back(1);
        v.push_back(4);

        StringVec sv;
        sv.push_back("Hello");
        sv.push_back("World");

        for (string value: sv) {
            cout << value << endl;
        }

        cout << "\n";
    }

    return 0;
}