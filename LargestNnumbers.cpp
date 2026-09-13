#include <iostream>
#include <vector>
#include <limits>

/*초기 Tournament Tree 생성에 \(O(N^2)\), 최대값 하나를 제거한 뒤 갱신하는 데 \(O(\log N)\), 이를 N번 수행하므로

$$ O(N^2 + N\log N)=O(N^2) $$

이다. 임의의 행렬에서는 애초에 N²개의 원소를 모두 확인해야 하므로 점근적으로 최적이다.
*/
using namespace std;

struct Node {
    long long value;
    int index;
};

Node bigger(Node a, Node b) {
    return (a.value > b.value) ? a : b;
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

    // leaf 개수를 2의 거듭제곱으로 맞춘다.
    int size = 1;
    while (size < K) {
        size *= 2;
    }

    const long long NEG_INF = numeric_limits<long long>::lowest();

    vector<Node> tree(2 * size, {NEG_INF, -1});

    // leaf에 원소 저장
    for (int i = 0; i < K; i++) {
        tree[size + i] = {arr[i], i};
    }

    // tournament tree 구성
    for (int i = size - 1; i >= 1; i--) {
        tree[i] = bigger(tree[i * 2], tree[i * 2 + 1]);
    }

    // 가장 큰 값 N개 출력
    for (int count = 0; count < N; count++) {
        Node maximum = tree[1];

        cout << maximum.value << '\n';

        // 최대값이 있던 leaf 제거
        int pos = size + maximum.index;
        tree[pos] = {NEG_INF, -1};

        // 해당 leaf에서 root까지의 경로만 갱신
        pos /= 2;

        while (pos >= 1) {
            tree[pos] = bigger(tree[pos * 2], tree[pos * 2 + 1]);
            pos /= 2;
        }
    }

    return 0;
}