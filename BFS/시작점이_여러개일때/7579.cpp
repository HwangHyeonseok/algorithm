// 시작점이 여러개인 BFS + 3차원 배열

// 꼭 인덱스의 역할을 정하고 출발하기
// 이 문제에서는 [z][y][x] 위치이다.

#include <iostream>
#include <queue>
#include <algorithm> // fill 사용
#include <tuple> // tuple 사용

using namespace std;

#define MAX_N 101  // M,N,H는 최대 100까지
int M,N,H;
int Board[MAX_N][MAX_N][MAX_N]; // 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸

queue< tuple<int, int, int> > Q; // BFS 보조 큐

void bfs() {
    // 상하좌우 위아래 구현을 위한 배열
    int dx[6] = {-1, 1, 0, 0, 0, 0};
    int dy[6] = {0, 0, -1, 1, 0, 0};
    int dz[6] = {0, 0, 0, 0, -1, 1}; 
    
    while(!Q.empty()) {
        int cur_x = get<0>(Q.front());
        int cur_y = get<1>(Q.front());
        int cur_z = get<2>(Q.front());
        Q.pop();

        for(int i=0; i<6; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            int next_z = cur_z + dz[i];

            // 판자 범위 안에 있는지 먼저 체크 + 아직 덜익은 토마토에 해당하는지 체크
            if(next_x >= M || next_x < 0 || next_y >= N || next_y < 0 || next_z >= H || next_z < 0) continue;
            if(Board[next_z][next_y][next_x] != 0) continue;
            
            Q.push({next_x, next_y, next_z});
            Board[next_z][next_y][next_x] = Board[cur_z][cur_y][cur_x] + 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    fill(&Board[0][0][0], &Board[MAX_N-1][MAX_N-1][MAX_N], -1); // Board 배열 모두 -1로 초기화 
    int answer = 0;

    cin >> M >> N >> H; // M : x포지션, N : y포지션, H : z포지션
    // 토마토 상태 입력받기
    for(int i=0; i<H; i++) { // z
        for(int j=0; j<N; j++) { // y
            for(int k=0; k<M; k++) { // x
                int condition;
                cin >> condition;
                Board[i][j][k] = condition;
            }
        }
    }
    // 토마토가 익은 것은 모두 push하여 bfs 순회
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(Board[i][j][k] == 1) 
                    Q.push(make_tuple(k,j,i)); // x,y,z로 보낸다.
            }
        }
    }

    bfs();

    // 안익은 토마토가 없는지 체크 + 이동 횟수 구하기
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(Board[i][j][k] == 0) {
                    cout << "-1";
                    return 0;
                }
                else {
                    answer = max(answer, Board[i][j][k]);
                }

            }
        }
    }

    cout << answer - 1 ;
    return 0;
}