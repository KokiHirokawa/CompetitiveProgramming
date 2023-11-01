#include <iostream>

using namespace std;

int main() {
    {
        cout << "---\n";

        int x = 10;

        int *p = &x; // int* p でも OK

        cout << "x = " << x << endl;
        cout << "p = " << p << ", *p = " << *p << endl;

        *p = 20;
        cout << "x = " << x << endl;
        cout << "p = " << p << ", *p = " << *p << endl;

        cout << "\n";
    }

    {
        cout << "---\n";

        int *p = nullptr;

        cout << "p = " << p << endl;

        int x = 10;
        int y = 20;

        p = &x;
        cout << "p = " << p << ", *p = " << *p << endl;

        p = &y;
        cout << "p = " << p << ", *p = " << *p << endl;

        cout << "\n";
    }

     {
        int x = 100;
        const int* p1 = &x;

        cout << "x = " << x << endl;
        
        // *p1 = 200; // 🔴 read-only variable is not assignable

        // 💡 int const *p2 だと同様にポイントが不変になるので、普段から（型名）* の方が良いかもしれない
        int* const p2 = &x;
        *p2 = 200;
        // p2 = nullptr; // 🔴 cannot assign to variable 'p2' with const-qualified type 'int *const'
        cout << "x = " << x << endl;

        const int* const p3 = &x;
        // p3 = nullptr;
        // *p3 = 200;
     }
}