#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> pebbles(int N, int K, string S) {
    vector<int> ans;
    // TODO
    // You should choose the indices and put them into
    // the vector `ans`.
    // The indices you insert should be 0-based, but
    // the skeleton code will convert them to 1-based
    // and print them.
    int left = 0;
    int white =0;
    int maxLen =0;
    int bestLeft =0;
    int bestRight=-1;

    for(int right =0;right<N;right++){
        if(S[right]=='W')white++;
        while(white>K){
            if(S[left]=='W') white--;
            left++;
        }
        if(right-left+1>maxLen){
            maxLen = right - left +1;
            bestLeft = left;
            bestRight=right;

        }
    }
    for (int i =bestLeft;i<=bestRight;i++){
        if(S[i]=='W') ans.push_back(i);
    }

    return ans;
}

int main() {
    int N, K;
    string S;

    cin >> N >> K >> S;

    vector<int> ans = pebbles(N, K, S);

    cout << ans.size() << '\n';
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

    return 0;
}