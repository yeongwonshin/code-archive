/*
2. 나이트 투어
문제

n × n 체스판이 있다.
나이트는 체스의 나이트처럼 움직인다.

가장 왼쪽 아래 칸에서 출발하여 가장 오른쪽 위 칸까지 이동하려고 한다.
도착하는 데 필요한 최소 이동 횟수를 출력하라.

첫 번째 줄에 테스트 케이스 개수 T가 주어진다.
각 테스트 케이스마다 정수 n이 주어진다.

단, 5 ≤ n ≤ 3000.

입력
T
n1
n2
...
nT
출력

각 테스트 케이스마다 최소 이동 횟수를 한 줄에 하나씩 출력한다.

예제 입력
4
5
6
7
8
예제 출력
4
4
4
6
*/
#include <iostream>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin>>n;
        int k = n - 1;

        /*
            ceil(2k / 3)
            정수 연산으로는 (2k + 2) / 3
            3으로 나누는 이유??
            -->나이트는 한 번에 보통 이렇게 움직인다.

(+1, +2)
(+2, +1)

목표가 오른쪽 위이므로 가장 유리한 이동은 이 두 종류다.

이때 좌표 합의 증가량은 둘 다

1 + 2 = 3
2 + 1 = 3
        */
        int ans = (2 * k + 2) / 3;

        /*
            출발점과 도착점의 색이 같으므로
            이동 횟수는 짝수여야 한다.
        */
        if (ans % 2 == 1) {
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
/*한 번에 모아서 출력하는 법
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    string output = "";

    while (T--) {
        int n;
        cin >> n;

        int k = n - 1;

        int ans = (2 * k + 2) / 3;

        if (ans % 2 == 1) {
            ans++;
        }

        output += to_string(ans) + '\n';
    }

    cout << output;

    return 0;
}*/