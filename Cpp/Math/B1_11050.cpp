#include <iostream>
using namespace std;

int binomial_coefficient(int **b, int n, int k){

    for (int i=0; i<n+1; i++){
        b[i][0] = 1;
    }
    for (int i=0; i<k+1; i++){
        b[i][i] = 1;
    }

    for (int i=2; i<n+1; i++){
        for (int j=1; j<k+1; j++){
            b[i][j] = b[i-1][j] + b[i-1][j-1];
        }
    }

    return b[n][k];
}


int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    int result;
    int **binomial;
    
    cin>>n>>k;

    binomial = new int*[n+1];
    for (int i=0; i<n+1; i++){
        binomial[i] = new int[k+1];
    }

    result = binomial_coefficient(binomial, n, k);
    cout<<result;

    return 0;
}