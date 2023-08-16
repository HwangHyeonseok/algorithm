// 단순 수학 구현
// 2S - R1 = R2
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int R1,R2;
    int S = 0; // S1,S2의 평균

    cin >> R1 >> S;

    cout << 2*S - R1;
    

    return 0;
}