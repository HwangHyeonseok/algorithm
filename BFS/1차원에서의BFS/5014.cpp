// BFS - 1차원
// 범위 기반 for문 테크닉 사용

#include <iostream>
#include <queue>

using namespace std;
#define MAX_F 1000001 // F의 최댓값 : 1000000
int Board[MAX_F]; 
    // 최대건물높이 : F, 지금 있는 위치(시작위치) S, 목적지 G
    // 위로 U층, 아래로 D층으로 가는 버튼
int F,S,G,U,D;


void bfs(int start, int goal, int up, int down) {
    queue<int> q;
    q.push(start);
    Board[start] = 1;

    while(!q.empty()) {
        int cur_x = q.front();
        q.pop();

        if(cur_x == goal) { // 목표 지점에 도달했다면
            cout << Board[cur_x] - 1;
            return;
        }
        
        for(int next : {cur_x+up,cur_x-down}) {
            if(next > F || next < 1) continue; // 맵 범위 밖 검사
            if(Board[next] != 0) continue; // 이미 방문을 마친 경우
            
            q.push(next);
            Board[next] = Board[cur_x]+1;
        }
    }
    // 엘레베이터로 도달할 수 없는 위치인 경우
    cout << "use the stairs";
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> F >> S >> G >> U >> D; 
    bfs(S, G, U, D);
    
    return 0;
}