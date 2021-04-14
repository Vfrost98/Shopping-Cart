#ifndef ITEMTOPURCHASE_H_INCLUDED
#define ITEMTOPURCHASE_H_INCLUDED

#include <iostream>
using namespace std;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string, string, int, int = 1);
    void SetName(string);
    string GetName() const;
    void SetPrice(int);
    int GetPrice() const;
    void SetQuantity(int);
    int GetQuantity() const;
    void SetDescription(string);
    string GetDescription() const;
    void PrintItemCost();
    void PrintItemDescription();

private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;
};


#endif // ITEMTOPURCHASE_H_INCLUDED
