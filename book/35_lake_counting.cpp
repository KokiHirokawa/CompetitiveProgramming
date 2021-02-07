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

int height, width;
vector<vector<char>> garden;

const vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1}, dx = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x) {
    garden[y][x] = '.';

    rep2(i, 8) {
        int ny = y + dy[i], nx = x + dx[i];
        if (0 <= ny && ny < height && 0 <= nx && nx < width && garden[ny][nx] == 'W') {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> height >> width;
    garden.resize(height);
    rep2(i, height) garden[i].resize(width);
    rep2(i, height) rep2(j, width) {
        char temp;
        cin >> temp;
        garden[i][j] = temp;
    }

    int res = 0;
    rep2(i, height) rep2(j, width) {
        if (garden[i][j] == 'W') {
            res++;
            dfs(i, j);
        }
    }

    printf("%d\n", res);
    return 0;
}