#include <bits/stdc++.h>
using namespace std;

int count_letters_in_int(int n) {
    if (n == 0) {
        return 4; // zero
    }

    // precalculated lengths of string sections
    const int DIGITS[10] = {4,3,3,5,4,4,3,5,5,4}; // 0, 1, 2, 3.. 9
    const int TEENS[10] =  {3,6,6,8,8,7,7,9,8,8}; // 10, 11, 12.. 19
    const int TENS[10] =   {4,3,6,6,5,5,5,7,6,6}; // 0, 10, 20, 30.. 90
    const int MAGNITUDES[5] = {4,8,7,7,8}; // zero, thousand, million, billion, trillion

    int total = 0;
    int index = 0; //position in number(right to left)
    int ones = 0; // holds the ones place for teen consideration
    int and_needed = 0; // bool
    while (n >= 1) { // going backwards from right -> left (smallest to biggest digits)
        int remainder = n % 10;

        if (index >= 3 && index % 3 == 0) {
            // MAGNITUDES (ex. million, or thousand)
            total += MAGNITUDES[index/3];
            and_needed = 0; // ands only carry between magnitudes
        }
        if (remainder == 0) {}
        else {
            // 0: ones(like 1 mil), 1: tens(like 10 mil), 2: hundreds(like 100 mil)
            int rel_position = index % 3;

            if (index == 0) {
                // FIRST DIGIT(ONES)
                ones = remainder;
                total += DIGITS[remainder];
            }
            else if (index == 1 && remainder == 1 && ones) {
                // TEENS
                // since teens combine the last two digits we have to remove the ones from before
                total += TEENS[ones] - DIGITS[ones];
            }
            else if (rel_position == 1) {
                // RELATIVE TENS
                total += TENS[remainder];
            }
            else if (rel_position == 2) {
                // RELATIVE HUNDREDS
                
                total += DIGITS[remainder] + 7; // "hundred" is 7 char
                if (and_needed) { // handle "and"
                    and_needed = 0;
                    total += 3; // ("and" is 3 letters)
                }
            }
            else if (rel_position == 0) {
                // RELATIVE ONES
                total += DIGITS[remainder];
            }
            and_needed = 1;
        }
        n /= 10;
        index ++;
    }
    return total;
}

void solve(int n){
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans += count_letters_in_int(i);
    }
    cout << ans << endl;
}

int main(){
    solve(5);
    solve(1000);

    return 0;
}