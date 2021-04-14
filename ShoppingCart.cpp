#include <iostream>
#include <vector>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart(){
  customerName = "none";
  currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date){
  customerName = name;
  currentDate = date;
}

string ShoppingCart::GetCustomerName() const{
  return customerName;
}

string ShoppingCart::GetDate() const{
  return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item){
  cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name){
  bool found = false;
  
  for(int i = 0; i < cartItems.size(); i++){
    
    if(cartItems.at(i).GetName() == name){
      found = true;
      cartItems.erase(cartItems.begin() + i);
    }
  }
    
  if(!found){
    cout << "Item not found in cart. Nothing removed." << endl;
  }
}

void ShoppingCart::ChangeQuantity(string nameOfItem, int newQuantity){
  bool found = false;
  
  for(int i = 0; i < cartItems.size(); i++){
    
    if(cartItems.at(i).GetName() == nameOfItem){
      cartItems.at(i).SetQuantity(newQuantity);
      found = true;
    }
  }
  
  if(!(cartItems.size() == 0 || found)){
    cout << "Item not found in cart. Nothing modified." << endl;
    return;
  }
  
}

int ShoppingCart::GetNumItemsInCart(){
  int totalQuantity = 0;
  
  for(int i = 0; i < cartItems.size(); i++){
    totalQuantity += cartItems.at(i).GetQuantity();
  }
  return totalQuantity;
}

double ShoppingCart::GetCostOfCart()
{
  int total = 0;
  for(int i = 0; i < cartItems.size(); i++){
    total += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
  }
  return total;
}

void ShoppingCart::PrintTotal()
{
  if(cartItems.size() == 0){
    cout << "SHOPPING CART IS EMPTY" << endl;
  }
  
  for(int i = 0; i < cartItems.size(); i++){
    cartItems.at(i).PrintItemCost();
  }
  cout << endl << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions()
{
  if(cartItems.size() == 0){
    cout << "SHOPPING CART IS EMPTY" << endl;
    return;
  }
    
  for(int i = 0; i < cartItems.size(); i++){
    ItemToPurchase currentItem = cartItems.at(i);
    currentItem.PrintItemDescription();
  }
}
