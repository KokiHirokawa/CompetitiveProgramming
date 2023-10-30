// include directive
// 指定されたファイルの内容をディレクティブがある位置に含めるようにプリプロセッサに指示する
#include <iostream>

int main() {
    // character output
    std::cout << "Hello, World!" << std::endl;

    // exit status (0 or 1 ~ 255)
    // 戻り値を指定しない場合、コンパイラが戻り値として 0 を指定する
    return 0;
}