//This is the HEADER FILE sale.h.
//This is the INTERFACE for the class Sale.
//Sale is a class for simple sales.
#ifndef SALE_H
#define SALE_H

#include <iostream>
using namespace std;

namespace savitchsale
{

    class Sale
    {
    public:
        Sale();
        Sale(double the_price);
        double bill() const;
        double savings(const Sale& other) const;
        //Returns the savings if you buy other instead of the calling object.
    protected:
        double price;
    };

    bool operator < (const Sale& first, const Sale& second);
    //Compares two sales to see which is larger.

}//savitchsale

#endif // SALE_H
