#include <iostream>
#include <iomanip>
using namespace std;

const int n = 11;

int main(){
    int a[n][n];

    a[0][0]=1;

    bool way=1, mid=0;
    int k=1,f=0,c=1;
    for (int i=3; i<n*2; i+=2) {
        for (int j=0; j<i; j++) {
            a[f][c] = ++k;
            
            if (j==i/2) mid = 1;

            if (way) {
                if (!mid) f++;
                else c--;
            } 
            else {
                if (!mid) c++;
                else f--;  
            }

        }
        
        f++; c++;

        way = !way;
        mid = 0;
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }

    while(true){
        int x, y;
        cin >> x >> y;
        cout << a[x-1][y-1] << endl;
    }
    return 0;
}