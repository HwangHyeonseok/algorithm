// 단순 연산자를 이용한 구현
#include <iostream>

using namespace std;

int main(void) {
    int x,y;
    int days = 0;
    int months = 0;
    cin >> x >> y;

    for(int i=1; i<=x-1; i++) {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) {
            days += 31;
        }
        else if(i==4 || i==6 || i==9 || i==11) {
            days += 30;
        }
        else {
            days += 28;
        }
    }

    days = days + y + 6;
    months = days % 7;
    
    if(months == 0) cout << "MON";
    else if(months == 1) cout << "TUE";
    else if(months == 2) cout << "WED";
    else if(months == 3) cout << "THU";
    else if(months == 4) cout << "FRI";
    else if(months == 5) cout << "SAT";
    else if(months == 6) cout << "SUN";    

    return 0;
}