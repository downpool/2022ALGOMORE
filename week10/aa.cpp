#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define V 501


int n;
vector<vector<ll> > capacity;
vector<vector<ll> > adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int> > q;
    q.push({s, __LONG_LONG_MAX__});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}


void solve(){
    int n, line;
    cin >> n >> line;
    ull gra[V][V];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            gra[i][j] = 0;
        }
    }
    for(int i = 0; i < line; i++){
        int a, b;
        ull c;
        cin >> a >> b >> c;
        gra[a][b] = c;
    }
    cout << maxflow(gra, 1, n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
