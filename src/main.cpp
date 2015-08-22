#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

struct vec2 {
    float x;
    float y;
    vec2(float _x, float _y) {
       x = _x;
       y = _y;
    }
};

struct rect {
    float right;
    float left;
    float top;
    float bottom;

    rect(float left_, float top_, float right_, float bottom_) {
        left = left_;
        top  = top_;
        right = right_;
        bottom = bottom_;
    }
};


char outcode(vec2 point,rect rec) {
    char op = 0;

    if(point.x  > rec.right)
        op = (1 << 1) | op;
    if(point.x < rec.left)
        op = (1) | op;

    if(point.y > rec.top)
        op = (1 << 3) | op;
    if(point.y < rec.bottom)
        op = (1 << 2) | op;

    return op;
}

void outcode_check(char number) {
    if(number & 0)
        std::cout << "inside" << std::endl;
    if(number & 1)
        std::cout << "left wall crossed" << std::endl;
    if(number & 2)
        std::cout << "right wall crossed" << std::endl;
    if(number & 4)
        std::cout << "bottom wall crossed" << std::endl;
    if(number & 8)
        std::cout << "top wall crossed" << std::endl;
}


   
vec2 param(vec2 p1, vec2 p2, float alpha) {
    vec2 tes(0, 0);
    tes.x = (1-alpha)*p1.x + alpha*p2.x;
    tes.y = (1-alpha)*p1.y + alpha*p2.y;
    return tes;
}

void calc_p_q(vec2 p1, vec2 p2, rect rec) {
    float dX = p2.x - p1.x;
    float dY = p2.y - p1.y;

    float p_1 = -dX;
    float p_2 = dX;
    float p_3 = -dY;
    float p_4 = dY;

    float q1 = p1.x - rec.left;
    float q2 = rec.right - p1.x;
    float q3 = p1.y - rec.bottom;
    float q4 = rec.top - p1.y;

    cout << p_1 << " " << p_2 << " " << p_3 << " " << p_4 << endl;
    cout << q1  << " " << q2  << " " << q3  << " " << q4 << endl;

    
    cout << q1/abs( p_1 )  << " " << q2/abs( p_2 )  << " " << q3/abs( p_3 )  << " " << q4/abs( p_4 ) << endl;
    vec2 point1 = param(p1, p2, q1/(p_1));
    vec2 point2 = param(p1, p2, q2/(p_2));
    vec2 point3 = param(p1, p2, q3/(p_3));
    vec2 point4 = param(p1, p2, q4/(p_4));


    cout << "p1 left   " << point1.x << " " << point1.y << endl;
    cout << "p2 right  " << point2.x << " " << point2.y << endl;
    cout << "p3 bottom " << point3.x << " " << point3.y << endl;
    cout << "p4 top    " << point4.x << " " << point4.y << endl;
}

int main(int argc, char ** argv) {
    vec2 p1 = vec2(-1.5,-0.8);
    vec2 p2 = vec2(0.8, 1.2);
    float leg = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    vec2 p1p = vec2(p1.x/leg, p1.y/leg);
    vec2 p2p = vec2(p2.x/leg, p2.y/leg);
    rect t(-1, 1, 1, -1);
    
    vec2 testing = param(p1, p2, 1);
    // cout << testing.x << " " << testing.y << endl;
    calc_p_q(p1, p2, t); 
    
    return 0;
}
