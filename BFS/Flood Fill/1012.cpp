// BFS - Flood Fill의 개수 세기 유형 + 시작점이 여러개인 유형

#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 51 // N,M의 최댓값은 50
int Board[MAX_N][MAX_N];  // 이동 가능 : 1
int T, M, N, K; // 테스트 케이스 개수, 배추밭의 가로길이, 세로길이, 배추가 심어져 있는 개수

void bfs(int start_x, int start_y) {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1}; 
    queue< pair<int, int> > q;
    
    q.push(make_pair(start_x, start_y));
    Board[start_x][start_y] = 0;

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= M || next_x < 0 || next_y >= N || next_y < 0) continue; // 맵 범위 밖인 경우
            if(Board[next_x][next_y] != 1) continue; // 배추가 있는 곳이 아닌 경우

            q.push({next_x, next_y});
            Board[next_x][next_y] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int answer; // 최소 배추흰지렁이 마릿수 (정답)

    cin >> T;
    for(int i=0; i<T; i++) {
        answer = 0;
        cin >> M >> N >> K;
        for(int i=0; i<K; i++) {
            int X,Y; // 배추의 위치 X,Y
            cin >> X >> Y;
            Board[X][Y] = 1;
        }
        
        // 시작점 탐색
        for(int i=0; i<M; i++) { // x
            for(int j=0; j<N; j++) { // y
                if(Board[i][j] == 1) {
                    bfs(i,j);
                    answer++;
                }
            }
        }

        cout << answer << "\n";
    }
    return 0;
}