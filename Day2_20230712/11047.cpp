// #그리디
// 가지고 있는 동전 10종류 / 가치의 합 4200

// 이때 필요한 동전의 개수의 최솟값?

// 동전의 가치를 쓴다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // 가지고 있는 동전 종류
    int sum; // 가지고 있는 동전의 합
    vector<int> money; // 동전 단위를 담는다.
    int answer = 0; // 동전의 개수

// 첫 번째줄 입력
    cin >> N >> sum;
// 동전을 입력받는다.
    for(int i=0; i<N; i++) {
        int PER; // 동전 단위
        cin >> PER;
        money.push_back(PER);
    }
    // 동전 단위대로 sort (내림차순?) 1000 -> 500 -> 300 ...
    sort(money.begin(), money.end(), greater<>());

// 가장 큰 돈부터 먼저 빼가면서 동전의 개수를 구한다.
    for(int j=0; j<money.size(); j++) {

    // 돈을 다 소비 할 때까지 진행
        while(sum >= money[j]) {
           sum = sum - money[j];
            answer++;
        }
    }

    cout << answer;
    return 0;
}