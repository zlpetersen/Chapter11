#include "Time.h"



Time::Time()
{
    hours_ = mins_ = 0;
}


Time::Time(int h, int m)
{
    hours_ = h;
    mins_ = m;
}


void Time::addMin(int m)
{
    mins_ += m;
    hours_ += mins_ / 60;
    mins_ %= 60;
}


void Time::addHr(int h)
{
    hours_ += h;
}


void Time::reset(int h, int m)
{
    hours_ = h;
    mins_ = m;
}


Time operator+(const Time& t1, const Time& t2)
{
    Time sum;
    sum.mins_ = t1.mins_ + t2.mins_;
    sum.hours_ = t1.hours_ + t2.hours_ + sum.mins_ / 60;
    sum.mins_ %= 60;
    return sum;
}


Time operator-(const Time& t1, const Time& t2)
{
    Time diff;
    int tot1, tot2;
    tot1 = t1.mins_ + 60 * t1.hours_;
    tot2 = t2.mins_ + 60 * t2.hours_;
    diff.mins_ = (tot1 - tot2) % 60;
    diff.hours_ = (tot1 - tot2) / 60;
    return diff;
}


Time operator*(double n, const Time& t1)
{
    Time result;
    long totalMins = t1.hours_ * n * 60 + t1.mins_ * n;
    result.hours_ = totalMins / 60;
    result.mins_ = totalMins % 60;
    return result;
}


std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << t.hours_ << " hours, " << t.mins_ << " minutes";
    return os;
}

