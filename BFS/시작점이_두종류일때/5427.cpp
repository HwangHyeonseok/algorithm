// �������� �� ����(�Ұ� ���)�� BFS

// �ε��� ���� !!
// �����ϴ� �迭�� �ε����� [y][x] ��, x���� C, y���� R, ť�� pair�� make_pair�� (x,y)

// ���(�߿�) : �迭�� �ε����� x,y ��ġ�� �����ְ�, pair�� x,y ��ġ�� �����ش�.
// �׸��� �Է¹޴� �������� pair�� ���󰣴�.

#include <iostream>
#include <queue>
#include <climits> // C++���� INT_MAX ���

using namespace std;
#define MAX_WH 1001 // �ִ� W�� H�� 1000
char Board[MAX_WH][MAX_WH];
int Board_fire[MAX_WH][MAX_WH];
int Board_human[MAX_WH][MAX_WH];

int testcase, w,h; // �׽�Ʈ ���̽�, ������ �ʺ�, ����

queue < pair<int, int> > queue_fire;
queue < pair<int, int> > queue_human;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

// �ҿ� ���� bfs
void bfs_fire() {
    while(!queue_fire.empty()) {
        int cur_x = queue_fire.front().first; // w
        int cur_y = queue_fire.front().second; // h
        queue_fire.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= w || next_x <0 || next_y >= h || next_y < 0) continue; // �� ���� ���� ��� �̵��� �� ����.
            if(Board_fire[next_y][next_x] != INT_MAX) continue; // ���� �̹� �湮�� ��� �̵��� �� ����.
            if(Board[next_y][next_x] == '#') continue; // ���� ��� �̵��� �� ����.

            queue_fire.push({next_x, next_y});
            Board_fire[next_y][next_x] = Board_fire[cur_y][cur_x] + 1;
        }
    }
}

// ���(���)�� ���� bfs
void bfs_human() {
    while(!queue_human.empty()) {
        int cur_x = queue_human.front().first; // w
        int cur_y = queue_human.front().second; // h
        queue_human.pop();

        // ������ Ż���� ���
        if(cur_x == w-1 || cur_x == 0 || cur_y == h-1 || cur_y == 0) {
            cout << Board_human[cur_y][cur_x] + 1 << "\n";
            return;
        }

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x >= w || next_x <0 || next_y >= h || next_y < 0) continue; // �� ���� ���� ���
            if(Board_human[next_y][next_x] != -1) continue; // ����̰� �̹� �湮�� ��� �̵��� �� ����. (�ٽ� �ǵ��ƿ��� ���� �ִܰŸ��� �ƴϱ� ����)
            if(Board[next_y][next_x] == '#') continue; // ���� ��� �̵��� �� ����.
            if(Board_fire[next_y][next_x] <= (Board_human[cur_y][cur_x] + 1)) continue; // (���� �̵� Ƚ��) <= (����� �̵� Ƚ��)�� ��� �̹� ���� ���������Ƿ� ����� �̵��� �� ���� ������ �ȴ�.
            
            queue_human.push({next_x, next_y});
            Board_human[next_y][next_x] = Board_human[cur_y][cur_x] + 1;
        }
    }
    // ������ Ż������ ���� ���
    cout << "IMPOSSIBLE\n"; 
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> testcase;

    for(int i=0; i<testcase; i++) {
        // Board_fire, Board_human �ʱ�ȭ
        fill(&Board_fire[0][0], &Board_fire[MAX_WH-1][MAX_WH], INT_MAX); // Board_fire �迭 int �ִ����� �ʱ�ȭ -> (���� �̵� Ƚ�� > ������� �̵� Ƚ��)�� ĭ�� �̵��� �����ϹǷ� ���� ���� ��츦 ����Ͽ���.
        fill(&Board_human[0][0], &Board_human[MAX_WH-1][MAX_WH], -1);
        // queue_fire, queue_human �ʱ�ȭ
        while(!queue_fire.empty()) {
            queue_fire.pop();
        }
        while(!queue_human.empty()) {
            queue_human.pop();
        }

        // �Է�
        cin >> w >> h;
        for(int i=0; i<h; i++) { // y
            for(int j=0; j<w; j++) { // x
                cin >> Board[i][j]; // [y][x]
            }
        }

        // ���� bfs�� ���� ���Ѵ�. (�� ĭ�� �ּ� �̵� Ƚ��)
        // ���� : ��, ���� ������ �� ���� �ִ�.
        
        
        for(int i=0; i<h; i++) { // y
            for(int j=0; j<w; j++) { // x
                // ��� ���� ã�� ť�� push ���ְ� ���� bfs�� �����Ѵ�.
                if(Board[i][j] == '*') {
                    queue_fire.push(make_pair(j,i)); // make_pair(x,y);
                    Board_fire[i][j] = 0;
                }
                // ����� ��ġ�� ã�� ť�� push ���ְ� ����� ���� bfs�� �����Ѵ�.
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