// https://www.acmicpc.net/problem/1541

// #문자열 -> 숫자 파싱, #문자열 #그리디 알고리즘

// 값이 최소가 되려면 - 기호가 나온 이후로는 모든 숫자에 대한 입력을 - 연산을 해주면 된다.
// ex ) 55-50+40 이면, 55-(50+40) = -35 (즉, -가 나온 50과 40 숫자는 부호 관계 없이 모두 마이너스 처리)
// ex ) 55+30+20-30+40+70 이면, -이후인 30,40,70 숫자에 대해 모두 - 연산 처리
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string cal; // 입력받은 계산식
    string s_num="";
    bool minus = false; // minus로 연산하는지 여부
    int last_index = 0;
    int answer = 0;
    cin >> cal;

    for(int i=0; i<cal.size(); i++) {
        if(cal[i] == '-' || cal[i] == '+') {
            // 문자열 -> 숫자 파싱
            for(int j = last_index; j < i; j++) {
                s_num += cal[j];
            }
            last_index = i+1;
        }
        // 숫자가 차였으므로 연산 처리
        if(s_num != "") {
            if(minus == true) answer -= stoi(s_num);
            else if(minus == false) answer += stoi(s_num);
        }

        s_num ="";
        if(cal[i] == '-') minus = true;
    }

    // 마지막 문자 처리
    for(int i=last_index; i<cal.size(); i++) {
        s_num += cal[i];
    }
    if(minus == true) answer -= stoi(s_num);
    else answer += stoi(s_num);

    cout << answer;

    return 0;
}