#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void printCustomerNameAndDate(ShoppingCart &cart)
{
  cout << "Customer name: " << cart.GetCustomerName() << endl;
  cout << "Today's date: " << cart.GetDate() << endl;
}

void printMenu()
{
  cout << endl << "MENU" << endl <<
         "a - Add item to cart" << endl <<
         "d - Remove item from cart" << endl <<
         "c - Change item quantity" << endl <<
         "i - Output items' descriptions" << endl <<
         "o - Output shopping cart" << endl <<
         "q - Quit" << endl << endl;
}

void getUserInput(char &userInput)
{
  vector<char> menuChoices = {'a', 'd', 'c', 'i', 'o', 'q'};
  
  do
    {
      cout << "Choose an option: ";
      cin >> userInput;
      cin.ignore();
    } while(find(menuChoices.begin(), menuChoices.end(), userInput) == menuChoices.end());
}

void addItemToCart(ShoppingCart &cart)
{
  string itemName, itemDes;
  int itemPrice, itemQuan;
  
  cout << "ADD ITEM TO CART" << endl;
  cout << "Enter the item name:" << endl;
  getline(cin, itemName);
  cout << "Enter the item description: " << endl;
  getline(cin, itemDes);
  cout << "Enter the item price:" << endl;
  cin >> itemPrice;
  cin.ignore();
  cout << "Enter the item quantity:" << endl;
  cin >> itemQuan;
  //cin.ignore();
  ItemToPurchase newItem(itemName, itemDes, itemPrice, itemQuan);
  cart.AddItem(newItem);
}

void removeItemFromCart(ShoppingCart &cart)
{
  string itemName;
  
  cout << "REMOVE ITEM FROM CART" << endl;
  cout << "Enter name of item to remove:" << endl;
  getline(cin, itemName);
  cart.RemoveItem(itemName);
}

void changeItemQuantity(ShoppingCart &cart)
{
  string itemName;
  int itemQuan;
  
  cout << "CHANGE ITEM QUANTITY" << endl;
  cout << "Enter the item name:" << endl;
  getline(cin, itemName);
  cout << "Enter the new quantity:" << endl;
  cin >> itemQuan;
  cart.ChangeQuantity(itemName, itemQuan);
}

void outputItemDescriptions(ShoppingCart &cart)
{
  cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
  cout << cart.GetCustomerName() << "\'s Shopping Cart - " << cart.GetDate();
  cout << endl << endl << "Item Descriptions" << endl;
  cart.PrintDescriptions();
}

void outputShoppingCart(ShoppingCart &cart)
{
  cout << "OUTPUT SHOPPING CART" << endl;
  cout << cart.GetCustomerName() << "\'s Shopping Cart - " << cart.GetDate() << endl;
  cout << "Number of items: " << cart.GetNumItemsInCart() << endl << endl;
  cart.PrintTotal();
}

int main()
{
  string itemName, itemDate;
  char userInput;
  
  cout << "Enter customer's name: " << endl;
  getline(cin, itemName);
  cout << "Enter today's date:" << endl;
  getline(cin, itemDate);
  
  ShoppingCart cart(itemName, itemDate);
  
  printCustomerNameAndDate(cart);
  
  do{
    printMenu();
    getUserInput(userInput);
  
    if(userInput == 'a'){
      addItemToCart(cart);
    }

    else if(userInput == 'd'){
      removeItemFromCart(cart);
    }
  
    else if(userInput == 'c'){
      changeItemQuantity(cart);
    }
  
    else if(userInput == 'i'){
      outputItemDescriptions(cart);
    }

    else if(userInput == 'o'){
      outputShoppingCart(cart);
    }
    
  } while(userInput != 'q');

  return 0;
}
