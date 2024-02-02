#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    int height, width, one_line;
    int count, state, answer;
    vector<vector<int>> blocks;

    cin>>height>>width;
    for (int i=0; i<height; i++) {
        vector<int> line(width, 0);
        blocks.push_back(line);
    }

    for (int i=0; i<width; i++) {
        cin>>one_line;
        for (int j=0; j<height; j++) {
            if ((height - j) <= one_line) {
                blocks[j][i] = 1;
            }
        }
    }

    answer = 0;
    for (int i=0; i<height; i++) {
        count = 0;
        state = 0;
        for (int j=0; j<width; j++) {
            if (blocks[i][j] == 1) {
                if (state == 0) {
                    state = 1;
                }
                else {
                    answer += count;
                    count = 0;
                }            
            }
            else {
                if (state == 1) {
                    count++;
                }
            }
        }
    }

    cout<<answer;

    return 0;
}