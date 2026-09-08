#include<iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    int max_num;

    // TODO : complete Maximum subsequence sum algorithm
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    max_num = 0;
    int current_sum = 0;

    for(int i = 0; i < n; i++){
        current_sum += arr[i];

        if(current_sum < 0){
            current_sum = 0;
        }

        if(current_sum > max_num){
            max_num = current_sum;
        }
    }

    cout << max_num;

    return 0;
}