#include "Time.h"

TTime::TTime(int h, int m, int s) {
    seconds = h * 3600 + m * 60 + s;
}

void TTime::addSeconds(int s) {
    seconds += s;
    seconds %= 86400;
}

void TTime::subSeconds(int s) {
    seconds -= s;
    if (seconds < 0) {
        seconds += 86400;
    }
}

int TTime::getSecondsLeft() const {
    return 86400 - seconds;
}

void TTime12::subSeconds(int s) {
    TTime::subSeconds(s);
    updateAMPM();
}

void TTime12::updateAMPM() {
    if (am == "PM" && seconds < 43200) {
        am = "PM";
    }
    else {
        am = "AM";
    }
}

int TTime12::getSecondsLeft() const {
    if (am == "PM") {
        return 43200 - seconds;
    }
    else if (am == "AM") {
        return 86400 - seconds;
    }
}

ostream& operator<<(ostream & out, const TTime12 & t) {
    int h = t.seconds / 3600;
    int m = (t.seconds % 3600) / 60;
    int s = t.seconds % 60;

    if (h == 0) {
        h = 12;
    }
    else if (h > 12) {
        h -= 12;
    }

    out << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << " " << t.am;
    return out;
}

void TTime24::addSeconds(int s) {
    TTime::addSeconds(s);
}

ostream& operator<<(ostream& out, const TTime24& t) {
    int h = t.seconds / 3600;
    int m = (t.seconds % 3600) / 60;
    int s = t.seconds % 60;

    out << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s;
    return out;
}