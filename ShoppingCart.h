#ifndef SHOPPINGCART_H_INCLUDED
#define SHOPPINGCART_H_INCLUDED

#include <iostream>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string, string);
    string GetCustomerName() const;
    string GetDate() const;
    void AddItem(ItemToPurchase);
    void RemoveItem(string);
    void ChangeQuantity(string, int);
    int GetNumItemsInCart();
    double GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};


#endif // SHOPPINGCART_H_INCLUDED
