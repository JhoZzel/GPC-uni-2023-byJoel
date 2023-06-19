#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){	
	int t; cin>>t;
	while(t!=0){
		int n; cin>>n;
        int A[n][n]{};
        
        int i=0, j=0, k=1;
        // Antes de la diagonal
        while(i<n){
            while(i>=0){
                A[i][j]=k;
                k++;
                i--;
                j++;
            }
            i=j;
            j=0;
        }
        // Luego de la diagonal
        i=n-1, j=1;
        while(j<n){
            while(j<n){
                A[i][j]=k;
                k++;
                i--;
                j++;
            }
            j=i+2;
            i=n-1;
        }

        // Impresion final
        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
        
		t--;
	}

	return 0;
}