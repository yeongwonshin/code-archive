#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();  // 숫자 입력 뒤에 남은 엔터 제거

    string line;

    for (int i = 0; i < N; i++) {
        getline(cin, line);

        cout << i + 1 << "번째 줄: " << line << '\n';
    }

    return 0;
}