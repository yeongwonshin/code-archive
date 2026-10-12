#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long double> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    const long double PI = acos(-1.0L);
    const long double EPS = 1e-12L;

    if(N<=2){
        cout<<"Yes\n";
        return 0;
    }
    long double x0 = X[0];
    long double y0 = Y[0];
    long double minAngle = 0.0L;
    long double maxAngle = 0.0L;
    bool hasAntipodal = false;

    bool positiveSide = false;
    bool negativeSide = false;
    for(int i =1;i<N;i++){
        long double cross = x0 * Y[i] - y0*X[i];
        long double dot = x0*X[i]+y0*Y[i];
        long double angle = atan2l(cross, dot);
        
        if(fabsl(fabsl(angle)-PI)<=EPS){
            hasAntipodal=true;
            continue;

        }
        minAngle = min(minAngle, angle);
        maxAngle = max(maxAngle, angle);
 // 기준 벡터를 중심으로 다른 벡터가 반시계 방향에 있는지, 시계 방향에 있는지 확인하는 코드
        if(angle>EPS)positiveSide=true;
        if(angle<-EPS)negativeSide=true;
    }
    bool possible;
    if(hasAntipodal){
        possible = !(positiveSide&&negativeSide);
    }
    else {
         possible = (maxAngle - minAngle<=PI + EPS);
        
    }
    if (possible) cout << "Yes\n";
    else cout<<"No\n";

    return 0;
}
