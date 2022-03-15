#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    int arr[n + 100];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i += 2){
        if(arr[i] != arr[i + 1]){
            sum += arr[i + 1] - arr[i];
        }
    }

    cout << sum << "\n";

    return 0;
}