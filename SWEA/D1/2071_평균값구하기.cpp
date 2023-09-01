// 헷갈렸던 점 : 반올림 구현 방법
#include <iostream>
#include <math.h>

using namespace std;

#define MAX_N 10.0 // 최대 10개까지만 입력받는다.

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int iter;

    cin >> iter;

    for(int i=1; i<=iter; i++) {
        float sum = 0;
        for(int j=0; j<MAX_N; j++) {
            float num = 0;
            cin >> num;
            sum += num;
        }
        
        cout << "#" << i << " " << round(sum/MAX_N) << "\n"; 
    }
    return 0;
}