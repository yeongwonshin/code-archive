#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<long double>> A(N+1, vector<long double>(N+1));

    for(int i=1;i<=N;i++){
         for(int j=1;j<=N;j++){
             cin>>A[i][j];
         }
    }
    int Q;
    cin>>Q;
    vector<vector<long double>> rp(N+2, vector<long double>(N+2, 0.0L));

    for(int q=0;q<Q;q++){
         int R1, R2, C1, C2;
         long double V;
         cin>>R1>>C1>>R2>>C2>>V;
         rp[R1][C1] += V;
         rp[R2+1][C1] -= V;
         rp[R1][C2+1]-=V;
         rp[R2+1][C2+1]+=V;
    
    } 
    for(int i =1; i<=N;i++){
        for(int j=1;j<=N;j++){
            rp[i][j]+=rp[i][j-1];
        }
    }
    for(int j=1;j<=N;j++){
        for(int i=1;i<=N;i++){
            rp[i][j]+=rp[i-1][j];
        }
    }
    cout << setprecision(12);

    for(int i=1;i<=N;i++){
         for(int j=1; j<=N;j++){
             A[i][j]+=rp[i][j];
             if(j>1)cout<<' ';
             cout<<A[i][j];
         }
         cout<<'\n';
    }


    return 0;
}
