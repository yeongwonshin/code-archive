#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int q[10005];
    int front = 0;
    int rear = 0;

    string cmd;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            q[rear++] = x;
        }
        else if (cmd == "pop") {
            if (front == rear) {
                cout << -1 << '\n';
            } else {
                cout << q[front++] << '\n';
            }
        }
        else if (cmd == "size") {
            cout << rear - front << '\n';
        }
        else if (cmd == "empty") {
            cout << (front == rear ? 1 : 0) << '\n';
        }
        else if (cmd == "front") {
            if (front == rear)
                cout << -1 << '\n';
            else
                cout << q[front] << '\n';
        }
        else if (cmd == "back") {
            if (front == rear)
                cout << -1 << '\n';
            else
                cout << q[rear - 1] << '\n';
        }
    }

    return 0;
}