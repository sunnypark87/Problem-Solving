#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, temp;
    vector<int> ans;
    cin>>n>>x;

    for (int i=0; i<n; i++) {
        cin>>temp;
        if (temp < x) ans.push_back(temp);
    }
    
    for (int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

    return 0;
}