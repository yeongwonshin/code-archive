/*
3. 뉴 스택

사용자가 말한 BOJ 10828과 유사한 스택 문제입니다. BOJ 10828은 push, pop, size, empty, top 명령을 처리하는 기본 스택 문제입니다. 여기서는 명령이 문자열이 아니라 숫자로 들어오고, swap, exit이 추가된 형태로 만들겠습니다.

문제

정수를 저장하는 스택을 구현하라.

명령은 숫자로 주어진다.

0 x : push x
1   : pop
2   : size
3   : empty
4   : top
5   : swap
6   : exit
입력

명령들이 여러 줄에 걸쳐 주어진다.
명령 6이 입력되면 종료한다.

출력

출력이 필요한 명령마다 결과를 한 줄에 하나씩 출력한다.

예제 입력
0 10
0 20
4
5
4
1
1
1
6
예제 출력
20
10
10
20
-1
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int stack[100000];
    int topIndex = -1;

    string output = "";

    while (true) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int x;
            cin >> x;
            stack[++topIndex] = x;
        }
        else if (cmd == 1) {
            if (topIndex == -1) {
                output += "-1\n";
            } else {
                output += to_string(stack[topIndex]) + "\n";
                topIndex--;
            }
        }
        else if (cmd == 2) {
            output += to_string(topIndex + 1) + "\n";
        }
        else if (cmd == 3) {
            if (topIndex == -1) {
                output += "1\n";
            } else {
                output += "0\n";
            }
        }
        else if (cmd == 4) {
            if (topIndex == -1) {
                output += "-1\n";
            } else {
                output += to_string(stack[topIndex]) + "\n";
            }
        }
        else if (cmd == 5) {
            if (topIndex < 1) {
                output += "-1\n";
            } else {
                int temp = stack[topIndex];
                stack[topIndex] = stack[topIndex - 1];
                stack[topIndex - 1] = temp;
            }
        }
        else if (cmd == 6) {
            break;
        }
    }

    cout << output;

    return 0;
}
/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> st;
    string output = "";

    while (true) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int x;
            cin >> x;
            st.push_back(x);
        }
        else if (cmd == 1) {
            if (st.empty()) {
                output += "-1\n";
            } else {
                output += to_string(st.back()) + "\n";
                st.pop_back();
            }
        }
        else if (cmd == 2) {
            output += to_string(st.size()) + "\n";
        }
        else if (cmd == 3) {
            if (st.empty()) {
                output += "1\n";
            } else {
                output += "0\n";
            }
        }
        else if (cmd == 4) {
            if (st.empty()) {
                output += "-1\n";
            } else {
                output += to_string(st.back()) + "\n";
            }
        }
        else if (cmd == 5) {
            if (st.size() < 2) {
                output += "-1\n";
            } else {
                int last = st.size() - 1;

                int temp = st[last];
                st[last] = st[last - 1];
                st[last - 1] = temp;
            }
        }
        else if (cmd == 6) {
            break;
        }
    }

    cout << output;

    return 0;
}
*/