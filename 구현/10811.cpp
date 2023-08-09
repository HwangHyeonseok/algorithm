// 구현 + 시뮬레이션 + 1차원 배열 - 배열 순서 뒤집는 알고리즘 

#include <iostream>

using namespace std;
#define MAX_N 101 // N의 최댓값

int basket[MAX_N];

void swap(int x, int y) {
    int change_count =0;
    if(x==y) { change_count = 0; }
    else if((y-x)%2==0) {    change_count = (y-x) / 2; }
    else if((y-x)%2!=0) { change_count = ((y-x) / 2) + 1; }
    
    for(int i=0; i<change_count; i++) {
        int temp = basket[x+i];
        basket[x+i] = basket[y-i];
        basket[y-i] = temp;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N,M;

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        basket[i] = i;
    }

    for(int i=0; i<M; i++) {
        int start, end;
        cin >> start >> end;
        swap(start, end);
    }

    for(int i=1; i<=N; i++) {
        cout << basket[i] << " ";
    }
    
    return 0;
}