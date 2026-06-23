/*
3. BOJ 14395 — 4연산

정수 s를 t로 바꾸는 최소 연산 과정을 출력한다. 가능한 연산은 *, +, -, /이고, 여러 답이 있으면 사전순으로 앞서는 것을 출력해야 한다. 
값 범위가 10^9까지라 배열 방문 처리가 아니라 해시 방식 방문 처리가 필요하다.
*/
#include <stdio.h>
#include <string.h>

#define LIMIT 1000000000LL
#define MAXNODE 2000000
#define HSIZE 4194304

long long values[MAXNODE];
int parent_idx[MAXNODE];
char op_char[MAXNODE];
int queue_idx[MAXNODE];
int hash_table[HSIZE];
int node_count;

int find_value(long long v) {
    unsigned int h = ((unsigned long long)v * 11995408973635179863ULL) & (HSIZE - 1);

    while (hash_table[h] != -1) {
        int idx = hash_table[h];

        if (values[idx] == v) return idx;

        h = (h + 1) & (HSIZE - 1);
    }

    return -1;
}

int add_value(long long v, int p, char op) {
    unsigned int h = ((unsigned long long)v * 11995408973635179863ULL) & (HSIZE - 1);

    while (hash_table[h] != -1) {
        int idx = hash_table[h];

        if (values[idx] == v) return idx;

        h = (h + 1) & (HSIZE - 1);
    }

    if (node_count >= MAXNODE) return -1;

    int idx = node_count++;
    values[idx] = v;
    parent_idx[idx] = p;
    op_char[idx] = op;
    hash_table[h] = idx;

    return idx;
}

int main(void) {
    long long s, t;
    scanf("%lld %lld", &s, &t);

    if (s == t) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < HSIZE; i++) {
        hash_table[i] = -1;
    }

    node_count = 0;

    int start = add_value(s, -1, 0);

    int front = 0, rear = 0;
    queue_idx[rear++] = start;

    int target_idx = -1;

    while (front < rear && target_idx == -1) {
        int cur_idx = queue_idx[front++];
        long long x = values[cur_idx];

        long long nexts[4];
        char ops[4] = {'*', '+', '-', '/'};
        int valid[4] = {0, 0, 1, 0};

        if (x != 0 && x <= LIMIT / x) {
            nexts[0] = x * x;
            valid[0] = 1;
        }

        if (x <= LIMIT / 2) {
            nexts[1] = x + x;
            valid[1] = 1;
        }

        nexts[2] = 0;

        if (x != 0) {
            nexts[3] = 1;
            valid[3] = 1;
        }

        for (int i = 0; i < 4; i++) {
            if (!valid[i]) continue;

            long long nx = nexts[i];

            if (nx < 0 || nx > LIMIT) continue;
            if (find_value(nx) != -1) continue;

            int ni = add_value(nx, cur_idx, ops[i]);

            if (ni == -1) continue;

            if (nx == t) {
                target_idx = ni;
                break;
            }

            queue_idx[rear++] = ni;
        }
    }

    if (target_idx == -1) {
        printf("-1\n");
        return 0;
    }

    char ans[200];
    int len = 0;
    int cur = target_idx;

    while (parent_idx[cur] != -1) {
        ans[len++] = op_char[cur];
        cur = parent_idx[cur];
    }

    for (int i = len - 1; i >= 0; i--) {
        putchar(ans[i]);
    }
    putchar('\n');

    return 0;
}