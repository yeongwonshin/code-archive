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
         __int128 X = S/N +1;//다음에 추가할 동전의 가치
         __int128 limit = min(target, (__int128)N*X);
//limit은 다음에 추가할 동전의 가치 X를 가진 동전을 추가했을 때, 목표값 target을 초과하지 않도록 제한한 값
         __int128 cnt = (limit - S + X -1)/X;
         S += cnt *X;
         ans+=(long long)cnt;
    }
    cout<<ans<<'\n';
    return 0;}
    
