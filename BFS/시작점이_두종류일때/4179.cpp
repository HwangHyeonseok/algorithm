// BFS - �� ������ ������

// ���� ���Ŀ� �������� �̵��� BFS�� ���� ���� �����־�� �Ѵ�.
// �� ��ġ�� (���� ���� �ð� > �������� �̵� ���� �ð�) �̾�� �����̰� �̵��� ������ ��ġ�̴�.

#include <iostream>
#include <queue>
#include <climits> // INT_MAX use

using namespace std;

#define MAX_N 1001 // ���� �ִ� ��� ���� ����
int R, C;
char Board[MAX_N][MAX_N];
int Jihoon[MAX_N][MAX_N];
int Fire[MAX_N][MAX_N];
queue< pair<int, int> > Jihoon_Q;
queue <pair<int, int> > Fire_Q;
// �̵� ����
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

// �ҿ� ���� bfs
void bfs_fire() {
    while (!Fire_Q.empty()) {
        int cur_x = Fire_Q.front().first;
        int cur_y = Fire_Q.front().second;
        Fire_Q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // �� ���� �˻�
            if (next_x >= C || next_x < 0 || next_y >= R || next_y < 0) continue;
            if (Board[next_y][next_x] == '#') continue; // ���� ���
            if (Fire[next_y][next_x] != INT_MAX) continue; // �̹� ���� �湮�� ���

            Fire[next_y][next_x] = Fire[cur_y][cur_x] + 1;
            Fire_Q.push({ next_x,next_y });
        }
    }
}

// �����̿� ���� bfs
int bfs_jihoon() {
    while (!Jihoon_Q.empty()) {
        int cur_x = Jihoon_Q.front().first;
        int cur_y = Jihoon_Q.front().second;
        Jihoon_Q.pop();

        // Ż�� ���ǿ� �ش��ϴ� ��� Ż���Ѵ�.
        if (cur_x == 0 || cur_x == C - 1 || cur_y == 0 || cur_y == R - 1) {
            return Jihoon[cur_y][cur_x] + 1;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // �� ���� �˻�
            if (next_x >= C || next_x < 0 || next_y >= R || next_y < 0) continue;
            if (Board[next_y][next_x] == '#') continue; // ���� ���
            if (Jihoon[next_y][next_x] != -1) continue; // �����̰� �̹� �湮�� ���
            if ((Jihoon[cur_y][cur_x] + 1) >= Fire[next_y][next_x]) continue; // ���� �̹� ������ ���

            Jihoon[next_y][next_x] = Jihoon[cur_y][cur_x] + 1;
            Jihoon_Q.push({ next_x,next_y });
        }
    }
    return -1; // Ż�� ����
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    fill(&Fire[0][0], &Fire[MAX_N - 1][MAX_N], INT_MAX);
    fill(&Jihoon[0][0], &Jihoon[MAX_N - 1][MAX_N], -1);
    cin >> R >> C;

    for (int i = 0; i < R; i++) { // y
        for (int j = 0; j < C; j++) { // x
            char condition;
            cin >> condition;
            Board[i][j] = condition;
        }
    }

    // �� �ٸ� ������ ������ push �۾�
    for (int i = 0; i < R; i++) { // y
        for (int j = 0; j < C; j++) { // x
            if (Board[i][j] == 'F') {
                Fire_Q.push(make_pair(j, i));
                Fire[i][j] = 0;
            }
            else if (Board[i][j] == 'J') {
                Jihoon_Q.push(make_pair(j, i));
                Jihoon[i][j] = 0;
            }
        }
    }

    if (!Fire_Q.empty()) // ���� �ִ� ���
        bfs_fire();
    int answer = bfs_jihoon();
    if (answer == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << answer;
    return 0;
}