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

int TTime12::getSecondLeft12() const {
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

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

void work() 
{
    int n, m;
    int h, minu, s;

    string am;

    cout << "Enter n: ";
    cin >> n;

    TTime12* t12 = new TTime12[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter time: ";
        cin >> h >> minu >> s >> am;
        t12[i] = TTime12(h, minu, s, am);
    }

    cout << "Enter m: ";
    cin >> m;

    TTime24* t24 = new TTime24[n];

    for (int i = 0; i < m; i++) {
        cout << "Enter time: ";
        cin >> h >> minu >> s;
        t24[i] = TTime24(h, minu, s);
    }

    for (int i = 0; i < n; i++) {
        cout << "Before subSeconds(): " << t12[i] << endl;
        t12[i].subSeconds(5);
        cout << "After subSeconds(): " << t12[i] << endl;
    }

    for (int i = 0; i < m; i++) {
        cout << "Before addSeconds(): " << t24[i] << endl;
        t24[i].addSeconds(15 * 60);
        cout << "After addSeconds(): " << t24[i] << endl;
    }

    int minSeconds12 = t12[0].getSecondLeft12();
    for (int i = 1; i < n; i++) {
        minSeconds12 = min(minSeconds12, t12[i].getSecondLeft12());
        //cout << minSeconds12 << endl;
    }
    int minSeconds24 = t24[0].getSecondsLeft();
    for (int i = 1; i < m; i++)
    {
        minSeconds24 = min(minSeconds24, t24[i].getSecondsLeft());
        //cout << minSeconds24 << endl;
    }

    int minSecondsLeft;
    if (minSeconds12 > minSeconds24) {
        minSecondsLeft = minSeconds24;
    }
    else {
        minSecondsLeft = minSeconds12;
    }

    cout << "The minimum time left in the day is " << minSecondsLeft << " seconds." << endl;

    delete[]t12;
    delete[]t24;
}