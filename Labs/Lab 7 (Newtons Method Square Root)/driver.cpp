#include <iostream>
#include <cmath>
using namespace std;

float NewtonsMethod(double x, double a, double e){
    if(abs(((a*a) - x)) < e)
        return a;
    else{
        return NewtonsMethod(x, ((a*a) + x)/(2*a),e);   
    }
}

int main(){
    // I found that using epsilon of 0.001 has good results.
    double num;
    double eps;
    cout << "What number would you like to find the square root of?" << endl;
    cin >> num;
    cout << "What would you like epsilon to be?" << endl;
    cin >> eps;
    cout << NewtonsMethod(num, num, eps);

    
    return 0;
}