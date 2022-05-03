#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class UFDS {
private:
    vector<int> p, rank, setSizes;
    int numSets;
public:
    UFDS(int N) {
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
        setSizes.assign(N, 1);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                setSizes[findSet(x)] += setSizes[findSet(y)];
                p[y] = x;
            } else {
                setSizes[findSet(y)] += setSizes[findSet(x)];
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            numSets--;
        }
    }
    int setSize(int i) {
        return setSizes[findSet(i)];
    }
    int numDisjointSets() {
        return numSets;
    }
};

signed main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, vector<int, int>>> edges;
    UFDS ufds {N};

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a - 1, b - 1}});
    }

    int connect = N;
    sort(edges.begin(), edges.end());
    int ans = 0;

    for(int i = 0; i < M; i++){
        if(ufds.findSet(edges[i].second.first) != ufds.findSet(edges[i].second.second)){
            ufds.unionSet(edges[i].second.first, edges[i].second.second);
            ans += edges[i].first;
            connect++;
        }
    }
    if(connect > 1){
        cout << "IMPOSSIBLE" << "\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}