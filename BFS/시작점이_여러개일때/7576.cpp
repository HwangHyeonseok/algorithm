// �������� �������� BFS
// => ó�� �������� �� �ְ� �Ѳ����� BFS�� ������.

#include <iostream>
#include <queue>
#include <algorithm> // fill ����� ���� ���̺귯��

using namespace std;

#define MAX_N 1001 // N,M�� �ִ� 1001
int Board[MAX_N][MAX_N] = { -1 }; // 1 : ���� �丶�� 0 : ���� ���� �丶�� -1 : �丶�䰡 ������� ����
int col, row;
queue< pair<int, int> > Q;

void bfs() {
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };

    while (!Q.empty()) {
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // �� ���� ���� ������� �׻� ���� �˻�
            if (next_x >= row || next_x < 0 || next_y >= col || next_y < 0) continue;
            if (Board[next_x][next_y] != 0) continue;

            Board[next_x][next_y] = Board[cur_x][cur_y] + 1;
            Q.push({ next_x, next_y });
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int answer = 0;
    fill(&Board[0][0], &Board[MAX_N-1][MAX_N], -1); // ��� -1�� �ʱ�ȭ
    cin >> col >> row;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int condition;
            cin >> condition;
            Board[i][j] = condition;
        }
    }

    // bfs Ž�� ���� Ž��
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (Board[i][j] == 1)
                Q.push(make_pair(i, j));
        }
    }

    bfs();


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (Board[i][j] == 0) {     // �������� �丶�䰡 ���� ��� -1 ���
                cout << "-1";
                return 0;
            }
            else {
                answer = answer > Board[i][j] ? answer : Board[i][j];
            }
        }
    }

    cout << answer -1;
}