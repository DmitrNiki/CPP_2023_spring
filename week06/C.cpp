#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time *timer = new Time[2];
    int hours   = 0;
    int h       = 0;
    int minutes = 0;
    int m       = 0;
    int seconds = 0;

    for (int i = 0; i < 2; i++) {
        cin >> timer[i].hours;
        cin >> timer[i].minutes;
        cin >> timer[i].seconds;
    }

    if (timer[0].seconds + timer[1].seconds >= 60) {
        seconds = timer[0].seconds + timer[1].seconds - 60;
        m += 1;
    } else {
        seconds = timer[0].seconds + timer[1].seconds;
    }

    if (timer[0].minutes + timer[1].minutes + m >= 60) {
        minutes = timer[0].minutes + timer[1].minutes + m - 60;
        h += 1;
    } else {
        minutes = timer[0].minutes + timer[1].minutes + m;
    }
    if (timer[0].hours + timer[1].hours + h >= 24) {
        hours = timer[0].hours + timer[1].hours + h - 24;
    } else {
        hours = timer[0].hours + timer[1].hours + h;
    }
    cout << hours << ':' << minutes << ':' << seconds << endl;
    return 0;
}