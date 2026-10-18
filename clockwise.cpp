/*
이 문제는 연못이 등장하지는 않지만, 시계방향과 반시계방향으로 원형 배치를 이동한다는 구조 때문에 함께 살펴볼 만합니다.
N명의 친구들이 원형으로 앉아 공을 주고받습니다.
공을 받은 횟수가 홀수이면 시계방향으로 L번째 사람에게 던지고, 짝수이면 반시계방향으로 L번째 사람에게 던집니다.
어떤 사람이 공을 M번 받으면 게임이 종료됩니다. 이때까지 공을 던진 총횟수를 구하는 문제입니다. 

예제 입력
5 3 2


예제 출력
10
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> cnt(N, 0);

    int pos = 0;
    int answer = 0;

    while (true) {
        cnt[pos]++;

        // M번 받은 사람이 생기면 종료
        if (cnt[pos] == M)
            break;

        if (cnt[pos] % 2 == 1) {
            // 홀수: 시계방향
            pos = (pos + L) % N;
        } else {
            // 짝수: 반시계방향
            pos = (pos - L + N) % N;
        }

        answer++;
    }

    cout << answer << '\n';

    return 0;
}
