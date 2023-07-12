// #그리디
// 풀이 아이디어 : 내림차순 정렬하여 레벨이 가장 높은 카드를 먼저 합성하면 가진 카드 중 가장 높은 골드를 획득할 수 있다.

#include <iostream>
#include <vector>
#include <algorithm> // 정렬 사용

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int gold = 0; // 획득한 누적 골드
    vector<int> cards_level; // 카드들의 레벨을 담아놓은 배열
    int n; // 카드의 개수

// 카드 개수 입력받기 + 카드 개수만큼 카드의 레벨 입력받기
    cin >> n;
    for(int i=0; i<n; i++) {
        int level;
        cin >> level;
        cards_level.push_back(level);
    }
    
    // 카드 레벨을 내림차순 정렬
    sort(cards_level.begin(), cards_level.end(), greater<>());
    
    // 카드 두 개가 합성 시 합성된 카드의 레벨은 합성된 두 개의 카드 중 큰 레벨로 합성된다.
    // 즉, 합성된 새로운 카드는 항상 cards_level[0] 의 레벨을 따른다는 것을 이용한다.
    for(int i=0; i<n-1; i++) {
        gold = gold + cards_level[0]+cards_level[i+1];
    }
    
    cout << gold;
    return 0;
}