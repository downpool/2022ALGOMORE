#include <bits/stdc++.h>
using namespace std;
#define ll long long

//노드 인덱스, 값
struct node {
    int value;
    int index;
};

//노드 값을 저장하는 트리 제작
node tree[10000000];

//세그먼트 트리 제작
void build(int a[], int v, int l, int r){
    if(l == r){
        tree[v].value = a[l];
        tree[v].index = l + 1;
        return;
    }
    int mid = (l + r) / 2;
    build(a, 2 * v, l, mid);
    build(a, 2 * v + 1, mid + 1, r);
    if(tree[2 * v].value >= tree[2 * v + 1].value){
       tree[v] = tree[2 * v];
    }else{
       tree[v] = tree[2 * v + 1];
    }
}
 
//세그먼트 트리 update + query과정 한번에
//이유는 계산 후 바로 출력값을 표시하기 위해
int query(int node, int l, int r, int num){
    //빈방의 값보다 들어오는 그룹의 수가 많은경우 
    if(tree[node].value < num){
        return 0;
    }
    //그룹수 조건을 충족한경우 인덱스 리턴
    if(l == r){
        tree[node].value -= num;
        return tree[node].index;
    }

    int mid = (l + r) / 2;
    
    //중간값 갱신
    if(tree[2 * node].value >= num){
        int idx = query(2 * node, l , mid, num);
        if(tree[2 * node].value >= tree[2 * node + 1].value){
            tree[node] = tree[2 * node];
        }else{
            tree[node] = tree[2 * node + 1];
        }
        return idx;
    }else{
        int idx= query(2 * node + 1, mid + 1, r, num);
        if(tree[2 * node].value >= tree[2 * node + 1].value){
            tree[node] = tree[2 * node];
        }else{
            tree[node] = tree[2 * node + 1];
        }
 
        return idx;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    int room[n], group[m];
    for(int i = 0; i < n; i++){
        cin >> room[i];
    }
    for(int i = 0; i < m; i++){
        cin >> group[i];
    }
    build(room, 1, 0, n - 1);
    for(int i = 0; i < m; i++){
        cout << query(1, 0, n - 1, group[i]) << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}