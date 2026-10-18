/*
연못에 0번부터 N-1번까지 N개의 연잎이 원형으로 배치되어 있습니다.
- 개구리는 0번 연잎에서 출발합니다.
- 한 번 점프할 때마다 시계방향으로 K칸 이동합니다.
- M번 점프했을 때 개구리가 위치한 연잎의 번호를 출력해야 합니다.
예제
입력:
5 2 3


출력:
1
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K, M;
    cin >> N >> K >> M;

    cout << (K * M) % N << '\n';

    return 0;
}
/*핵심 원리
원형으로 배치되어 있으므로 N번째 위치에 도달하면 다시 0번으로 돌아옵니다.
따라서 최종 위치는

answer=(K * M)mod N

으로 계산할 수 있습니다.
이 문제는 점프 횟수가 최대 10^9이지만, 모든 점프를 시뮬레이션할 필요가 없다는 점이 핵심입니다.
*/