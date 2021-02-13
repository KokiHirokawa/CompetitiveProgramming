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

typedef pair<int, int> P;

int main() {
    int height, width;
    cin >> height >> width;

    int sx, sy, gx, gy;
    vector<int> dx = {-1, 0, 0, 1}, dy = {0, -1, 1, 0};

    vector<vector<char>> maze(height, vector<char>(width));
    vector<vector<int>> d(height, vector<int>(width, INT32_MAX));

    rep2(i, height) rep2(j, width) {
        char temp;
        cin >> temp;
        maze[i][j] = temp;

        if (temp == 'S') {
            sy = i;
            sx = j;
        } else if (temp == 'G') {
            gy = i;
            gx = j;
        }
    }

    queue<P> que;
    que.push(make_pair(sy, sx));
    d[sy][sx] = 0;

    while (!que.empty()) {
        P top = que.front();
        que.pop();

        rep2(i, 4) {
            int ny = top.first + dy[i], nx = top.second + dx[i];
            if (0 <= ny && ny < height && 0 <= nx && nx < width && maze[ny][nx] != '#' && d[ny][nx] == INT32_MAX) {
                que.push(make_pair(ny, nx));
                d[ny][nx] = d[top.first][top.second] + 1;
            }
        }
    }

    printf("%d\n", d[gy][gx]);
    return 0;
}