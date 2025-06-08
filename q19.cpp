#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year) {
    if (year % 100 == 0) {
        return year % 400 == 0;
    }

    return year % 4 == 0;
}

const std::vector<int> getNumDaysPerMonth(int year) {
    return {
        31,                          // JAN
        isLeapYear(year) ? 29 : 28,  // FEB
        31,                          // MAR
        30,                          // APR
        31,                          // MAY
        30,                          // JUN
        31,                          // JUL
        31,                          // AUG
        30,                          // SEP
        31,                          // OCT
        30,                          // NOV
        31                           // DEC
    };
}

int getFirstDayOf1901() {
    int startDay = -1;  // 1st of Jan is Monday
    for (const auto& daysInMonth : getNumDaysPerMonth(1900)) {
        startDay = (startDay + daysInMonth) % 7;
    }
    // We are at 31st of Dec 1900
    return (startDay + 1) % 7;
}

int numSundaysOnFirstOfMonth() {
    int startYear = 1901;
    int endYear = 2000;
    int startDay = getFirstDayOf1901();
    int numSundays = 0;
    for (int year = startYear; year <= endYear; year++) {
        for (const auto& daysInMonth : getNumDaysPerMonth(year)) {
            if (startDay == 6) {
                numSundays += 1;
            }
            startDay = (startDay + daysInMonth) % 7;
        }
    }
    return numSundays;
}

int main() {
    cout << numSundaysOnFirstOfMonth() << '\n';
    return 0;
}