#include <iostream>
#include <random>

class Time{
public:
    explicit Time(int sec = rand() % 60, int min = rand() % 60, int h = rand() % 24);
    ~Time();
    Time& operator=(Time& time);

    Time& operator+(int num);
    Time& operator-(int num);
    Time& operator*(int num);
    Time& operator/(int num);

/*
    friend Time operator+ (Time time, int num);
    friend Time operator- (Time time, int num);
    friend Time operator* (Time time, int num);
    friend Time operator/ (Time time, int num);
*/
    void printTime();
    friend void normaliseTime(Time* timePtr);
private:
    int sec = 0;
    int min = 0;
    int h = 0;
    void normaliseTime();
};
