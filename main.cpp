#include <iostream>
#include<cmath>
#include"Header.h"
using namespace std;



int main() {

    complexno v(0, 45);
    cout << " complex no. i.e: ";
    cout << v;
    cout << endl << endl << endl;


    cout << "following is the operation adding two complex numbers: " << endl;
    cout << endl;
    complexno c1(3, 6), c2(4, 1);
    complexno t;
    t = c1 + c2;
    cout << c1;
    cout << " + ";
    cout << c2;
    cout << " = ";
    cout << t;

    cout << endl;


    // complexno c1(3,0) , c2(4,1);
    complexno ty = c1 - c2;
    // complexno difference = subtract(c1, c2);
    cout << c1;
    cout << " - ";
    cout << c2;
    cout << " = ";
    cout << ty;

    cout << endl;
    //(a * c) - (a * d) + (b * c)i;
    complexno tm = c1 * c2;
    // complexno difference = subtract(c1, c2);
    cout << c1;
    cout << " * ";
    cout << c2;
    cout << " = ";
    cout << tm;

    cout << endl;


    cout << c2;
    cout << " = ";
    complexno tys = tys.inverse(c2);
    cout << tys;

    cout << endl;

    cout << c1;
    cout << " = ";
    complexno revo = revo.conjugate(c1);
    cout << revo;

    cout << endl;

    cout << c1;
    cout << " / ";
    cout << c2;
    cout << " = ";
    complexno cvc = c1 / c2;
    cout << cvc;

    cout << endl;

    cout << c1;
    cout << " = ";
    complexno grd = grd.additive_inverse(c1);
    cout << grd;

    cout << endl;

    // c1.print();
    // cout<<" = ";
    // double res=modulus(c1);
    // // res.print();
    // cout <<res;

// finding modulus of the complex numberz
    double rem = sqrt(c1.getreal() * c1.getreal() + c1.getimag() * c1.getimag());
    cout << c1.getreal() << "+" << c1.getimag() << "i=" << rem;


    cout << endl << endl;


    //============================== FRACTION CLASS =============================


    cout << "following are the calculator operation for fractions: " << endl << endl;

    fraction f1(15, 10), f2(5, 10);
    cout << f1;
    cout << " + ";
    cout << f2;
    cout << " = ";
    fraction grnd = f1 + f2;
    cout << grnd;

    cout << endl;

    cout << f1;
    cout << " - ";
    cout << f2;
    cout << " = ";
    fraction swf = f1 - f2;
    cout << swf;

    cout << endl;

    cout << f1;
    cout << " * ";
    cout << f2;
    cout << " = ";
    fraction wgnr = f1 * f2;
    cout << wgnr;

    cout << endl;

    cout << f1;
    cout << " = ";
    fraction cul = cul.add_inverse(f1);
    cout << cul;

    cout << endl;


    cout << f1;
    cout << " / ";
    cout << f2;
    cout << " = ";
    fraction suz = f1 / f2;
    cout << suz;

    cout << endl;

    cout << f1;
    cout << " = ";
    fraction mg = mg.multiplicative_inverse(f1).simplify();
    // fraction remm=mg.simplify();
    cout << mg;

    cout << endl;


    //     f1.print();
    //     cout<<" = ";
    //     fraction fr=reduced(f1);
    //     fr.print();

    // gcd(f1);


    cout << f1;
    cout << " = ";
    fraction yrs = f1.simplify();
    //fraction remm=mg.simplify();
    cout << yrs;


    cout << endl;

    cout << f2;
    cout << " = ";
    fraction oshn = f2.simplify();
    cout << oshn;



    //cout << " = ";
    //fraction oshn = f2.simplify();
    //cout << oshn;
    //cout << f2 << endl;
    //cout << f2 << " = " << oshn;

    return 0;
}

