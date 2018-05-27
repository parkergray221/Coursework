#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void y(double x1, double y1, double x2, double y2, double x3, double y3, double X)
{
    //EQUATION IS (y = ax^2 + bx + c)
    double a1 = x1*x1; //get values of a b and c in equation
    double b1 = x1;
    double c1 = 1;
    double a2 = x2*x2;
    double b2 = x2;
    double c2 = 1;
    double a3 = x3*x3;
    double b3 = x3;
    double c3 = 1;
    double d1 = -y1;
    double d2 = -y2;
    double d3 = -y3; //also need to record values of y when points are inserted.
    //How to find coefficients of points? Cramer's rule.
    double D = (a1 * b2 * c3 + b1 * a3 * c2 + c1 * a2 * b3) - (a1 * c2 * b3 + b1 * a2 * c3 + c1 * b2 * a3);
    double x = ((b1 * c3 * d2 + c1 * b2 * d3 + d1 * c2 * b3) - (b1 * c2 * d3 + c1 * b3 * d2 + d1 * b2 * c3)) / D;
    double y = ((a1 * c2 * d3 + c1 * a3 * d2 + d1 * a2 * c3) - (a1 * c3 * d2 + c1 * a2 * d3 + d1 * c2 * a3)) / D;
    double z = ((a1 * b3 * d2 + b1 * a2 * d3 + d1 * b2 * a3) - (a1 * b2 * d3 + b1 * a3 * d2 + d1 * a2 * b3)) / D;
    double inc = (x3 - x1) / 39; //deduce the amount of incrementing that will need to occur between each point
    int counter = 1; //counter for display of points
    double point;
    for(point = x1; point < x3; point += inc, counter++){ //print 40 points in a tab le. start at point x1 and go until x1 = x3.
        double yPoint = x * (point * point) + y * (point) + z;
        cout << counter << ":\t(" << setprecision(3) << point << ", " << setprecision(3) << yPoint << ")" << endl;
    }
}

int main() {
    int x1 = 1; //(x1, y1) = (1,2)
    int y1 = 2;
    int x2 = 3; //(x2, y2) = (3,4)
    int y2 = 4;
    int x3 = 5; //(x3, y3) = (5,6)
    int y3 = 6;
    int x = 40; //n = 40 equidistant points between (x1, y1) and (x3, y3)
    //get input for x1, y1, x2, y2, x3, y3
    cout << "Input points are: (x1, y1) = " << "(" << x1 << ", " << y1 << "), (x2, y2) = " << "(" << x2 << ", " << y2 << "), (x3, y3) = " << "(" << x3 << ", " << y3 << ")." << endl;
    y(x1, y1, x2, y2, x3, y3, x);
}
