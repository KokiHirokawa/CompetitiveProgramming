#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

class Solution {
    public:
        int romanToInt(string s) {
            int result = 0;

            rep(s.size()) {
                char c = s[i];
                char next = s[i + 1];

                if (c == 'I') {
                    if (next == 'V') {
                        result += 4;
                        i++;
                    }
                    else if (next == 'X') {
                        result += 9;
                        i++;
                    }
                    else {
                        result += 1;
                    }
                }
                else if (c == 'V') result += 5;
                else if (c == 'X') {
                    if (next == 'L') {
                        result += 40;
                        i++;
                    }
                    else if (next == 'C') {
                        result += 90;
                        i++;
                    }
                    else {
                        result += 10;
                    }
                }
                else if (c == 'L') result += 50;
                else if (c == 'C') {
                    if (next == 'D') {
                        result += 400;
                        i++;
                    }
                    else if (next == 'M') {
                        result += 900;
                        i++;
                    }
                    else {
                        result += 100;
                    }
                }
                else if (c == 'D') result += 500;
                else if (c == 'M') result += 1000;
            }

            return result;
        }
};

int main() {
    Solution s;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("LVIII") << endl;
    cout << s.romanToInt("MCMXCIV") << endl;

    return 0;
}