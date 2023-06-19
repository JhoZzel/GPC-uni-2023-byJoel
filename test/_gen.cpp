#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
typedef long long ll;

const int maxn=2e5+3;

int main(){
    ofstream fout("_out.txt");
    srand(time(nullptr));

    int t = 100;
    fout << t << endl;
    while(t--) {
        //int n = rand() % 10 + 2;
        int s[9][9] = {{3, 0, 7, 4, 0, 0, 0, 0, 8},
                {0, 0, 4, 0, 0, 7, 3, 5, 0},
                {0, 1, 0, 0, 2, 0, 0, 0, 9},
                {0, 6, 9, 2, 7, 0, 8, 3, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 3, 2, 0, 1, 4, 7, 9, 0},
                {2, 0, 0, 0, 8, 0, 0, 4, 0},
                {0, 7, 6, 1, 0, 0, 9, 0, 0},
                {4, 0, 0, 0, 0, 9, 2, 0, 6}};

        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                fout << s[i][j] << " ";
            }
            fout << endl;
        }
        fout << endl;
    }
   
    cout << "FINISH";
    return 0;
}