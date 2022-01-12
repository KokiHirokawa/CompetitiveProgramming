#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector< pair<int, int> > edges[100010];
int answers[100010];

void dfs(int cu, int pa = -1, int col = 0) {
    set<int> used;
    used.insert(col);

    int c = 1;
    for (auto to : edges[cu]) {
        if (to.first != pa) {
            while (used.count(c)) c++;
            answers[to.second] = c;
            dfs(to.first, cu, c);
            c++;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        edges[a].push_back(make_pair(b, i));
        edges[b].push_back(make_pair(a, i));
    }

    dfs(0);

    int color_num = 0;
    for (int i = 0; i < n; i++) {
        int num = edges[i].size();
        if (num > color_num) color_num = num;
    }
    printf("%d\n", color_num);

    for (int i = 0; i < n - 1; i++) {
        printf("%d\n", answers[i]);
    }
}