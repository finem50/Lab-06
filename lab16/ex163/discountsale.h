//This is the INTERFACE for the class DiscountSale.
#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"

namespace savitchsale
{
    class DiscountSale : public Sale
    {
    public:
        DiscountSale();
        DiscountSale(double the_price, double the_discount);
        //Discount is expressed as a percent of the price.
        double bill() const;
    protected:
        double discount;
    };
}//savitchsale
#endif //DISCOUNTSALE_H 
