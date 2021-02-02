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

int N, M;
vector<vector<char>> maze;
vector<vector<int>> d;
int sx, sy, gx, gy;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    que.push(P(sy, sx));
    d[sy][sx] = 0;

    while (que.size()) {
        P p = que.front(); que.pop();
        if (p.first == gy && p.second == gx) break;

        rep2(i, 4) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] != '#' && d[ny][nx] == INT32_MAX) {
                que.push(P(ny, nx));
                d[ny][nx] = d[p.first][p.second] + 1;
            }
        }
    }

    return d[gy][gx];
}

int main() {
    cin >> N >> M;

    maze.resize(N);
    d.resize(N);
    rep2(i, N) {
        maze[i].resize(M);
        d[i].resize(M);
    }
    rep2(i, N) rep2(j, M) {
        d[i][j] = INT32_MAX;

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

    int res = bfs();
    printf("%d\n", res);
    return 0;
}