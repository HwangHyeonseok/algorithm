// BFS - 시작점이 여러개

// 배열 복사하기 -> copy
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 101 // 최대 N은 100
int N;
int Board[MAX_N][MAX_N]; // 각 높이
int Board_tmp[MAX_N][MAX_N]; // 연산을 위한 임시 복사본

void bfs(int start_x, int start_y, int height) { // height 보다 낮으면 잠긴다.
    queue< pair<int, int> > q;
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };

    q.push(make_pair(start_x, start_y));
    Board_tmp[start_x][start_y] = 0;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= N || next_x < 0 || next_y >= N || next_y < 0) continue;
            if (Board_tmp[next_x][next_y] <= height) continue;

            Board_tmp[next_x][next_y] = 0;
            q.push({ next_x, next_y });
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int maxheight = 0;
    int answer = 1;
    cin >> N;
    // 입력
    for (int i = 0; i < N; i++) { // x
        for (int j = 0; j < N; j++) { // y
            cin >> Board[i][j]; // [x][y]
            maxheight = maxheight > Board[i][j] ? maxheight : Board[i][j];
        }
    }

    for (int i = 1; i <= maxheight; i++) {
        int area = 0;
        copy(&Board[0][0], &Board[0][0] + 10201, &Board_tmp[0][0]);
        // bfs 탐색을 할 위치를 찾는다. - 안전 영역 찾는 과정
        for (int j = 0; j < N; j++) { // x
            for (int k = 0; k < N; k++) { // y
                if (Board_tmp[j][k] > i) {
                    bfs(j, k, i); // (x,y)
                    area++;
                }
            }
        }
        answer = max(answer, area);
    }

    cout << answer;

    return 0;
}