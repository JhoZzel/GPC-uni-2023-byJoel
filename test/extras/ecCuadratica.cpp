#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float a,b,c,D;

    cout<<"Sea la ecuacion cuadratica  'ax^2 + bx + c' "<<endl;
    cout<<"Ingrese los coeficientes: "<<endl;
    cout<<" a -> "; cin>>a;
    cout<<" b -> "; cin>>b;
    cout<<" c -> "; cin>>c;
    
    D = b*b - 4*a*c;

    if (D>=0){
        float x1 = (-b + sqrt(D))/(2*a);
        float x2 = (-b - sqrt(D))/(2*a);

        if (x1!=x2){
            cout<<" -----Raices Reales Distintas-----\n";
            cout<<"  x1: "<<x1<<"\t"<<"x2: "<<x2;
        }
        else{
            cout<<" -----Raices Reales Iguales-----\n";
            cout<<"  x: "<<x1;
        }
    }
    else{
        float x_r = -b/2/a;
        float x_c = sqrt(-D)/2/a;
        
        cout<<" -----Raices Complejas-----\n";
        cout<<"  x1: "<<x_r<<"+"<<x_c<<"i"<<"\t"<<"x2: "<<x_r<<"-"<<x_c<<"i"<<endl;
    }
    return 0;
}
