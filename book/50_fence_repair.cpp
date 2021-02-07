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
    int n;
    cin >> n;

    vector<int> l(n);
    rep2(i, n) cin >> l[i];

    ll ans = 0;
    while (n > 1) {
        int mii1 = 0, mii2 = 1;
        if (l[mii1] > l[mii2]) swap(mii1, mii2);

        for (int i = 2; i < n; i++) {
            if (l[i] < l[mii1]) {
                mii1 = i;
                mii2 = mii1;
            } else if (l[i] < l[mii2]) {
                mii2 = i;
            }
        }

        int t = l[mii1] + l[mii2];
        ans += t;

        if (mii1 == n - 1) swap(mii1, mii2);
        l[mii1] = t;
        l[mii2] = l[n - 1];
        n--;
    }

    printf("%d\n", ans);
    return 0;
}