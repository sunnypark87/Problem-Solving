#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int test_case, n;
    vector<long long> triangles;
    
    cin>>test_case;
    for (int i=0; i<test_case; i++) {
        cin>>n;
        triangles.clear();
        triangles = {1, 1, 1, 2, 2};
        for (int i=4; i<n-1; i++) {
            triangles.push_back(triangles[i] + triangles[i-4]);
        }
        cout<<triangles[n-1]<<'\n';
    }
    

    return 0;
}