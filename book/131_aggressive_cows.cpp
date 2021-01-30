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

int n, m;
vector<int> x;

bool isOK(int d) {
    int last = 0;
    rep3(i, 1, m) {
        int crt = last + 1;
        while (crt < n && x[crt] - x[last] < d) {
            crt++;
        }
        if (crt == n) return false;
        last = crt;
    }
    return true;
}

int main() {
    cin >> n >> m;

    x.resize(n);
    rep2(i, n) cin >> x[i];

    sort(x.begin(), x.end());

    int lb = 0, ub = INT32_MAX;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        
        if (isOK(mid)) lb = mid;
        else ub = mid;
    }

    printf("%d\n", lb);
    return 0;
}