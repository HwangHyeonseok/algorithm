// #그리디=>배수 규칙 / 배수 판정하기 #정렬 #문자열 추출
// 숫자를 조합해서 30의 배수가 되려면 각 자리수의 합이 3의 배수여야 하고 최소 한 개 이상의 0이 있어야 한다. 
// 30의 배수가 되는 가장 큰 수라고 하였으므로, 현재 있는 수들 중 가장 큰 값을 높은 자릿수에 배치하면 된다.

// 정답 아이디어 : 30의 배수를 판정하려면 10의 배수 && 3의 배수 의 조건에 해당하면 된다.
// 10의 배수 조건 : 0이 있다.
// 3의 배수 조건 : 모든 자리수의 합이 3의 배수여야 한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string input_str_num;
    vector<int> nums;
    int check_sum = 0;
    bool zero_number = false; // 숫자 0이 하나 이상 있는지 체크

    cin >> input_str_num;

    // 문자열 -> 하나하나의 숫자로 추출
    for(int i=0; i<input_str_num.size(); i++) {
        nums.push_back(input_str_num[i]-'0');
    }

    // 각 자릿수의 모든 합이 3의 배수가 되는지 체크 + 숫자 0이 하나 이상 있는지 체크
    for(int i=0; i<nums.size(); i++) {
        check_sum += nums[i];
        if(nums[i] == 0)
            zero_number = true;
    }
    
    // 각 자릿수의 모든 합이 3의 배수가 아니라면 어떤 조합으로도 30의 배수가 나올 수 없다.
    if(check_sum % 3 != 0 || zero_number == false) {
        cout << "-1";
        return 0;
    }
    
    // 각 자릿수의 모든 합이 3의 배수인 경우
    // 30의 배수가 되는 가장 큰 수라고 하였으므로, 현재 있는 수들 중 가장 큰 값을 높은 자릿수에 배치하면 된다.

    sort(nums.begin(), nums.end(), greater<>()); // 4 3 2 1 .. 내림차순 정렬
    
    // 그대로 문자열로 바꾸어서 출력한다.
    for(int i=0; i<nums.size(); i++) {
        cout << to_string(nums[i]); 
    }

    return 0;
}