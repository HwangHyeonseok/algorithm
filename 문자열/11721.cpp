// 구현 + 문자열

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string x;
    int cur_index = 0;
    cin >> x;


    while(cur_index <= x.length()-1 ) {
        cout << x[cur_index];
        if(cur_index % 9 == 0 && cur_index != 0) 
            cout << "\n";
        
        cur_index++;
    }

    return 0;
}