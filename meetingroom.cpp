/*회의실 배정 문제는 그리디 알고리즘(Greedy Algorithm) 을 이용하는 대표적인 문제입니다.

핵심은 회의가 끝나는 시간이 가장 빠른 순서대로 선택하는 것입니다.
1. 문제 설명
하나의 회의실에서 N개의 회의를 진행하려고 합니다.

각 회의에는 시작 시간과 종료 시간이 주어집니다.

다음 조건을 만족하면서 최대한 많은 회의를 배정해야 합니다.
- 하나의 회의실에서는 동시에 두 개의 회의를 진행할 수 없습니다.
- 한 회의가 끝나는 시간에 다른 회의를 시작할 수 있습니다.
- 회의의 시작 시간과 종료 시간이 같을 수도 있습니다.
- 진행할 수 있는 회의의 최대 개수를 출력합니다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first
            >> meetings[i].second;
    }

    // 종료 시간 기준 오름차순 정렬
    sort(meetings.begin(), meetings.end(),
        [](const auto& a, const auto& b) {
            if (a.second == b.second)
                return a.first < b.first;

            return a.second < b.second;
        });

    int cnt = 0;
    int lastEnd = 0;

    for (int i = 0; i < N; i++) {
        int start = meetings[i].first;
        int end = meetings[i].second;

        if (start >= lastEnd) {
            cnt++;
            lastEnd = end;
        }
    }

    cout << cnt << '\n';

    return 0;
}
