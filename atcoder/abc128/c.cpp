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
    int n, m;
    cin >> n >> m;

    vector<int> k(m), p(m);
    vector<vector<int>> s(m);

    rep2(i, m) {
        int _k;
        cin >> _k;
        k[i] = _k;

        s[i].resize(_k);

        rep2(j, _k) {
            int _s;
            cin >> _s;
            _s--;
            s[i][j] = _s;
        }
    }

    rep2(i, m) cin >> p[i];

    int res = 0;
    rep2(i, 1 << n) {
        bool flag = true;
        rep2(j, m) {
            int sum = 0;
            for (auto k: s[j]) {
                if (i >> k & 1) sum++;
            }
            if (sum % 2 != p[j]) {
                flag = false;
                break;
            }
        }
        if (flag) res++;
    }

    printf("%d\n", res);
    return 0;
}