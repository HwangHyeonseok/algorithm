//#그리디
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m;
    vector<vector<int>> cards(10000); // v[0].push_back
    vector<int> smaller;

    cin >> n >> m;
    // 카드 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            cards[i].push_back(x);
        }
    }
    // 가장 낮은 숫자가 0인덱스로 오게끔한다.
    for (int j = 0; j < n; j++) {
        sort(cards[j].begin(), cards[j].end());
    }

    // 각 열마다 가장 낮은 다음 숫자(1인덱스)를 추가한다.
    for (int j = 0; j < n; j++) {
        smaller.push_back(cards[j][1]);
    }
    // 작은 값들 중 큰 수 출력
    sort(smaller.begin(), smaller.end());
    
    cout << smaller[0];

    return 0;

}