#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    long long n = N;
    long long ans = 0;

    if(M==0) {
         cout<< 0 << '\n'; 
         return 0;
    }
    ans = N;
    __int128 S = N;
    __int128 target = (__int128)N *M;
    
    while(S < target){
         __int128 X = S/N +1;
         __int128 limit = min(target, (__int128)N*X);
         __int128 cnt = (limit - S + X -1)/X;
         S += cnt *X;
         ans+=(long long)cnt;
    }
    cout<<ans<<'\n';
    return 0;}
    
