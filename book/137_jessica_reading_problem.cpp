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
    int p;
    cin >> p;

    vector<int> a(p);
    rep2(i, p) cin >> a[i];

    set<int> all;
    rep2(i, p) all.insert(a[i]);
    int n = all.size();

    int l = 0, r = 0, num = 0;
    map<int, int> count;
    int res = p;
    for (;;) {
        while (r < p && num < n) {
            if (count[a[r++]]++ == 0) {
                num++;
            }
        }
        if (num < n) break;
        res = min(res, r - l);
        if (--count[a[l++]] == 0) {
            num--;
        }
    }

    printf("%d\n", res);
    return 0;
}