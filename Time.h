#pragma once
#include <iostream>
class Time
{
private:
    int hours_;
    int mins_;
public:
    Time(); // default constructor
    Time(int h, int m = 0); // h and m arguments, m defaults to 0
    void addMin(int m); // add minutes
    void addHr(int h); // add hours
    void reset(int h = 0, int m = 0); // resets to default 0 or h and m
    friend Time operator+(const Time& t1, const Time& t2);
    friend Time operator-(const Time& t1, const Time& t2);
    friend Time operator*(double n, const Time& t1);
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

