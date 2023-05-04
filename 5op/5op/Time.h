#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TTime 
{
protected:
    int seconds;

public:
    TTime(int h, int m, int s);

    void addSeconds(int s);

    void subSeconds(int s);

    int getSecondsLeft() const;
};

class TTime12 : public TTime
{
private:
    string am;

public:
    TTime12(int h = 0, int m = 0, int s = 0, string ap = "AM") : TTime(h, m, s), am(ap) {}

    void subSeconds(int s);

    void updateAMPM();

    int getSecondLeft12() const;

    friend ostream& operator<<(ostream& out, const TTime12& t);
};

class TTime24 : public TTime
{
public:
    TTime24(int h = 0, int m = 0, int s = 0) : TTime::TTime(h, m, s) {}

    void addSeconds(int s);

    friend ostream& operator<<(ostream& out, const TTime24& t);
};

int min(int, int);

void work();
