// 시작점이 여러개인 BFS + 두 종류를 따로 따져야하는 BFS

// 새롭게 알게 된 것 : char 배열은 전역에서 초기화하지 않으면 뭘로 초기화되는가?
#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 101 // 최대 N : 100
char Board[MAX_N][MAX_N];
char Board_weakness[MAX_N][MAX_N]; // 적록색약용 
int N;
// 비적록색약 bfs
void bfs(int start_x, int start_y, char color) {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    queue< pair<int, int> > q;
    
    q.push(make_pair(start_x, start_y));
    Board[start_x][start_y] = 'D'; // 그렸다는 의미의 Draw 약자
    
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x >= N || next_x < 0 || next_y >= N || next_y < 0) continue;
            if(Board[next_x][next_y] != color) continue; 

            q.push({next_x, next_y});
            Board[next_x][next_y] = 'D';
        }
    }
}
// 적록색약 bfs
void bfs_weakness(int start_x, int start_y, char color) {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    queue< pair<int, int> > q;
    
    q.push(make_pair(start_x, start_y));
    Board_weakness[start_x][start_y] = 'D'; // 그렸다는 의미의 Draw 약자
    
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x >= N || next_x < 0 || next_y >= N || next_y < 0) continue;
            if(Board_weakness[next_x][next_y] != color) continue; 

            q.push({next_x, next_y});
            Board_weakness[next_x][next_y] = 'D';
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int non_colorweakness = 0; // 색약이 아닌 사람
    int colorweakness  = 0; // 색약인 사람 색상 개수

    cin>> N;

    for(int i=0; i<N; i++) { // x
        for(int j=0; j<N; j++) { // y
            char color;
            cin >> color;
            Board[i][j] = color; // 비 적록색약
            // 적록색약은 빨강과 초록을 같은 것으로 취급한다.
            if(color == 'G') {
                Board_weakness[i][j] = 'R';
                continue;
            }
            Board_weakness[i][j] = color; // 적록색약
        }
    }
    
    // R,G,B가 있다면 찾아서 모두 bfs 탐색 (비 적록색약 입장)
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(Board[i][j] == 'R' || Board[i][j] == 'G' || Board[i][j] == 'B') {
                bfs(i,j,Board[i][j]);
                non_colorweakness++;
            }
        }
    }

    // R,G,B가 있다면 찾아서 모두 bfs 탐색 (적록색약 입장)
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(Board_weakness[i][j] == 'R' || Board_weakness[i][j] == 'B') {
                bfs_weakness(i,j,Board_weakness[i][j]);
                colorweakness++;
            }
        }
    }

    cout << non_colorweakness << " " << colorweakness;
    return 0;
}