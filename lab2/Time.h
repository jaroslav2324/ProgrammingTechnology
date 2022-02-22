

class Time{
public:
    Time& operator+(int num);
    Time& operator-(int num);
    Time& operator*(int num);
    Time& operator/(int num);

private:
    int sec = 0;
    int min = 0;
    int h = 0;
};
