#include <functional>
#include <iostream>

void block() {
    auto sum = [](int x, int y) -> int { return x + y; };

    int result = sum(15, 35);
    std::cout << result << std::endl;

    // 引数リスト、および戻り値は省略可能
    // auto sayHello = []() -> void { std::cout << "Hello✨" << std::endl; };
    auto sayHello = [] { std::cout << "Hello✨" << std::endl; };
    sayHello();
}

void block2() {
    int a = 100;   

    // コピーキャプチャ
    auto f = [a] { std::cout << a << std::endl; };
    // 参照キャプチャ
    auto g = [&a] { std::cout << a << std::endl; };

    a = 200;

    f();
    g();
}

int add(int x, int y) { return x + y; }

void block3() {
    std::function<int(int, int)> f = add;
    std::cout << f(4, 7) << std::endl;

    f = [](int x, int y) { return x * y; };
    std::cout << f(4, 7) << std::endl;
}

int main() {
    block();
    block2();
    block3();
}