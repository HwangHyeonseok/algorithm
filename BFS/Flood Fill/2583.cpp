// BFS - Flood Fill 유형 + 시작점이 여러개 + 입력 형식이 독특한 유형 (BFS의 역연산)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 101 // M,N은 최대 100
int Board[MAX_N][MAX_N]; // 1 : bfs 탐색 불가능(벽)
int M,N,K; // M×N(맵의 범위), k는 직사각형 개수

vector<int> areas; // 각 영역의 넓이

int bfs(int start_x, int start_y) {
    int area = 0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    queue< pair<int, int> > q;
    
    q.push(make_pair(start_x, start_y)); // 큐도 x,y
    Board[start_y][start_x] = 1;
    area++;

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        area++;

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= N || next_x < 0 || next_y >= M || next_y < 0) continue;
            if(Board[next_y][next_x] != 0) continue; // 이미 방문한 경우

            q.push({next_x, next_y});
            Board[next_y][next_x] = 1;
        }

    }
    return area;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int answer = 0; // 분리되어 나누어지는 영역의 개수
        // 입력
    cin >> M >> N >> K;
    for(int i=0; i<K; i++) {
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;
        for(int j=start_y; j< end_y; j++) { // y
            for(int k=start_x; k< end_x; k++) { // x
                Board[j][k] = 1; // 벽으로 간주 | 배열은 : [y][x]
            }
        }
    }

    // bfs 순회 위치 찾기 : 
    for(int i=0; i<M; i++) { // y
        for(int j=0; j<N; j++) { //x
            if(Board[i][j] == 0) {
                areas.push_back(bfs(j, i)); // bfs는 (x,y)
                answer++;
            }
        }
    } 

    // 넓이 영역 오름차순 정렬
    sort(areas.begin(), areas.end());

    // 정답 출력
    cout << answer << "\n";
    for(int i=0; i<areas.size(); i++) {
        cout << areas[i] - 1 << " ";
    }
    return 0;
}