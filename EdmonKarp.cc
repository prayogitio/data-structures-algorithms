#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector> 
using namespace std;
 
int N, mf, f, s, t, c;
int res[110][110];
vector<int> p;
 
void augment(int v, int min_edge) {
    if(v == s) {
        f = min_edge;
        return;
    } else if(p[v] != -1) {
        augment(p[v], min(min_edge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}
 
int main() {
    for(int i = 1;; i++) {
        scanf("%d", &N);
        if(N == 0) break;
        scanf("%d %d %d", &s, &t, &c);
        s--; t--;
        memset(res, 0, sizeof res);
        int x, y, w;
        for(int j = 0; j < c; j++) {
            scanf("%d %d %d", &x, &y, &w);
            x--; y--;
            res[x][y] += w;
            res[y][x] += w;
        }
        mf = 0;
        for(;;) {
            f = 0;
            vector<int> dist(N, INT_MAX);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(N, -1);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                if(u == t) break;
                for(int v = 0; v < N; v++) {
                    if(res[u][v] > 0 && dist[v] == INT_MAX) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            augment(t, INT_MAX);
            if(f == 0) break;
            mf += f;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", i, mf);
    }
}