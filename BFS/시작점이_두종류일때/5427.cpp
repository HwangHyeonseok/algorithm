// 시작점이 두 종류(불과 사람)인 BFS

// 인덱스 문제 !!
// 저장하는 배열의 인덱스는 [y][x] 로, x축은 C, y축은 R, 큐의 pair의 make_pair은 (x,y)

// 결론(중요) : 배열의 인덱스의 x,y 위치를 정해주고, pair의 x,y 위치를 정해준다.
// 그리고 입력받는 변수들은 pair을 따라간다.

#include <iostream>
#include <queue>
#include <climits> // C++에서 INT_MAX 사용

using namespace std;
#define MAX_WH 1001 // 최대 W와 H는 1000
char Board[MAX_WH][MAX_WH];
int Board_fire[MAX_WH][MAX_WH];
int Board_human[MAX_WH][MAX_WH];

int testcase, w,h; // 테스트 케이스, 빌딩의 너비, 높이

queue < pair<int, int> > queue_fire;
queue < pair<int, int> > queue_human;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// 불에 대한 bfs
void bfs_fire() {
    while(!queue_fire.empty()) {
        int cur_x = queue_fire.front().first; // w
        int cur_y = queue_fire.front().second; // h
        queue_fire.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= w || next_x <0 || next_y >= h || next_y < 0) continue; // 맵 범위 밖인 경우 이동할 수 없다.
            if(Board_fire[next_y][next_x] != INT_MAX) continue; // 불이 이미 방문한 경우 이동할 수 없다.
            if(Board[next_y][next_x] == '#') continue; // 벽인 경우 이동할 수 없다.

            queue_fire.push({next_x, next_y});
            Board_fire[next_y][next_x] = Board_fire[cur_y][cur_x] + 1;
        }
    }
}

// 사람(상근)에 대한 bfs
void bfs_human() {
    while(!queue_human.empty()) {
        int cur_x = queue_human.front().first; // w
        int cur_y = queue_human.front().second; // h
        queue_human.pop();

        // 빌딩을 탈출한 경우
        if(cur_x == w-1 || cur_x == 0 || cur_y == h-1 || cur_y == 0) {
            cout << Board_human[cur_y][cur_x] + 1 << "\n";
            return;
        }

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= w || next_x <0 || next_y >= h || next_y < 0) continue; // 맵 범위 밖인 경우
            if(Board_human[next_y][next_x] != -1) continue; // 상근이가 이미 방문한 경우 이동할 수 없다. (다시 되돌아오는 것은 최단거리가 아니기 때문)
            if(Board[next_y][next_x] == '#') continue; // 벽인 경우 이동할 수 없다.
            if(Board_fire[next_y][next_x] <= (Board_human[cur_y][cur_x] + 1)) continue; // (불의 이동 횟수) <= (사람의 이동 횟수)인 경우 이미 불이 도착했으므로 사람이 이동할 수 없는 영역이 된다.
            
            queue_human.push({next_x, next_y});
            Board_human[next_y][next_x] = Board_human[cur_y][cur_x] + 1;
        }
    }
    // 빌딩에 탈출하지 못한 경우
    cout << "IMPOSSIBLE\n"; 
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> testcase;

    for(int i=0; i<testcase; i++) {
        // Board_fire, Board_human 초기화
        fill(&Board_fire[0][0], &Board_fire[MAX_WH-1][MAX_WH], INT_MAX); // Board_fire 배열 int 최댓값으로 초기화 -> (불의 이동 횟수 > 상근이의 이동 횟수)인 칸에 이동이 가능하므로 불이 없는 경우를 고려하였다.
        fill(&Board_human[0][0], &Board_human[MAX_WH-1][MAX_WH], -1);
        // queue_fire, queue_human 초기화
        while(!queue_fire.empty()) {
            queue_fire.pop();
        }
        while(!queue_human.empty()) {
            queue_human.pop();
        }

        // 입력
        cin >> w >> h;
        for(int i=0; i<h; i++) { // y
            for(int j=0; j<w; j++) { // x
                cin >> Board[i][j]; // [y][x]
            }
        }

        // 불의 bfs를 먼저 구한다. (각 칸의 최소 이동 횟수)
        // 주의 : 단, 불은 여러개 일 수도 있다.
        
        
        for(int i=0; i<h; i++) { // y
            for(int j=0; j<w; j++) { // x
                // 모든 불을 찾아 큐에 push 해주고 불의 bfs을 진행한다.
                if(Board[i][j] == '*') {
                    queue_fire.push(make_pair(j,i)); // make_pair(x,y);
                    Board_fire[i][j] = 0;
                }
                // 사람의 위치를 찾아 큐에 push 해주고 사람에 대해 bfs을 진행한다.
                else if(Board[i][j] == '@') {
                    queue_human.push(make_pair(j,i));
                    Board_human[i][j] = 0;
                }
            }
        }
        bfs_fire();
        bfs_human();
    }
    return 0;
}