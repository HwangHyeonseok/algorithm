// BFS - 두 종류의 시작점

// 불의 전파와 지훈이의 이동을 BFS로 각각 따로 따져주어야 한다.
// 각 위치의 (불의 전파 시간 > 지훈이의 이동 가능 시간) 이어야 지훈이가 이동이 가능한 위치이다.

#include <iostream>
#include <queue>
#include <climits> // INT_MAX use

using namespace std;

#define MAX_N 1001 // 맵의 최대 행과 열의 개수
int R, C;
char Board[MAX_N][MAX_N];
int Jihoon[MAX_N][MAX_N];
int Fire[MAX_N][MAX_N];
queue< pair<int, int> > Jihoon_Q;
queue <pair<int, int> > Fire_Q;
// 이동 구현
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

// 불에 대한 bfs
void bfs_fire() {
    int cur_x = Fire_Q.front().first;
    int cur_y = Fire_Q.front().second;
    Fire[cur_y][cur_x] = 0;

    while (!Fire_Q.empty()) {
        cur_x = Fire_Q.front().first;
        cur_y = Fire_Q.front().second;
        Fire_Q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // 맵 범위 검사
            if (next_x >= C || next_x < 0 || next_y >= R || next_y < 0) continue;
            if (Board[next_y][next_x] == '#') continue; // 벽인 경우
            if (Fire[next_y][next_x] != INT_MAX) continue; // 이미 불이 방문한 경우

            Fire[next_y][next_x] = Fire[cur_y][cur_x] + 1;
            Fire_Q.push({ next_x,next_y });
        }
    }
}

// 지훈이에 대한 bfs
int bfs_jihoon() {
    int cur_x = Jihoon_Q.front().first;
    int cur_y = Jihoon_Q.front().second;
    Jihoon[cur_y][cur_x] = 0;

    while (!Jihoon_Q.empty()) {
        cur_x = Jihoon_Q.front().first;
        cur_y = Jihoon_Q.front().second;
        Jihoon_Q.pop();

        // 탈출 조건에 해당하는 경우 탈출한다.
        if (cur_x == 0 || cur_x == C - 1 || cur_y == 0 || cur_y == R - 1) {
            return Jihoon[cur_y][cur_x] + 1;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // 맵 범위 검사
            if (next_x >= C || next_x < 0 || next_y >= R || next_y < 0) continue;
            if (Board[next_y][next_x] == '#') continue; // 벽인 경우
            if (Jihoon[next_y][next_x] != -1) continue; // 지훈이가 이미 방문한 경우
            if ((Jihoon[cur_y][cur_x] + 1) >= Fire[next_y][next_x]) continue; // 불이 이미 지나간 경우

            Jihoon[next_y][next_x] = Jihoon[cur_y][cur_x] + 1;
            Jihoon_Q.push({ next_x,next_y });
        }
    }
    return -1; // 탈출 실패
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

    // 각 다른 종류의 시작점 push 작업
    for (int i = 0; i < R; i++) { // y
        for (int j = 0; j < C; j++) { // x
            if (Board[i][j] == 'F') {
                Fire_Q.push(make_pair(j, i));
            }
            else if (Board[i][j] == 'J') {
                Jihoon_Q.push(make_pair(j, i));
            }
        }
    }

    if (!Fire_Q.empty()) // 불이 있는 경우
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