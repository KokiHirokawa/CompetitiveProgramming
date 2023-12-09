#include <iostream>
#include <string>

using namespace std;

vector<string> split(string source, string separator) {
    int separator_length = separator.length();

    vector<string> res;

    if (separator_length == 0) {
        res.push_back(source);
    } else {
        string::size_type offset = 0;
        while (true) {
            string::size_type pos = source.find(separator, offset);

            if (pos == string::npos) {
                res.push_back(source.substr(offset, pos - offset));
                break;
            }

            res.push_back(source.substr(offset, pos - offset));
            offset = pos + separator_length;
        }
    }

    return res;
}

int main() {
    {
        string s = "こんにちは";
        cout << s << endl;
        cout << s.size() << endl;

        string t = { s[12], s[13], s[14] };
        cout << t << endl;
    }

    {
        setlocale(LC_CTYPE, "ja_JP.UTF-8");

        char str1[] = "わーい";

        // 十分なメモリ領域を確保
        size_t capacity = strlen(str1) + 1;
        wchar_t *str2 = (wchar_t *)malloc(sizeof(wchar_t) * capacity);

        // char -> wchar_tの変換
        int result = mbstowcs(str2, str1, capacity);

        if (result <= 0) {
            fprintf(stderr, "マルチバイト文字列の変換に失敗\n");
            return EXIT_FAILURE;
        }

        printf("バイト長: %lu\n", capacity - 1);
        printf("長さ: %d\n", result);

        // 十分なメモリ領域を確保
        capacity = wcslen(str2) * 6 + 1;
        char* str3 = (char *)malloc(sizeof(char) * capacity);

        // wchar_t -> charの変換
        result = wcstombs(str3, str2, capacity);

        if (result <= 0) {
            fprintf(stderr, "ワイド文字列の変換に失敗");
            return EXIT_FAILURE;
        }

        printf("文字列: %s\n", str3);
        printf("1文字目: %lc\n", str2[0]);

        cout << str3 << endl;
        cout << str3[0] << endl;
        cout << str2[0] << endl;
    }

    {
        // SeeAlso: https://learn.microsoft.com/ja-jp/cpp/c-language/multibyte-and-wide-characters?view=msvc-170

        wchar_t s1[] = L"こんばんは";
        wprintf(L"%ls\n", s1);
        cout << wcslen(s1) << endl;

        wchar_t s2[] = { L'H', L'E', L'L', L'L', L'O', 0 };
        wprintf(L"%ls\n", s2);
        cout << wcslen(s2) << endl;
    }

    {
        cout << "--- 4 ---" << endl;

        string s = "\u0067\u0067";
        for_each(s.begin(), s.end(), [](const char c) { cout << c << endl; });

        for (int i = 0; i < s.size(); i++) {
            printf("%c\n", s[i]);
        }

        cout << endl;
    }

    {
        printf("--- 5 ---\n");

        string source = "dog cat monkey";
        vector<string> separated = split(source, " ");

        for (int i = 0; i < separated.size(); i++) {
            printf("%d: %s\n", i, separated[i].c_str());
        }

        printf("\n");
    }
}