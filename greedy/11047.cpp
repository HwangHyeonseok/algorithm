// https://www.acmicpc.net/problem/11047

// 그리디 알고리즘 활용 
// 둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수) 에서 i ≥ 2인 경우에 Ai는 Ai-1의 배수 조건 때문에 그리디 알고리즘 가능
// 무조건 큰 수부터 빼주는 것이 동전의 합이 최소가 될 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; // 동전의 종류 
    int target_money; // 동전 가치의 합
    vector<int> coins; // 화폐 종류 (단, 1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
    int answer = 0;

    cin >> N >> target_money;

    for(int i=0; i<N; i++) {
        int coin_type;
        cin >> coin_type;
        coins.push_back(coin_type);
    }

    sort(coins.begin(), coins.end(), greater<>()); // 내림차순 정렬

    for (int coin : coins) {
        while(target_money >= coin) {
            target_money -= coin;
            answer++;
        }
    }

    cout << answer;

    return 0;
}
