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
    string s;
    cin >> s;

    int n = s.length();

    vector<int> res(n, 0);
    int a = 1;
    rep3(i, 1, n) {
        if (s[i - 1] == 'R' && s[i] == 'R') {
            a++;
        } else if (s[i - 1] == 'R' && s[i] == 'L') {
            res[i] += a / 2;
            res[i - 1] += a / 2;
            if (a % 2 == 1) res[i - 1]++;
            a = 1;
        }
    }

    a = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i + 1] == 'L' && s[i] == 'L') {
            a ++;
        } else if (s[i + 1] == 'L' && s[i] == 'R') {
            res[i] += a / 2;
            res[i + 1] += a / 2;
            if (a % 2 == 1) res[i + 1]++;
            a = 1;
        }
    }

    rep2(i, n) {
        if (i < n - 1) printf("%d ", res[i]);
        else printf("%d\n", res[i]);
    }
    return 0;
}