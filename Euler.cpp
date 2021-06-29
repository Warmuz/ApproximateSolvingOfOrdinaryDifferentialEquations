#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

double function(double x, double y){
    return -2*y+1*exp(-2*x);
}

double euler(double x, double y, double h, int n){
    double* arguments;
    double* values;
    double* triangle;
    
    arguments = new double [n+1];
    values = new double [n+1];
    triangle = new double [n];
    
    values[0]=y;
    for(int i =0; i<n ; i++){
        arguments[i]=x+i*h;
        triangle[i]=h*function(arguments[i],values[i]);
        values[i+1]=values[i]+triangle[i];
        cout<<values[i]<<endl;
    }
    return* values;
}

double broken_lines(double x, double y, double h, int n){
    double* arguments;
    double* values;
    double* arguments2;
    double* values2;
    double* z;
    double* triangle;
    
    arguments = new double [n];
    values = new double [n];
    arguments2= new double [n];
    values2= new double [n];
    z = new double [n];
    triangle = new double [n];
    
    values[0]=y;
    for(int i=0; i<n; i++){
        arguments[i]=x+i*h;
        z[i]=0.5*h*function(arguments[i],values[i]);
        arguments2[i]=arguments[i]+0.5*h;
        values2[i]=values[i]+0.5*h*function(arguments[i],values[i]);
        triangle[i]=h*function(arguments2[i],values2[i]);
        values[i+1]=values[i]+triangle[i];
    }
    cout<<values[n]<<endl;
    return* values;
}

double euler_cauchy(double x, double y, double h, int n){
    double* arguments;
    double* values;
    double* f;
    double* values2;
    double* f2;
    double* triangle;
    double* arg;
    
    
    arguments = new double [n];
    arg = new double [n];
    values = new double [n];
    f = new double [n];
    values2 = new double [n];
    f2 = new double [n];
    triangle = new double [n];
    
    values[0]=y;
    for(int i=0; i<n; i++){
        arguments[i]=x+i*h;
        f[i]=0.5*h*function(arguments[i],values[i]);
        values2[i]=values[i]+h*function(arguments[i],values[i]);    //arguments[i] is wrong
        f2[i]=0.5*h*function(arguments[i+1],values2[i]);
        triangle[i]=f[i]+f2[i];
        values[i+1]=values[i]+triangle[i];
        
    }
    return* values;
}

int main() {
    double x=0;
    double y=-10;
    double h=0.1;
    int n=51;
    euler(x,y,h,n);
    //broken_lines(x,y,h,n);
    //euler_cauchy(x,y,h,n);
}
