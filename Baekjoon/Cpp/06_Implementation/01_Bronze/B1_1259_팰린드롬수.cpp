#include <iostream>
#include <string>
using namespace std;

int main(void){

    string word;
    int i, index;
    int palindrom;
    cin>>word;

    while(word != "0"){
        i = 0;
        index = word.length()-1;
        palindrom = 1;
        while((i != index)){
            if (word[i] != word[index]){
                palindrom = 0;
                break;
            }
            if (i+1 == index) break;
            i++;
            index--;
        }

        if (palindrom){
            cout<<"yes\n";
        }
        else {
            cout<<"no\n";
        }

        cin>>word;
    }

    return 0;
}