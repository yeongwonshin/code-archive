/*
문제: Sport Climbing Combined

스포츠 클라이밍 선수들의 경기 결과가 주어진다.

각 선수는 등번호와 세 종목 점수를 가진다.

각 선수의 최종 순위는 다음 기준으로 정한다.

세 종목 점수의 곱이 작은 선수가 더 높은 순위이다.
곱이 같다면, 세 종목 점수의 합이 작은 선수가 더 높은 순위이다.
곱과 합이 모두 같다면, 등번호가 작은 선수가 더 높은 순위이다.

모든 선수의 정보를 정렬한 뒤, 순위가 가장 높은 선수 3명의 등번호를 출력하라.

입력

첫 번째 줄에 선수의 수 n이 주어진다.

다음 n개의 줄에는 각 선수의 정보가 주어진다.

각 줄에는 다음 네 정수가 주어진다.

등번호 x y z

여기서 x, y, z는 세 종목 점수이다.

출력

순위가 가장 높은 선수 3명의 등번호를 공백으로 구분하여 출력한다.

예제 입력
5
101 1 2 3
102 2 2 2
103 1 3 2
104 1 1 10
105 2 1 4
예제 출력
101 103 102*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Player {
    int num;
    int x, y, z;
};

bool cmp(const Player& a, const Player& b) {
    long long productA = 1LL * a.x * a.y * a.z;
    long long productB = 1LL * b.x * b.y * b.z;

    if (productA != productB) {
        return productA < productB;
    }

    int sumA = a.x + a.y + a.z;
    int sumB = b.x + b.y + b.z;

    if (sumA != sumB) {
        return sumA < sumB;
    }

    return a.num < b.num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Player arr[105];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].num >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    sort(arr, arr + n, cmp);
//arr[0] ~ arr[n-1]이 cmp 기준으로 정렬

    cout << arr[0].num << ' ' << arr[1].num << ' ' << arr[2].num;

    return 0;
}
/*<algorithm>header를 못 쓰는 경우:

 #include <iostream>
using namespace std;

struct Player {
    int num;
    int x, y, z;
};

long long product(Player p) {
    return 1LL * p.x * p.y * p.z;
}

int sum(Player p) {
    return p.x + p.y + p.z;
}

bool isBetter(Player a, Player b) {
    if (product(a) != product(b)) {
        return product(a) < product(b);
    }

    if (sum(a) != sum(b)) {
        return sum(a) < sum(b);
    }

    return a.num < b.num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Player arr[105];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].num >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    // 선택 정렬
    for (int i = 0; i < n - 1; i++) {
        int best = i;

        for (int j = i + 1; j < n; j++) {
            if (isBetter(arr[j], arr[best])) {
                best = j;
            }
        }

        Player temp = arr[i];
        arr[i] = arr[best];
        arr[best] = temp;
    }

    cout << arr[0].num << ' ' << arr[1].num << ' ' << arr[2].num;

    return 0;
}

*/

/*merge sort
#include <iostream>
using namespace std;

struct Player {
    int num;
    int x, y, z;
};

long long product(const Player& p) {
    return 1LL * p.x * p.y * p.z;
}

int sumScore(const Player& p) {
    return p.x + p.y + p.z;
}

// a가 b보다 순위가 높으면 true
bool isBetter(const Player& a, const Player& b) {
    long long productA = product(a);
    long long productB = product(b);

    if (productA != productB) {
        return productA < productB;
    }

    int sumA = sumScore(a);
    int sumB = sumScore(b);

    if (sumA != sumB) {
        return sumA < sumB;
    }

    return a.num < b.num;
}

void merge(Player arr[], Player temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (isBetter(arr[i], arr[j])) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int t = left; t <= right; t++) {
        arr[t] = temp[t];
    }
}

void mergeSort(Player arr[], Player temp[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Player arr[105];
    Player temp[105];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].num >> arr[i].x >> arr[i].y >> arr[i].z;
    }

    mergeSort(arr, temp, 0, n - 1);

    cout << arr[0].num << ' ' << arr[1].num << ' ' << arr[2].num;

    return 0;
}*/