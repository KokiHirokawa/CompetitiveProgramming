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

vector<vector<char>> grid(10, vector<char>(10));
vector<vector<bool>> reached(10, vector<bool>(10, false));

ll dfs(int y, int x) {
    if (y < 0 || 10 <= y || x < 0 || 10 <= x || reached[y][x] || grid[y][x] == 'x') return 0;

    reached[y][x] = true;
    return 1 + dfs(y, x - 1) + dfs(y - 1, x) + dfs(y + 1, x) + dfs(y, x + 1);
}

int main() {
    ll count = 0;
    rep2(i, 10) rep2(j, 10) {
        char temp; cin >> temp;
        grid[i][j] = temp;
        if (temp == 'o') ++count;
    }

    rep2(i, 10) rep2(j, 10) {
        if (grid[i][j] != 'x') continue;

        grid[i][j] = 'o';
        rep2(i, 10) rep2(j, 10) reached[i][j] = false;
        if (dfs(i, j) == count + 1) {
            printf("YES\n");
            return 0;
        }
        grid[i][j] = 'x';
    }
    printf("NO\n");
    return 0;
}