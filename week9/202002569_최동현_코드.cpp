#include <bits/stdc++.h>
using namespace std;


//기본 변수들 사이즈 설정
const int N = 100000;
const int M = 200000;
vector<int> arr1[M + 1];
vector<int> arr2[M + 1];
int visited[N + 1];
int visited2[N + 1];
stack<inta> st;

//dfs 두번 사용
void dfs(int node){
    if(visited[node]) return;
    visited[node] = 1;
    for(int child : arr2[node]){
        dfs(child);
    }
    //재탐색 하기 위해
    st.push(node);
}
int nodec = 0;
void dfs2(int node){
    if(visited2[node]) return;
    visited2[node] = nodec;
    for(int child : arr1[node]){
        dfs2(child);
    }
}

void solve(){
    int n, m, x, y;
    cin >> n >> m;
    memset(visited, 0, n + 1);
    memset(visited2, 0, n + 1);
    while(m--){
        cin >> x >> y;
        arr1[x].push_back(y);
        arr2[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    while(!st.empty()){
        //정방향 탐색
        int k = st.top();
        st.pop();
        if(!visited2[k]){
            nodec++;
            dfs2(k);
        }
    }
    cout << nodec << "\n";
    for(int i = 1; i <= n; i++){
        cout << visited2[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}