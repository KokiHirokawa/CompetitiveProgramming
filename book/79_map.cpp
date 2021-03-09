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
    // setは二分木として実装されている
    // set内の要素は特定の基準に従ってソートされた状態で保持される
    set<int> s;

    s.insert(3);
    s.insert(13);
    s.insert(21);

    set<int>::iterator ite;

    ite = s.find(3);
    if (ite == s.end()) puts("not found");
    else puts("found");

    ite = s.find(11);
    if (ite == s.end()) puts("not found");
    else puts("found");

    s.erase(3);

    if (s.count(3) != 0) puts("found");
    else puts("not found");

    for (ite = s.begin(); ite != s.end(); ++ite) printf("%d\n", *ite);

    return 0;
}