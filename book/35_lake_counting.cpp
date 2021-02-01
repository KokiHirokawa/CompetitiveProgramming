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
vector<vector<bool>> a;

void dfs(int y, int x) {
    a[y][x] = false;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            int ny = y + dy, nx = x + dx;
            if (0 <= nx && nx < m && 0 <= ny && ny < n && a[ny][nx]) dfs(ny, nx);
        }
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    rep2(i, n) a[i].resize(m);
    rep2(i, n) rep2(j, m) {
        char temp;
        cin >> temp;
        a[i][j] = temp == 'W';
    }

    int res = 0;
    rep2(i, n) rep2(j, m) if (a[i][j]) {
        dfs(i, j);
        res++;
    }
    printf("%d\n", res);
    return 0;
}