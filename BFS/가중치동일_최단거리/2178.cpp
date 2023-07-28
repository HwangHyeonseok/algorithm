// BFS - 최단거리

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 101 // 최대 크기 100
int row, col;
int Board[MAX_N][MAX_N]; // 이동 가능 : 1

void bfs(int start_x, int start_y) {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    queue< pair<int, int> > Q;
    
    // 첫 위치 push + 방문 처리
    Q.push(make_pair(start_x, start_y));
    Board[start_x][start_y] = 2; // movecount 로 칠해준다. (처음을 2로 칠했으므로 마지막에서 최종 이동거리에서 1을 빼준다.)

    while(!Q.empty()) {
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // 맵 범위 밖으로 나갔는지 먼저 검사
            if(next_x >= row || next_x < 0 || next_y >= col || next_y < 0) continue;
            if(Board[next_x][next_y] != 1) continue;

            Q.push({next_x, next_y});
            Board[next_x][next_y] = Board[cur_x][cur_y]+1;
        }
    }
    cout << Board[row-1][col-1] - 1;
}

int main(void) {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); // [오답노트] C와 C++ 입출력 문법을 혼용하여 사용 시 이 구문을 사용하면 안된다.
    cin >> row >> col;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            int condition;
            scanf("%1d", &condition);
            Board[i][j] = condition;
        }
    }
    
    bfs(0,0);

    return 0;
}