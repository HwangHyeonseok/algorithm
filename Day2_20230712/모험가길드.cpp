//# 그리디

// 공포도가 높은 순서대로 배열해서 묶고 뺀다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> gongpo;

    int people;
    cin >> people;
    int answer = 0;

    for(int i=0; i<people; i++) {
        int x;
        cin >> x;
        gongpo.push_back(x);
    }
    // 내림차순 정렬
    sort(gongpo.begin(), gongpo.end(), greater<>());
    
    // 3 2 2 2 2 1 일 경우 3명 먼저 그룹 해주고 그 다음 인덱스 + 3 해준다.
    int index = 0;
    while(people > 0) {
        people -= gongpo[index];
        index += gongpo[index];
        answer++;
    }
    
    cout << answer;

    return 0;
}