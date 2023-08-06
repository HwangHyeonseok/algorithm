// ���� : �迭 �ε����� Ȱ���� ����

// �縻 5���� �־����ϴ�. �� �縻���� ���ڰ� �ϳ��� �����ֽ��ϴ�. 
// ���� ���ڰ� ���� �縻 �� ���� ������ �縻 �� ���� �˴ϴ�.

// ���� ���� �� �ִ� �縻�� �� ���� �� �� ���� ���� �縻�� ���� ���ڴ� �����ΰ���?
#include <iostream>

using namespace std;
#define SOCKS_NUM 10  // �縻�� �ִ� ���� ��ȣ�� 9 (0~9)
#define SOCKS_COUNT 5    // �縻 ������ 5��

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int socks_num[SOCKS_NUM];
    fill(&socks_num[0], &socks_num[SOCKS_NUM], 0);
 
    for(int i=0; i<SOCKS_COUNT; i++) {
        int num;
        cin >> num;
        socks_num[num]++;
    }

    for(int i=0; i<SOCKS_NUM; i++) {
        if(socks_num[i] == 1) {
            cout << i;
            return 0;
        }
    }

    return 0;
}