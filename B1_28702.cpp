#include <iostream>
#include <string>
using namespace std;

int check_number(string input) {
    if (input == "FizzBuzz" || input == "Fizz" || input == "Buzz") return 0;
    else return 1;
}

int main(void) {
    string a, b, c, answer;
    int check, a_num, b_num, c_num;
    int answer_num;

    cin >> a >> b >> c;

    a_num = 0;
    b_num = 0;
    c_num = 0;
    check = check_number(a);
    if (check) a_num = stoi(a);
    check = check_number(b);
    if (check) b_num = stoi(b);
    check = check_number(c);
    if (check) c_num = stoi(c);

    if (a_num != 0) answer_num = a_num + 3;
    else if (b_num != 0) answer_num = b_num + 2;
    else if (c_num != 0) answer_num = c_num + 1;
    if (answer_num % 3 == 0 && answer_num % 5 == 0) cout << "FizzBuzz\n";
    else if (answer_num % 3 == 0) cout << "Fizz\n";
    else if (answer_num % 5 == 0) cout << "Buzz\n";
    else cout << answer_num << '\n';

    return 0;
}