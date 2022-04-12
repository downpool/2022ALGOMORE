#include <iostream>
#include <vector>

using namespace std;
//최대값 설정
const int maxs = 100001;

//기본 변수 생성
int N, M, a, b;
bool abl, visit[maxs], setteam[maxs];
vector<int> graph[maxs];

void dfs(int u, int p = 0){
    //인접 리스트 그래프 순회
    for(int v : graph[u]){
        //목표 노드가 현재 노드와 다르면
        if(v != p){
            //방문하지 않았을 경우
            if(!visit[v]){
                //팀을 다르게 설정
                setteam[v] = !setteam[u];
                //방문 완료
                visit[v] = true;
                //목표 노드를 변경해서 추가로 순회
                dfs(v, u);
            } else {
                //dfs를 해도 팀이 같으면 불가능.
                if(setteam[v] == setteam[u])
                    abl = false;
            }
        }
    }
}

int main(){
    //입력시간 단축
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //가능하다고 가정
    abl = true;
    //차례대로 방문
    for(int i = 1; i <= N; i++){
        if(!visit[i]){
            visit[i] = true;
            dfs(i);
        }
    }
    //출력
    if(!abl){
        cout << "IMPOSSIBLE" << "\n";
    }else{
        for(int i = 1; i <= N; i++){
            cout << (setteam[i] ? 1 : 2) << " ";
        }
    }   
}