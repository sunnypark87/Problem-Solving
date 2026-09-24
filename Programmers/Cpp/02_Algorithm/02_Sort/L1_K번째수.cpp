#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 개선 후 코드

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i=0; i<commands.size(); i++) {
        vector<int> sliced (
            array.begin() + commands[i][0] - 1,
            array.begin() + commands[i][1]
        );
        sort(sliced.begin(), sliced.end());
        answer.push_back(sliced[commands[i][2]-1]);
    }
    
    return answer;
}

// 개선 전 코드

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i=0; i<commands.size(); i++) {
        vector<int> slice_array;
        for (int j=commands[i][0]-1; j<commands[i][1]; j++) {
            slice_array.push_back(array[j]);
        }
        sort(slice_array.begin(), slice_array.end());
        answer.push_back(slice_array[commands[i][2]-1]);
    }
    
    return answer;
}

int main(void) {
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = {
        {2, 5, 3},
        {4, 4, 1},
        {1, 7, 3}
    };


    return 0;
}