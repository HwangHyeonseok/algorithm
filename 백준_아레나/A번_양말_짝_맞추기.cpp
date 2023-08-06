// 구현 : 배열 인덱스를 활용한 구현

// 양말 5개가 주어집니다. 각 양말에는 숫자가 하나씩 쓰여있습니다. 
// 같은 숫자가 쓰인 양말 두 개를 모으면 양말 한 쌍이 됩니다.

// 쌍을 만들 수 있는 양말을 두 개씩 두 쌍 빼면 남는 양말에 쓰인 숫자는 무엇인가요?
#include <iostream>

using namespace std;
#define SOCKS_NUM 10  // 양말의 최대 숫자 번호는 9 (0~9)
#define SOCKS_COUNT 5    // 양말 개수는 5개

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