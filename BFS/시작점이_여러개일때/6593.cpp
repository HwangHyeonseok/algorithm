// BFS - 시작점이 여러개 + 3차원 + 
// 인덱스 정하기 : [z][y][x] 로 정하고 dfs,튜플 호출 시에는 (x,y,z)로 보낸다.

#include <queue>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
#define MAX_N 31 // L, R, C 모두 최대 30
char Board[MAX_N][MAX_N][MAX_N];
int MovingBoard[MAX_N][MAX_N][MAX_N];

int L,R,C; // L : z축 / R : y축 / C : x축 개수
queue< tuple<int, int, int> > q;

int bfs(int escape_x, int escape_y, int escape_z) {
    int dx[6] = {-1,1,0,0,0,0};
    int dy[6] = {0,0,-1,1,0,0};
    int dz[6] = {0,0,0,0,-1,1};

    while(!q.empty()) {
        int cur_x = get<0>(q.front());
        int cur_y = get<1>(q.front());
        int cur_z = get<2>(q.front());
        q.pop();
        if(cur_x == escape_x && cur_y == escape_y && cur_z == escape_z) { // 도착 지점으로 도착 시
            return MovingBoard[cur_z][cur_y][cur_x];
        }

        for(int i=0; i<6; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            int next_z = cur_z + dz[i];

            if(next_x >= C || next_y >= R || next_z >= L || next_x<0 || next_y<0 || next_z<0) continue;
            if(MovingBoard[next_z][next_y][next_x] != -1) continue;
            if(Board[next_z][next_y][next_x] == '#') continue;
            
            // 조건에 모두 해당되는 경우에는 push
            q.push({next_x, next_y, next_z});
            MovingBoard[next_z][next_y][next_x] = MovingBoard[cur_z][cur_y][cur_x] + 1;
        }
    }
    return -1;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while(1) {
        cin >> L >> R >> C;
        int minutes = -1;
        fill(&MovingBoard[0][0][0], &MovingBoard[MAX_N-1][MAX_N-1][MAX_N], -1); // 미방문시 -1

        if((L==0) && (R==0) && (C==0)) break;
        // 입력
        for(int i=0; i<L; i++) { // z
            for (int j=0; j<R; j++) { // y
                for(int k=0; k<C; k++) { // x
                    cin >> Board[i][j][k]; // [z][y][x]로 입력받음
                    if(Board[i][j][k] == 'S') { // 시작 위치
                        q.push(make_tuple(k,j,i)); // x,y,z으로 보낸다.
                        MovingBoard[i][j][k] = 0;
                    }
                }
            }
        }
        
        // 탈출 위치가 조회되면 bfs 실행
        for(int i=0; i<L; i++) { // z
            for (int j=0; j<R; j++) { // y
                for(int k=0; k<C; k++) { // x
                    if(Board[i][j][k] == 'E') { // 탈출 위치
                        minutes = bfs(k,j,i); // x,y,z로 보낸다.
                    }
                }
            }
        }
        if(minutes == -1) { // 탈출할 방법이 없는 경우
            cout << "Trapped!\n";
        }
        else { // 탈출에 성공한 경우
            cout << "Escaped in " << minutes << " minute(s).\n";
        }
        while(!q.empty()) { q.pop(); }
    }


    return 0;
}