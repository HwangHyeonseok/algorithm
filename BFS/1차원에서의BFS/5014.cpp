// BFS - 1����
// ���� ��� for�� ��ũ�� ���

#include <iostream>
#include <queue>

using namespace std;
#define MAX_F 1000001 // F�� �ִ� : 1000000
int Board[MAX_F]; 
    // �ִ�ǹ����� : F, ���� �ִ� ��ġ(������ġ) S, ������ G
    // ���� U��, �Ʒ��� D������ ���� ��ư
int F,S,G,U,D;


void bfs(int start, int goal, int up, int down) {
    queue<int> q;
    q.push(start);
    Board[start] = 1;

    while(!q.empty()) {
        int cur_x = q.front();
        q.pop();

        if(cur_x == goal) { // ��ǥ ������ �����ߴٸ�
            cout << Board[cur_x] - 1;
            return;
        }
        
        for(int next : {cur_x+up,cur_x-down}) {
            if(next > F || next < 1) continue; // �� ���� �� �˻�
            if(Board[next] != 0) continue; // �̹� �湮�� ��ģ ���
            
            q.push(next);
            Board[next] = Board[cur_x]+1;
        }
    }
    // ���������ͷ� ������ �� ���� ��ġ�� ���
    cout << "use the stairs";
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> F >> S >> G >> U >> D; 
    bfs(S, G, U, D);
    
    return 0;
}