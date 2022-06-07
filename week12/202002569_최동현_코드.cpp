#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a, b, c;

void solve(){
    cin >> a >> b >> c;
    for(int i = 0; i < c / a + 2; i++){
        for(int j = 0; j < c / b + 2; j++){
            if(i * a + j * b == c){
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}