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

int main() {
    int length = 4;

    vector<char> number(4);
    rep2(i, length) cin >> number[i];

    vector<int> a(length);
    rep2(i, length) a[i] = (int)number[i] - '0';

    rep2(i, 1 << (length - 1)) {
        int sum = a[0];
        vector<char> c(length - 1);
        rep2(j, length - 1) {
            if (i >> j & 1) {
                c[j] = '+';
                sum += a[j + 1];
            } else {
                c[j] = '-';
                sum -= a[j + 1];
            }
        }
        if (sum == 7) {
            rep2(i, length) {
                printf("%d", a[i]);
                if (i < length - 1) {
                    printf("%c", c[i]);
                }
            }
            printf("=7\n");
            break;
        }
    }
    return 0;
}