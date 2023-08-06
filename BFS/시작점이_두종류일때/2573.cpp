// BFS - �������� �� ���� + �������� �������϶�

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX_N 301 // N�� M�� 300�����̴�.

int N, M;
int height[MAX_N][MAX_N]; // ������ ���� ����
int visited[MAX_N][MAX_N]; // 1) ���� ���� �� �湮 ���� üũ (�湮���� : 1, �湮�Ұ��� : 0)
queue< pair<int, int> > left_bingsan; // 2) ���� ������ ��ǥ ������ ������ �ִ� ť

// 1) ������ ���� -> ���ƴٴϸ鼭 2��� �̻��� ��������? (bfs_count_bingsan)
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
// 2) ���� ��� ���� ���� (bfs_remove_bingsan)
void bfs_remove_bingsan() {
    int height_tmp[MAX_N][MAX_N];
    copy(&height[0][0], &height[0][0]+(MAX_N*MAX_N), &height_tmp[0][0]); // height ������ height_tmp�� ����
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    
    while(!left_bingsan.empty()) {
        int cur_x = left_bingsan.front().first;
        int cur_y = left_bingsan.front().second;
        left_bingsan.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (height[cur_y][cur_x] == 0) break; // ���̰� 0�� �Ǿ���� ��� �������´�.

            if (next_x >= M || next_y >= N || next_x < 0 || next_y < 0) continue;
            if (height_tmp[next_y][next_x] != 0) continue;

            height[cur_y][cur_x] = height[cur_y][cur_x] - 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int bingsan_count = 0; // ���� ���� üũ  
    int year_count = 0; // ������ 2�� �̻��� �� ������ �ɸ� �ð�
    cin >> N >> M;

    for (int i = 0; i < N; i++) { // y ** �������� �־��� �Է¹޴� ������� �Է� ���� ��
        for (int j = 0; j < M; j++) { // x
            cin >> height[i][j];
        }
    }

    while (1) {
        bingsan_count = 0; // ���� ���� üũ  

        // ���� �۾� : �湮 ���� ���� üũ
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (height[i][j] > 0) { // ���� ���̰� 0���� ũ�� �湮 ���� �������� ����
                    visited[i][j] = 1;
                }
            }
        }

        // 1) ������ ���� -> ���ƴٴϸ鼭 2��� �̻��� ��������? (bfs_count_bingsan)
        for (int i = 0; i < N; i++) { // y
            for (int j = 0; j < M; j++) { // x
                if (visited[i][j] == 1) { // ����� ��� ������ üũ
                    bfs_count_bingsan(j, i); // (x,y)
                    bingsan_count++;
                }
            }
        }

        // ���� ���� ������ 2�� �̻��̸� ������ ����ϰ� ���α׷��� �����Ѵ�.
        if (bingsan_count >= 2) {
            cout << year_count;
            return 0;
        }
        // ���� ������ ���� ��� 0 ��� �� ���α׷��� �����Ѵ�.
        else if (bingsan_count == 0) {
            cout << "0";
            return 0;
        }

        // 2) ���� ��� ���� ���� (bfs_remove_bingsan)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (height[i][j] > 0) {
                    left_bingsan.push(make_pair(j,i));
                }
            }
        }
        bfs_remove_bingsan();//(x,y)

        // 3) ������ 1���� ��� �����ߴ�.
        year_count++;
    }

    return 0;
}