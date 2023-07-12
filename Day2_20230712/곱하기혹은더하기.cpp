// # 그리디
// 참고 ref : https://royhelen.tistory.com/28
// 0 아스키코드 48, 9 아스키코드 57
// 숫자 하나만을 입력받는 타입, 문자열 처리 ★
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    int answer = 1;
    string x;
    vector<int> mult;
    vector<int> plus;

    cin >> x;
    for (int i = 0; i < x.length(); i++) {
        int num = x[i] - 48;
        if (num == 0 || num == 1) {
            plus.push_back(num);
        }   
        else {
            mult.push_back(num);
        }
    }

    for (int i = 0; i < mult.size(); i++) {
        answer *= mult[i];
    }
    for (int j = 0; j < plus.size(); j++) {
        answer += plus[j];
    }

    cout << answer;
    return 0;
}