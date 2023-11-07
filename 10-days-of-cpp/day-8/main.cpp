#include <iostream>
#include <cstddef>
#include <array>

using namespace std;

template <class T, size_t N>
constexpr size_t _size(const T (&)[N]) noexcept { return N; }

void printArray(int* array, size_t num) {
    for (size_t i = 0; i < num; i++) {
        cout << array[i] << endl;
    }
}

int main() {
    {
        int x[5] = { 0, 1, 2, 3, 4};
        int y[] = { 5, 6, 7, 8, 9, 10 }; // 要素数の省略

        cout << x << endl;
        cout << y << endl;

        cout << "x + 1 (" << x + 1 << ") = " << "&(x[1]) (" <<  &(x[1]) << ")" << endl;

        for (int i = 0; i < 5; i++) {
            cout << &(x[i]) << endl;
        }
    }

    {
        constexpr size_t num = 10;
        int x[num] = {};

        static_assert(_size(x) == 10, "");

        printArray(x, _size(x));
    }

    {
        array<int, 3> array = { 11, 12, 13 };

        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << endl;
        }
    }

    return 0;
}