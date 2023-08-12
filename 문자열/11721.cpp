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
        if(cur_index % 10 == 0 && cur_index != 0) 
            cout << "\n";
        cout << x[cur_index];

        
        cur_index++;
    }

    return 0;
}