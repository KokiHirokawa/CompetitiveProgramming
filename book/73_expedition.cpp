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

using ull = unsigned long long;

int main() {
    ll n, l, p;
    cin >> n >> l >> p;

    vector<ull> a(n + 1), b(n + 1);
    rep2(i, n) cin >> a[i];
    rep2(i, n) cin >> b[i];

    a[n] = l;
    b[n] = 0;

    priority_queue<ll> q;
    ll position = 0;
    ll res = 0;

    rep2(i, n + 1) {
        ll d = a[i] - position;

        while (p - d < 0) {
            if (q.empty()) {
                print(-1);
                return 0;
            }

            p += q.top();
            q.pop();
            res++;
        }

        p -= d;
        position = a[i];
        q.push(b[i]);
    }

    print(res);
    return 0;
}