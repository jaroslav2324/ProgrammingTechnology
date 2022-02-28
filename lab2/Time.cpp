#include "Time.h"

Time::Time(int sec, int min, int h){

    this->sec = sec;
    this->min = min;
    this->h = h;
    return;
}

Time::~Time(){

    return;
}

/*increases minutes*/
Time& Time::operator+(int num){

    min += num;
    normaliseTime();
    return *this;
}

/*decreases minutes*/
Time& Time::operator-(int num){

    min -= num;
    normaliseTime();
    return *this;
}

Time& Time::operator*(int num){

    sec *= num;
    min *= num;
    h *= num;
    normaliseTime();
    return *this;
}


Time& Time::operator/(int num){

    sec /= num;
    min /= num;
    h /= num;
    normaliseTime();
    return *this;
}
/*
Time operator+ (Time time, int num){

    Time timeOut = time;
    timeOut.min += num;

    normaliseTime(&timeOut);

    return timeOut;
}

Time operator- (Time time, int num){

    Time timeOut = time;
    timeOut.min -= num;

    normaliseTime(&timeOut);

    return timeOut;
}


Time operator* (Time time, int num){

    Time timeOut = time;
    timeOut.min *= num;
    timeOut.sec *= num;
    timeOut.h *= num;

    normaliseTime(&timeOut);

    return timeOut;
}


Time operator/ (Time time, int num){

    Time timeOut = time;
    timeOut.min /= num;
    timeOut.sec /= num;
    timeOut.h /= num;

    normaliseTime(&timeOut);

    return timeOut;
}
*/
Time& Time::operator=(Time& time){

    this->h = time.h;
    this->min = time.min;
    this->sec = time.sec;
    return *this;
}

/*automatically converts sec in min, min in h, checks negative values of variables...*/
void Time::normaliseTime(){

    min +=  sec / 60;
    sec %= 60;
    if (sec < 0){
        min--;
        sec += 60;
    }
    h += min / 60;
    min %= 60;
    if (min < 0){
        h--;
        min += 60;
    }
    h %= 24;
    if (h < 0)
        h = 0;
    return;
}

void Time::printTime(){

    std::cout << "Current time is " << h << "h " << min << "min " << sec << "sec" << std::endl;
    return;
}

/*automatically converts sec in min, min in h, checks negative values of variables...*/
void normaliseTime(Time* timePtr){

    timePtr->min +=  timePtr->sec / 60;
    timePtr->sec %= 60;
    if (timePtr->sec < 0){
        timePtr->min--;
        timePtr->sec += 60;
    }
    timePtr->h += timePtr->min / 60;
    timePtr->min %= 60;
    if (timePtr->min < 0){
        timePtr->h--;
        timePtr->min += 60;
    }
    timePtr->h %= 24;
    if (timePtr->h < 0)
        timePtr->h = 0;
    return;
}
