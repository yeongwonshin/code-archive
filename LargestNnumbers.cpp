#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long value;
    int index;
};

Node bigger(Node a, Node b) {
    // index가 -1이면 실제 원소가 없는 노드
    if (a.index == -1) return b;
    if (b.index == -1) return a;

    return (a.value >= b.value) ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int K = N * N;

    vector<long long> arr(K);

    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }

    // K 이상인 가장 작은 2의 거듭제곱
    int size = 1;
    while (size < K) {
        size *= 2;
    }

    // index == -1이면 빈 노드
    vector<Node> tree(2 * size, {0, -1});

    // leaf에 실제 값과 원래 index 저장
    for (int i = 0; i < K; i++) {
        tree[size + i] = {arr[i], i};
    }

    // tournament tree 구성
    for (int i = size - 1; i >= 1; i--) {
        tree[i] = bigger(tree[i * 2], tree[i * 2 + 1]);
    }

    // 가장 큰 값 N개 추출
    for (int count = 0; count < N; count++) {

        Node maximum = tree[1];

        cout << maximum.value << '\n';

        // 해당 leaf 제거
        int pos = size + maximum.index;
        tree[pos] = {0, -1};

        // root까지 갱신
        pos /= 2;

        while (pos >= 1) {
            tree[pos] =
                bigger(tree[pos * 2], tree[pos * 2 + 1]);

            pos /= 2;
        }
    }

    return 0;
}