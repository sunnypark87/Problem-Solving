#include <iostream>

using namespace std;

int main(void) {

    int note, prev_note;
    int ascending=0;
    int descending=0;

    note = 0;
    prev_note = 0;
    for (int i=0; i<8; i++) {
        cin>>note;
        if (ascending == 0 && descending == 0) {
            if (prev_note == 0) {
                prev_note = note;
                continue;
            }
            if (note < prev_note) {
                descending = 1;
            }
            else if (note > prev_note) {
                ascending = 1;
            }
        }
        if (ascending == 1) {
            if (note < prev_note) {
                ascending = 0;
                cout<<"mixed";
                break;
            }
        }
        if (descending == 1) {
            if (note > prev_note) {
                descending = 0;
                cout<<"mixed";
                break;
            }
        }
        prev_note = note;
    }

    if (ascending == 1) {
        cout<<"ascending";
    }
    else if (descending == 1) {
        cout<<"descending";
    }

    return 0;
}