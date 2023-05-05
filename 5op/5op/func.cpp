#include "func.h"

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
        cout << "-----------------------------" << endl;
        cout << "Before subSeconds(): " << t12[i] << endl;
        t12[i].subSeconds(5);
        cout << "After subSeconds(): " << t12[i] << endl;
        cout << "-----------------------------" << endl;
    }

    for (int i = 0; i < m; i++) {
        cout << "-----------------------------" << endl;
        cout << "Before addSeconds(): " << t24[i] << endl;
        t24[i].addSeconds(15 * 60);
        cout << "After addSeconds(): " << t24[i] << endl;
        cout << "-----------------------------" << endl;
    }

    int minSeconds12 = t12[0].getSecondsLeft();
    for (int i = 1; i < n; i++) {
        minSeconds12 = min(minSeconds12, t12[i].getSecondsLeft());
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