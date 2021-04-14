#include <iostream>
#include "ItemToPurchase.h"
using namespace std;


ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, string desc, int price, int quantity)
{
  itemName = name;
  itemDescription = desc;
  itemPrice = price;
  itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name)
{
  itemName = name;
}
string ItemToPurchase::GetName() const
{
  return itemName;
}

void ItemToPurchase::SetPrice(int price)
{
  itemPrice = price;
}

int ItemToPurchase::GetPrice() const
{
  return itemPrice;
}

void ItemToPurchase::SetQuantity(int q)
{
  itemQuantity = q;
}

int ItemToPurchase::GetQuantity() const
{
  return itemQuantity;
}

void ItemToPurchase::SetDescription(string desc)
{
  itemDescription = desc;
}

string ItemToPurchase::GetDescription() const
{
  return itemDescription;
}

void ItemToPurchase::PrintItemCost()
{
  //Bottled Water 10 @ $1 = $10
  cout << this->itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl;
}

void ItemToPurchase::PrintItemDescription()
{
  //Bottled Water: Deer Park, 12 oz.
  cout << this->itemName + ": " + this->itemDescription << endl;
}
