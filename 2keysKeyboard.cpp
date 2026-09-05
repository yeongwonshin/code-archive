#include <iostream>
using namespace std;

int minSteps(int n) {
    int answer = 0;

    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            answer += p;
            n /= p;
        }
    }

    // 마지막 남은 n이 1보다 크다면 소수
    if (n > 1)
        answer += n;

    return answer;
}

int main() {
    int N;
    cin >> N;

    cout << minSteps(N) << '\n';

    return 0;
}