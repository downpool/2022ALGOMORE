#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    int N[n + 1];
    int M[m + 1];

    for(int i = 1; i <= n; i++){
        cin >> N[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> M[i];
    }

    for(int p = 0; p <= 512; p++){
        int count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(((N[i] & M[j]) | p) == p){
                    count++;
                    break;
                }
            }
        }
        if(count == n){
            cout << p << "\n";
            break;
        }
    }

    return 0;
}