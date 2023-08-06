// BFS - 시작점이 두 종류 + 시작점이 여러개일때

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX_N 301 // N과 M이 300이하이다.

int N, M;
int height[MAX_N][MAX_N]; // 빙산의 높이 정보
int visited[MAX_N][MAX_N]; // 1) 빙산 점검 중 방문 가능 체크 (방문가능 : 1, 방문불가능 : 0)
queue< pair<int, int> > left_bingsan; // 2) 남은 빙산의 좌표 정보를 가지고 있는 큐

// 1) 빙산을 점검 -> 돌아다니면서 2덩어리 이상이 나오는지? (bfs_count_bingsan)
void bfs_count_bingsan(int start_x, int start_y) {
    queue< pair<int, int> > q;

    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };

    q.push(make_pair(start_x, start_y));
    visited[start_y][start_x] = 0;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= M || next_y >= N || next_x < 0 || next_y < 0) continue;
            if (height[next_y][next_x] <= 0) continue;
            if (visited[next_y][next_x] != 1) continue;

            q.push({ next_x,next_y });
            visited[next_y][next_x] = 0;
        }
    }

}
// 2) 빙산 녹는 것을 구현 (bfs_remove_bingsan)
void bfs_remove_bingsan() {
    int height_tmp[MAX_N][MAX_N];
    copy(&height[0][0], &height[0][0]+(MAX_N*MAX_N), &height_tmp[0][0]); // height 정보를 height_tmp에 복사
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    
    while(!left_bingsan.empty()) {
        int cur_x = left_bingsan.front().first;
        int cur_y = left_bingsan.front().second;
        left_bingsan.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (height[cur_y][cur_x] == 0) break; // 높이가 0이 되어버린 경우 빠져나온다.

            if (next_x >= M || next_y >= N || next_x < 0 || next_y < 0) continue;
            if (height_tmp[next_y][next_x] != 0) continue;

            height[cur_y][cur_x] = height[cur_y][cur_x] - 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int bingsan_count = 0; // 빙산 개수 체크  
    int year_count = 0; // 빙산이 2개 이상이 될 때까지 걸린 시간
    cin >> N >> M;

    for (int i = 0; i < N; i++) { // y ** 문제에서 주어진 입력받는 순서대로 입력 받을 것
        for (int j = 0; j < M; j++) { // x
            cin >> height[i][j];
        }
    }

    while (1) {
        bingsan_count = 0; // 빙산 개수 체크  

        // 사전 작업 : 방문 가능 영역 체크
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (height[i][j] > 0) { // 빙산 높이가 0보다 크면 방문 가능 영역으로 지정
                    visited[i][j] = 1;
                }
            }
        }

        // 1) 빙산을 점검 -> 돌아다니면서 2덩어리 이상이 나오는지? (bfs_count_bingsan)
        for (int i = 0; i < N; i++) { // y
            for (int j = 0; j < M; j++) { // x
                if (visited[i][j] == 1) { // 연결된 모든 빙산을 체크
                    bfs_count_bingsan(j, i); // (x,y)
                    bingsan_count++;
                }
            }
        }

        // 만약 빙산 개수가 2개 이상이면 정답을 출력하고 프로그램을 종료한다.
        if (bingsan_count >= 2) {
            cout << year_count;
            return 0;
        }
        // 남은 빙산이 없는 경우 0 출력 후 프로그램을 종료한다.
        else if (bingsan_count == 0) {
            cout << "0";
            return 0;
        }

        // 2) 빙산 녹는 것을 구현 (bfs_remove_bingsan)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (height[i][j] > 0) {
                    left_bingsan.push(make_pair(j,i));
                }
            }
        }
        bfs_remove_bingsan();//(x,y)

        // 3) 빙산을 1년차 모두 제거했다.
        year_count++;
    }

    return 0;
}