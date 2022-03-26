#include <iostream>
#include "InfiniteInt.h"

using namespace std;

int main()
{
  cout << "InfiniteInt::InfiniteInt(): Creating InfiniteInt with default initialization...";
  InfiniteInt b1;
  cout << "\n     done; value is " << b1 << " (should be zero)" << endl << endl;

  cout << "InfiniteInt::InfiniteInt(int): Creating and initializing from an int...";
  InfiniteInt b2{123456};
  cout << "\n     done; value is " << b2 << " (should be 123456)" << endl << endl;

  cout << "InfiniteInt::InfiniteInt(const InfiniteInt&): Creating and initializing from small InfiniteInt...";
  InfiniteInt b3{b2};
  cout << "\n     done; value is " << b3 << " (should be 123456)" << endl << endl;

  cout << "InfiniteInt::operator int(): converting InfiniteInt to int (explicit)...";
  int i = int(b2);
  cout << "\n     done; value is " << b2 << " (should be 123456)" << endl << endl;

  cout << "InfiniteInt::operator=(): assigning value to InfiniteInt (from converted int)...";
  b1 = InfiniteInt(456789);
  cout << "\n     done; value is " << b1 << " (should be 456789)" << endl << endl;

  cout << "InfiniteInt:operator+(): not implemented\n";
//  b2 = b2 + b1;
//  cout << "\n     done; value is " << b2 << " (should be 580245)" << endl << endl;

  cout << "InfiniteInt::InfiniteInt(const InfiniteInt&): checking deep copy...";
  cout << "\n     done; value is " << b3 << " (should be 123456)" << endl << endl;

  cout << "InfiniteInt:operator-(): not implemented\n";
  //b2 = b2 - b1;
  //cout << "\n     done; value is " << b2 << " (should be 123456)" << endl << endl;

  cout << "InfiniteInt:operator*(): not implemented\n";
  //b3 = b1 * b2;
  //cout << "\n     done; value is " << b3 << " (should be 56393342784)" << endl << //endl;

  cout << "InfiniteInt:operator<(): comparing two InfiniteInts...";
  if (b2 < b1)
    cout << " successful" << endl << endl;
  else
    cout << " unsuccessful" << endl << endl;

  cout << "InfiniteInt:operator==(): comparing two InfiniteInts...";
  if (b2 == InfiniteInt(123456))
    cout << " successful" << endl << endl;
  else
    cout << " unsuccessful" << endl << endl;

    /*
  cout << "Using multiplication to generate successively larger InfiniteInts...";
  InfiniteInt product{1};
  for (int j = 2; j <= 8; j++)
    product = product * InfiniteInt(j);
  cout << "\n     8! is " << product
       << " (should be 40320)" << endl;
  product = InfiniteInt(1);
  cout << "          reset to 1: " << product << endl;
  for (int j = 2; j <= 12; j++)
    product = product * InfiniteInt(j);
  cout << "\n     12! is " << product
       << " (should be 479001600)" << endl;
  product = InfiniteInt(1);
  cout << "          reset to 1: " << product << endl;
  for (int j = 2; j <= 21; j++)
    product = product * InfiniteInt(j);
  cout << "\n     21! is " << product
       << " (should be 51090942171709440000)" << endl << endl;
     */
  
  cout << "operator>>(): reading InfiniteInt from cin...";
  cin >> b1;
  cout << "\n     done; value is " << b1
       << " (should be 9876)" << endl;

  cout << "All tests complete." << endl;
}