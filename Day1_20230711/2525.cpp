// 시간 구현 기초
// 1-1. 현재 시간의 분과 더할 분을 합쳐서 60 미만이면 -> 그대로 더한 값 출력
// 1-2. 현재 시간의 분과 더할 분을 합쳐서 60 이상이면
// 합한 분의 값이 60 미만이 될 때까지 시간을 +1 하고, 분을 -60한다.

// 예외조건 : 23시를 넘어가면 0시로 되돌아가야 함.

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int min; // 분
    int hour; // 시간
    int plus_min; // 더할 시간

    cin >> hour >> min;
    cin >> plus_min;
    min = min+plus_min;

    while(min >= 60) {
        hour++; 
        min-=60;
        if(hour>=24) {
            hour -= 24;
        }
    }
    
    cout << hour << " " << min;
    
    return 0;
}