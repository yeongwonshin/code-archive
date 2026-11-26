#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxWater(vector<int>& arr) {
    int res = 0;
    int left = 0;
    int right = (int)arr.size()-1;
    int leftMax =0;
    int rightMax =0;
    while (left<right){
        if(arr[left]<=arr[right]){
            leftMax = max(leftMax, arr[left]);
            res+=leftMax-arr[left];
            left++;

        }
        else {
            rightMax = max(rightMax, arr[right]);
            res+=rightMax-arr[right];
            right--;
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num; 

    for (int t = 0; t < test_num; ++t) {
        int B;
        cin >> B; 

        vector<int> arr(B);
        for (int i = 0; i < B; ++i) {
            cin >> arr[i];
        }

        cout << maxWater(arr) << endl;
    }

    return 0;
}