#pragma once

#include <iostream>
using namespace std;


//============================= COMPLEX CLASS ===============================


class complexno {

private:

    int realpart;
    int imginarypart;

public:

    complexno();
    complexno(int r, int i);
    int getreal();
    int getimag();
    void setreal(int rr);
    void setimag(int imginn);
    complexno operator+(complexno c2);
    complexno operator-(complexno c2);
    complexno operator*(complexno c2);
    complexno inverse(complexno c1);
    complexno conjugate(complexno c1);
    complexno additive_inverse(complexno c1);
    double operator%(complexno& c1);
    complexno operator/(complexno c2);
    friend ostream& operator<<(ostream& cout, const complexno& nam)
    {

        char yo;
        if (nam.imginarypart >= 0)
            yo = '+';
        else
            yo = '-';

        cout << nam.realpart << yo << abs(nam.imginarypart) << "i";

        return cout;
    }


};


complexno::complexno()
{
    realpart = 0;
    imginarypart = 0;
}

complexno::complexno(int r, int i)
{
    realpart = r;
    imginarypart = i;
}


//void complexno::operator<<(iostream& cout)
//{
//    char yo;
//    if (imginarypart >= 0)
//        yo = '+';
//    else
//        yo = '-';
//
//    cout << realpart << yo << abs(imginarypart) << "i";
//
//}

int complexno::getreal()
{
    return this->realpart;
}

int complexno::getimag()
{
    return this->imginarypart;
}

void complexno::setreal(int rr)
{
    this->realpart = rr;
}

void complexno::setimag(int imginn)
{
    this->imginarypart = imginn;
}



complexno complexno::operator+(complexno c2) {

    // complexno r(c1.getreal()+c2.getreal(), c1.getimag()+c2.getimag());
    complexno r;
    r.setreal((*this).getreal() + c2.getreal());
    r.setimag((*this).getimag() + c2.getimag());
    return r;

}


complexno complexno::operator-(complexno c2) {

    complexno r;
    // (c1.getreal()-c2.getreal(), c1.getimag() - c2.getimag());
    r.setreal((*this).getreal() - c2.getreal());
    r.setimag((*this).getimag() - c2.getimag());
    return r;
}

complexno complexno::operator*(complexno c2) {

    // complexno r;
    // r.setreal(c1.getreal() * c2.getreal());
    int rwq = (((*this).getreal() * c2.getreal()) - ((*this).getimag() * c2.getimag()));
    complexno r(rwq, ((*this).getimag() * c2.getreal()) + ((*this).getreal() * c2.getimag()));

    return r;
}
complexno complexno::inverse(complexno c1) {
    double denominator = c1.getreal() * c1.getreal() + c1.getimag() * c1.getimag();
    if (denominator == 0) {
        throw runtime_error("Inverse does not exist: denominator is zero");
    }
    // complexno(c1.getreal() / denominator, -c1.getimag() / denominator);
    return complexno(c1.getreal() / denominator, -c1.getimag() / denominator);
}



complexno complexno::conjugate(complexno c1) {

    complexno r(c1.getreal(), (c1.getimag() * -1));
    return r;
}
complexno complexno::additive_inverse(complexno c1) {

    complexno r(c1.getreal() * -1, (c1.getimag() * -1));
    return r;
}
double complexno::operator%(complexno& c1) {

    // complexno rr=(pow(c1.getreal(),2)) + pow(c1.getimag(),2,0);
    // complexno res = sqrt(c1.getreal()*c1.getreal()+c1.getimag()*c1.getimag());
    return sqrt(c1.getreal() * c1.getreal() + c1.getimag() * c1.getimag());
}

complexno complexno::operator/(complexno c2) {
    // complexno r((c1.getreal()+c1.getimag())*(c2.getreal()+c2.getimag())
    // r=(a + bi) * (c - di) / (c + di) * (c - di);
    complexno numerator = (*this) * conjugate(c2); //operator*((*this), conjugate(c2));
    complexno denomenator = (*this) * conjugate(c2); // operator*(c2, conjugate(c2));
    // complexno r((mulltiply(c1,conjugate(c2))/mulltiply(c2,conjugate(c2));
    complexno r = (numerator, denomenator);
    return r;
}



// complexno mulltiply(complexno c1, complexno c2) {
//     complexno r((c1.getreal() * c2.getreal()) - (c1.getreal() * std::abs(c2.getimag())),
//                  c1.getimag() + c2.getreal() - (c1.getreal() * std::abs(c2.getimag())));
//     return r;
// }

// void minus(complexno c1, const complexno& c2) {
//     c1.setreal() -= c2.realpart;
//     c1.imginarypart -= c2.imginarypart;
// }

// complexno subtract(complexno& c1, const complexno& c2) {
//     complexno result = c1;
//     minus(result, c2);
//     return result;
// }














/*
aik trha is trha likh saktey hain

fraction don;
don.set_fraction(fr1.get_fraction+fr2.get_fraction);
return don;

or dosri tarha iss trha likh saktey hain

fraction don(idk)
*/



//============================= FRACTION CLASS ==============================



class fraction {

private:

    int numerator;
    int denominator;

public:

    fraction();
    fraction(int jj, int gg);
    fraction& simplify();
    int gcd(int a, int b);
    int getnum();
    int getden();
    void setnum(int _num);
    void setden(int _den);
    friend ostream& operator<< (ostream& cout, const fraction& name) {

        
            if (name.denominator == 0)
                cout << "Invalid Denominator! Cannot be zero.";
            else
                cout << name.numerator << "/" << name.denominator;
        
            return cout;

    }
    fraction gcd(fraction a, fraction b);
    fraction& reduce(fraction num,fraction den);
    fraction operator+(fraction f2);
    fraction operator-(fraction f2);
    fraction operator*(fraction f2);
    fraction operator/(fraction f2);
    fraction add_inverse(fraction f1);
    fraction multiplicative_inverse(fraction f1);



};





    fraction& fraction::simplify()
     {
        int divisor = std::min(abs(numerator), abs(denominator));
        while (divisor > 1) {
            if (numerator % divisor == 0 && denominator % divisor == 0) {
                numerator /= divisor;
                denominator /= divisor;
            }
            divisor--;

        }

        bool isNegative = numerator * denominator < 0;

        if (isNegative) {
            numerator = -numerator;
        }

        return *this;
    }


    fraction::fraction()
    {
        numerator=0;
        denominator=1;
    }

    fraction::fraction(int jj,int gg)
    {
        numerator=jj;
        denominator=gg;
    }

 int  fraction::getnum()
 {
return this->numerator;
    }

 int  fraction::getden()
 {
    return this->denominator;
    }

void  fraction::setnum(int _num)
{
        this->numerator = _num;
    }

  void  fraction::setden(int _den)
  {
        if(_den==0)
            cout<<"Invalid Denominator! Cannot be zero.";
        else
        this->denominator = _den;
    }

     //void fraction::print() const {
     //    if(denominator==0)
     //        cout<<"Invalid Denominator! Cannot be zero.";
     //        else
     //   cout <<this-> numerator << "/" <<denominator;
     // }

     /*
    fraction fraction::gcd(fraction a, fraction b) {
    while (b != 0) {
     int temp = a % b;
     a = b;
     b = temp;
   }
   return a;
 }

     fraction& fraction::reduce(fraction num,fraction den){
     fraction g=gcd(num,den);
     num/=g;
     den/=g;
     *this=fraction(num,den);
     return *this;
 }

     */



     //----------



     fraction fraction::operator+(fraction f2) {

         fraction result(((*this).getnum() * f2.getden()) + (f2.getnum() * (*this).getden()), ((*this).getden() * f2.getden()));
         return result;
     }


     fraction fraction::operator-(fraction f2) {

         fraction result(((*this).getnum() * f2.getden()) - (f2.getnum() * (*this).getden()), ((*this).getden() * f2.getden()));
         return result;
     }

     fraction fraction::operator*(fraction f2) {

         fraction result(((*this).getnum() * f2.getnum()), ((*this).getden() * f2.getden()));
         return result;
     }

     fraction fraction::add_inverse(fraction f1) {

         if (f1.getnum() == 0)
         {

             fraction();
         }
         else {
             fraction result(f1.getnum() * -1, f1.getden());
             return result;
         }
     }

     fraction fraction::operator/(fraction f2) {

         fraction r((*this).getnum() * f2.getden(), (*this).getden() * f2.getnum());
         return r;
     }

     fraction fraction::multiplicative_inverse(fraction f1) {

         fraction r(f1.getden(), f1.getnum());

         return r;
     }

     //     int gcd(int a, int b) {
     //   while (b != 0) {
     //     int temp = a % b;
     //     a = b;
     //     b = temp;
     //   }
     //   return a;
     // }

     // fraction& reduce(){
     //     int g=gcd(f1.getnum(),f1.getden());
     // }


     //     fraction reduced (fraction f1){

     //         // fraction r(f1.getden(),f1.getnum());

     //             // int gcd(int a, int b) {
     //   while (f1.getden() != 0) {
     //     // int temp = f1.getnum() % f1.getden();
     //     fraction rfr=f1.getnum();
     //     b = temp;
     //   }
     //   return a;
     // }


     //         return r;
     //     }


