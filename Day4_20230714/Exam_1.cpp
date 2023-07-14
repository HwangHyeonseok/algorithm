//#그리디->규칙성 찾기 #정렬 #문자열 파싱 #숫자<->문자열 변환 스킬
// 체감 난이도 : 백준 S4

// 남은 시간 : 2시간 -> 1시간 32분 54초 (27분 6초 소요)

//---------------------------문제 조건---------------------------
// 입력 : 숫자 문자열 S, 제거할 숫자의 개수 X
// 출력 : 조건을 만족하는 수 중 가장 큰 수
// "가장 큰 수" 의 유형은 파라메트릭 서치, 그리디를 의심해볼만 하다.

// 정렬이 들어가는 유형이면 그리디일 가능성이 높다.

// ---------------------------아이디어 ---------------------------
// 1) 어째든 가장 큰 수를 만족하기 위해서는 제거하는 숫자는 무조건 작은 수들을 제거해야 할 것이다.
// ==> 정렬을 해서 그 갯수만큼 제거를 해야하므로 그리디

// 2) 그 다음에 남은 수들 중 정렬을 하여 큰 수부터 가장 높은 자리 수에 배치되도록 하면 정답이다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string input_str_num;
    vector<int> numbers;
    int del_num;
    
    cout << "숫자를 입력하세요 : ";
    getline(cin, input_str_num); // 숫자를 문자열로 입력받는다.
    cout << "제거할 숫자 입력 : ";
    cin >> del_num; // 제거할 숫자를 입력받는다.
    
    // 각 문자를 숫자로 추출한다.
    for(int i=0; i<input_str_num.size(); i++) {
        int num = input_str_num[i] - '0'; // 아스키코드를 이용하여 문자 -> 숫자로 바꾸는 테크닉
        numbers.push_back(num);
    }
    
    // 아이디어 1) 작은 수들을 제거하기 위한 작업 
    sort(numbers.begin(), numbers.end()); // 1 2 3 4 5
    for(int i=0; i<del_num; i++) {
        numbers.erase(numbers.begin()); // 매 회차마다 가장 작은 원소를 지운다. (지울 원소 입력한 개수만큼) 
    }

    // 아이디어 2) 남은 수들을 정렬해서 가장 높이가 큰 순서대로 출력한다.
    sort(numbers.begin(), numbers.end(), greater<>()); // 5 4 3 
    for(int i=0; i<numbers.size(); i++) {
        cout << to_string(numbers[i]);
    }
    
    return 0;
}

// ------------------------ testcase -----------------------
// 1942 / 2개 제거 -> 94
// 1234 / 2개 제거 -> 43
// 5838428 / 4개 제거 -> 888