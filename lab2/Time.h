#include <iostream>

class Time{
public:
    explicit Time(int sec = 0, int min = 0, int h = 0);
    ~Time();
    Time& operator+(int num);
    Time& operator-(int num);
    Time& operator*(int num);
    Time& operator/(int num);
    void printTime();
private:
    int sec = 0;
    int min = 0;
    int h = 0;
    void normaliseTime();
};
