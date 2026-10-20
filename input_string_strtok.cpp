#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();  // cin 뒤에 남은 엔터 제거

    string line;

    for (int i = 0; i < N; i++) {
        getline(cin, line);

        cout << i + 1 << "번째 줄:\n";

        stringstream ss(line);
        string word;

        while (ss >> word) {
            cout << "단어: " << word << '\n';
        }
    }

    return 0;
}