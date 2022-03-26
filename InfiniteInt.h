//File Name: InfiniteInt.h
//Name: Andres Marin
//Date: 01/20/2021
/*Description: This file is the header file which holds all of the declarations for the
  .cpp file methods.
 *This file starts off by creatign a structure node the will holds the int value variable
  which will be used to hold the nodes value.
  *It also holds the next and prev node whioch will be sued to travers through the linked list.
  *Next is holds the InfiniteInt class which contains all of the private member variables and 
   public functions for this class.
  *The member variables consit of the int count variable, the bool signFlag variable
   and the head and tail nodes for the linked list.
 *The publcui functions consit of all three constructor, the destructotr and the various methods
  at will be used to manipulate, insert, delete, compare, input and ooutput the values of the 
  InfiniteInt objects.
 *The parametric constructor and the conversion method have explicit to prevent any implicit 
  declarations.
 *Both stream functions use friend keyword to allow access to the private variables of the class.
 */
#pragma once
#include <iostream>
using namespace std;

//Node Structure to hold 
//The next, previous nodes and node value.
struct Node{
    int data;
    Node* next;
    Node* prev;
};

//InfiniteInt class
class InfiniteInt{
    //Private member variables.
    //Private member nodes.
    private:
       int count_;
       bool signFlag_;
       Node* head_;
       Node* tail_;

    //public member functions.
    //functions declaration and definitions.
    public:
       InfiniteInt();//default constructor
       InfiniteInt(const InfiniteInt& other);//deep copy constructor.
       explicit InfiniteInt(int value);//parametric constructor.
       ~InfiniteInt();//destructor.
       explicit operator int () const; //conversion method

       //overloaded assignment operator function.
       InfiniteInt& operator=(const InfiniteInt& other);
       bool operator==(const InfiniteInt& other);//boolean comparison function
       bool operator<(const InfiniteInt& other);//boolean comparison function
       void insert(int value);//insert function.
       void copy(const InfiniteInt& other);//copy function.
       void clear();//clear function.
       int numDigits(void) const;//node count function.

       //Overloaded iostream operators to input and output InfiniteInt objects.
       friend istream& operator>>(istream& input, InfiniteInt& list);
       friend ostream& operator<<(ostream& output, const InfiniteInt& list);
       
};