#include <cmath>
#include <iostream>
double function(double x, double y){
    return -2*y+1*exp(-2*x);
}
double k(double x, double y, double h){
    double k[4] = {0};
    double deltaY = 0;
    
    k[0] = h*function(x,y);
    k[1] = h*function(x+0.5*h, y+0.5*k[0]);
    k[2] = h*function(x+0.5*h, y+0.5*k[1]);
    k[3] = h*function(x+h, y+k[2]);
    
    deltaY = (k[0] + 2*k[1] + 2*k[2] + k[3])/6;
    
    return deltaY;
}


int main() {
    
    double x0 = 0.1;
    double y0 = -10;
    double h = 0.1;
    double n = 50;
    std::cout << y0 << std::endl;
    for(int i = 1; i <= n; i++){
        k(x0, y0, h);
        y0 += k(x0, y0, h);
        x0 = i*h;
        std::cout << y0 << std::endl;
    }
    
}
