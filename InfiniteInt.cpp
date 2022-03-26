//File Name: InfiniteInt.cpp
//Name: Andres Marin
//Date: 01/20/2021
/*Description:This source code file will be able to implement all of the 
*function declarations from the header file.
 *The file begins by implementing the default constructor. 
 *The default constructor sets the head and tail node to empty and the count at 0.
 *Next is the copy constructor that takes an Infiniteint object as a parameter.
 *This constructor calls on the copy method to make a deep copy of another object.
 *The next constructor is the parametarized constructor which takes an integer as
  a parameter. 
 *This constructor calls on the insert method to add the individual
 values with in a digit and insert them into a linked list.
 *The next constructor is the destructor that is used to delete the allocated memory
  and prevent any memory leaks or dangling pointers.
 *The destructor calls on the clear method to delete the nodes.
 *Next is the insert method which takes an integer as a parameter.
  this method sets both the head node to nullptr and the count variable to 0.
 *It then checks if the parameter value is positive or negative.
 *If it is positive it sets the signFlag variable to false. 
 *If the value is negative the it will set the signFlag variable to true.
 *Next it will traverse through the digit with a while loop.
 *If the value is positive then it will traverse the number until it is less than 0.
 *If it is negative it will travers the number until it is greater than 0.
 *Next the function will take the value and modulo to isolate one digit at a time.
 *It will then insert that digit into a temporary node and then the value will 
  be divided by 10 to get rid of that digit.
 *Next if the head node is empty the function will insert that value from the
  temporary node into the head node.
 *If the head node is not empty then it will insert the value into the next node
  and link that node with the next node.
 *The negative value has the same process but instead of inserting all the negative
  all the negative values it takes the absolute value of the number and then inserts
  it into the node.
 *The next method is the copy constructor which takes an another object and 
  deep copies all of the values into the originla object. 
 *The function does this by traversing the other list and copying all of the values
  into new nodes.
 *The next method is clear method. This method will set a new node to the head node.
 *It will then traverse that list using the while loop. 
 *With in the wild loop the function will set the new node to point to the next node.
 *It will then delete the head node and set the head node to the  new node so it can
  continue travers the list and delete all the nodes to prevent a memory leak.
 *The next method is the conversion method which wil take an object and convert it into
  and integer. 
 *This method will traverse through the list using a while loop. 
 *Within the wild loop the int variable will hold the values of the nodes and multiply 
  by 10.
 *This will move the place value by times to so that the next value could be added.
 *Next the value will be compared to the INT_MAX and INT_MIN to prevent any overflow.
 *The next method is the = operator method. This method takes an object as a parameter
  and return an object. 
 *This method will compare the addresses of two lists.
 *If they are equal then the method will return the original list.
 *If they are not equal then the method will clear the oringinal list and deep copy
  the other list into it.
 *The next method is the == operator method.This method takes an object as a parameter
  and returns an boolean.
 *This method will compare the values of both lists. If they are equal the list will
  return true.
 *The method compares the two list first based on their size, next based on if they are
  both negative or positive and if they are it will compare their values by traverisng
  through the list with a while loop.
 *The next function is the < operator function. This method will compare the two list
  based on their value. The method compares them using their size, if their positive or
  negative.
 *If they both are positive or negative, the method will traverse through the list 
  using a while loop and compare their values.
 *The next method is the numDigits method that returns the size of a list.
 *This is done by returning the count variable from the insert method.
 *The next function is the overload istreammethod that takes in both a istream object
  and an InfiniteInt object. 
 *This method will take the users input and store it in a string variable.
 *It whell then take each character in the string and insert it into a node.
 *The method also checks if the value is positive or negative and if the first value is
  a digit or the "-" symbol.
 *The method adds each character like the insert method but instead uses a for loop to
  traverse through the string variable.
 *If the user inputs anything but a digit or a "-" symbol it will throw and exception.
 *The final method is the overload ostream method that takes a ostream object and  
  an InfiniteInt object as a parameter and returns an ostream object.
 *The method sets current node as the head node of the list parameter.
 *It then checks if the object is positive or negative through the signFlag variable.
 *It then traverses through the list and prints out the values ofthe list.
 *If the list is negative then the method will print out "-" symbol infront of the
  values.
 *The method than return the ostream object.
 */
#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include "InfiniteInt.h"
using namespace std;

//Default constructor.
InfiniteInt::InfiniteInt(){
    
    //sets count to 0.
    count_ = 0;

    //Sets both head and tail nodes to nullptr.
    head_ = nullptr;
    tail_ = nullptr;
}

//Deep Copy constructor.
//Takes and InfiniteInt object as a parameter.
InfiniteInt::InfiniteInt(const InfiniteInt& other){

    //Invokes copy method.
    copy(other);
}

//parameterized counstructor.
//Takes an int variable as a parameter.
InfiniteInt::InfiniteInt(int value){

    //calls insert method.
    insert(value);
}
//destructor used to prevent memory leaks.
InfiniteInt::~InfiniteInt(){
    clear(); 
}

//insert method used to add values to new nodes.
//Insert method takes one int variable.
void InfiniteInt:: insert(int value){

     //Sets head node to nullptr;.
    //Sets count to 0.
    head_ = nullptr;
    count_ = 0;
    
    //If statement to check if number is negative.
    if (value > 0){
        //sets sign flag to false to demonstrate positive number.
        signFlag_ = false;

        //While loop to traverse through the int variable.
        //Adds it isolated number to the link list.
        while(value > 0){

            //modulus 10 used to isolate number.
            int number = value % 10;

            //new node create to allocate memory
            Node* insertNode = new Node;

            //Number value is being added to the node.
            insertNode -> data = number;
            //The previous node is empty.
            insertNode -> prev = nullptr;

            //Last value removed.
            value /= 10;
            
            //if statement if the head node is empty
            if (head_ == nullptr){

                //head and tail node holds new nodes value.
                head_ = insertNode;
                tail_ = insertNode;
                //head previous node is empty.
                head_ -> prev = nullptr;
                count_++;//counts lists nodes.
            } else {
                //The connects the new node to the head node.
                insertNode -> next = head_;
                //head_ node takes the value of new node.
                head_ = insertNode;
                count_++;
            } 
            //The tails next node is empty.
            tail_ -> next = nullptr;  
        }
    //else statement for negative number.
    } else {
        //sets sign flag to true to demostrate negative number
        signFlag_ = true;

        //while loop used to traverse negative number.
        //Adds isolated numbers to nodes.
        while(value < 0){

            //the sets the absolute value for the variable.
            //Used to prevent "-" from being added to each node.
            int number = abs(value) % 10;

            Node* insertNode = new Node;
            insertNode -> data = number;
            insertNode -> prev = nullptr;
            value /= 10;
            if (head_ == nullptr){
                head_ = insertNode;
                tail_ = insertNode;
                head_ -> prev = nullptr;
                count_++;
            } else {
                insertNode -> next = head_;
                head_ = insertNode;
                count_++;
            } 
            tail_ -> next = nullptr;
        }
    }

}

//copy function used to copy the values of one object to the other.
//Function takes a constant reference object as a parameter.
void InfiniteInt:: copy(const InfiniteInt& other){
    
    //if statement to check if other.head is empty.
    if (other.head_ == nullptr){
        //both head and tail node will be empty.
        head_ = nullptr;
        tail_ = nullptr;
    //else statement if other list is not empty.
    } else {
        
        //current node holds other.head.
        Node* current = other.head_;

        //head allocates memory for new node.
        head_ = new Node;

        //head node copies the current nodes data.
        head_  -> data = current -> data;

        //temporary node to hold the head node.
        Node* copy = head_;

        //sets current to the next node.
        current = current -> next;

        //while loop to traverse the other list.
        while(current != nullptr){
            //creates new node to allocate memory.
            copy -> next = new Node;
            //sets copy to the next node.
            copy = copy -> next;
            //copies the other list data.
            copy -> data = current -> data;
            //sets copy's next node to empty.
            copy -> next = nullptr;

            current = current -> next;
        }
        //sets current list count and sign flag to
        //the values of the other list.
        this -> count_ = other.count_;
        this -> signFlag_ = other.signFlag_;
    }
}

//clear method used to prevent memory leaks.
void InfiniteInt::clear(){

    //sets deleteNode the lists head_ node.
    Node* deleteNode = head_;
    
    //while loop traverses through the linked list.
    while (deleteNode != nullptr){
        //sets deleteNode to the next node.
        deleteNode = deleteNode -> next;
        //deletes the value in the head node.
        delete head_;
        //sets head node to the deleteNode
        //next node.
        head_ = deleteNode;
    }
}

//method used to convert InfiniteInt object to an integer.
InfiniteInt::operator int () const{
    //Int variables used to convert the values
    //of the InfiniteInt object to integer.
    int number;

    //total is set to 0 so it can hold the nodes values.
    int total = 0;

    //sets the current to the heaad node.
    Node* current = head_; 
    
    //While loop used to traverse through the linked list.
    while (current != nullptr){

        //variable holds the current nodes value.
        number = current -> data;

        //total multiplies its self by 10 
        //to move place values.
        //It then adds the node value.
        total = (total * 10) + number;
        //Sets current to the next node.
        current = current -> next;
    }

    //If statement to check if total is negative or psotive.
    if (signFlag_){
        //if it is negative it multiplies the total by -1;
        total *= -1;
        //checks if the value is less than INT_MIN
        if ( total < INT_MIN){
            //if it is it throws invalid argument.
            throw invalid_argument ("Integer overflow");
        } else { //else returns total
            return total;
        }
    } else {//if total is positive
        //checks if the value is less than INT_MIN
        if ( total > INT_MAX){
            //if it is it throws invalid argument.
            throw invalid_argument ("Integer overflow");
        } else {//else returns total
            return total;
        }
    }
    return total;
}
//Overlode assignment operator function.
//Takes a constant reference object as a parameter
//returns a reference object.
InfiniteInt& InfiniteInt::operator=(const InfiniteInt& other){
   
   //if statement to check if both list are the same.
   if(this == &other ){

       //if it is the function return *this.
       return *this;
   //else statement in case the lists are not the same.    
   } else {
       //invokes clear method to empty the list nodes.
       clear();
       //invokes copy function to create a deep copy.
       copy(other);
   }
   //returns *this.
   return *this;
}
//Boolean comparison function. 
//Takes an InfiniteInt object and returns a boolean.
bool InfiniteInt::operator==(const InfiniteInt& other){

    //boolean variable used to return result.
    bool result = false;

    //Node list1 and list2 used to
    //traverse through both lists.
    Node* list1 = head_;
    Node* list2 = other.head_;

    //While used to traverse through both lists.
    while (list1 != nullptr || list2 != nullptr){

        //if statement used to prevent any segmentation fault.
        //keeps traversing through list even if one is smaller than
        //the other.
        if ( (list1 == nullptr) || (list2 == nullptr)){

            //returns false if one list is smaller than
            //the other.
            return false;
        }else{//else statement to traverse the lists if they dont equal nullptr.

            //If statement used to check if lsits are negative or positive.
            if ((signFlag_ && other.signFlag_) || (!signFlag_ && !other.signFlag_)){
                 
                //checks the individual values of the nodes.
                if( list1 -> data == list2 -> data){
                    //Returns true if values are equal.
                    result =  true;
                } else {
                    //if they are not returns false.
                    return false;
                }
            } else{//else statement in case one list is negative and one is positive.
                return false;
            } 
        }//ends if else statement.
        
        //sets lists to the next node.
        list1 = list1 -> next;
        list2 = list2 -> next;
    }//ends while loop.

    //returns final result.
    return result;
}
///Boolean comparison function. 
//Takes an InfiniteInt object and returns a boolean.
bool InfiniteInt::operator<(const InfiniteInt& other){
    ////boolean variable used to return result.
    bool result = false;

    //Node list1 and list2 used to
    //traverse through both lists.
    Node* list1 = head_;
    Node* list2 = other.head_;

   //If statment used to compare list if they are the same size..
   if (numDigits() == other.numDigits()){
       
       //if statement used to compare lists based on if one
       //is negative and the other positive.
       if (signFlag_ && !other.signFlag_){

           //returns true if list1 is negative.
           //list1 is less than.
           result = true;
       } else if (!signFlag_ && other.signFlag_){

           //returns false if list2 is negative.
           //list1 is greater than.
           return false;
       } else {//else statement if both lists are negative or positive.
           
           //while loop used to traverse both lists
           //to compare values.
           while (list1 != nullptr && list2 != nullptr){
               
                //if statment to check if both lists are positive.
                if (!signFlag_ && !other.signFlag_){

                    //if statement used to compare values.
                    if(list1 -> data < list2 -> data){
                        //returns true if list1 is less than.
                        return true;
                    } else {
                        //returns false if list1 is greater than.
                        result = false;
                    }
                } else {//else statement if bboth lists are negative.
                    
                    //if statement to compare the values of both lists.
                    if (list1 -> data > list2 -> data){
                        //returns true if list1 has a larger negative value.
                        return true;
                    } else {
                        //returns true if list1 has a smaller negative value.
                        result =  false;
                    }
                }//ends if else statment.
            
                //sets lists to the next node.
                list1 = list1 -> next;
                list2 = list2 -> next;
           }//ends while loop.
        }
    } else {//else statement if size of lists are not the same.
        
        //if statement to check if both lists are positive.
        if (!signFlag_ && !other.signFlag_ ){

            //if statement to compare lists by size.
            if (numDigits() < other.numDigits()){

                //returns true if list1 is less than.
                result = true;
            } else {
                //returns false if list1 is greater than.
                 return false;
            }
        // else statement if both lists are negative.
        } else if (signFlag_ && other.signFlag_){
            if (numDigits() < other.numDigits()){
                //returns  false if list one is greater than.
                return false;
            } else {
                //returns true if list1 is less than
                result = true;
            }
        //else if one list1 is negative.
        } else if (signFlag_ && !other.signFlag_){
            result = true;
        } else {//else statement if list2 is negative.
            return false;
        }
   }
   //returns final result.856
   return result;
}
//numDigits function used to count the number 
//of values within each linked list.
int InfiniteInt::numDigits(void) const{
    //returns the count int variable.
    return count_;
}
//Overload istream operator.
//takes istream and an Infinite int object as a parameter.
istream& operator>>(istream& input, InfiniteInt& list){
    
    //sets head node to empty.
    list.head_= nullptr;

    //string variable use to hold users input.
    string number = "";
    
    //inputs users value into the number variable.
    input >> number;
    
    //if statement used to check if first character
    //is a number or "-". 
    if (isdigit(number.at(0)) || number.at(0) == '-'){

        //Checks if input is a negative values.
        if(number.at(0) == '-'){
            //for loop used to traverse through string input.
            //starts at the end of the string to input char
            //in forward order.
            for( int i = number.length() - 1; i >= 1; i--){

                //code the same as the insert method.
                list.signFlag_ = true;
                Node* newNode = new Node;

                //takes the aboslute values for negative number.
                //uses ASCII decimal value to get the appropiate number.
                newNode -> data = abs(number.at(i)) - 48;

                if(list.head_ == nullptr){
                    list.head_ = newNode;
                    list.tail_ = newNode;
                    list.head_ -> prev = nullptr;
                    list.count_++;
                } else {
                    newNode -> next = list.head_;
                    list.head_ = newNode;
                    list.count_++;
                }
                list.tail_ = nullptr;
            }
        } else {//else statement for positive input.
            
            //for loop used to traverse through string input.
            //starts at the end of the string to input char
            //in forward order.
            for (int i = number.length() - 1; i >= 0; i--){

                //code the same as the insert method.
                list.signFlag_ = false;
                Node* newNode = new Node;

                //takes the aboslute values for negative number.
                //uses ASCII decimal value to get the appropiate number.
                newNode -> data = number.at(i) - 48;

                if(list.head_ == nullptr){
                    list.head_ = newNode;
                    list.tail_ = newNode;
                    list.head_ -> prev = nullptr;
                    list.count_++;
                } else {
                    newNode -> next = list.head_;
                    list.head_ = newNode;
                    list.count_++;
                }
                list.tail_ = nullptr;
            }
        }
    } else {//else statement for input other than numbers and "-".

        //throws invalid argument exception.
        throw invalid_argument("invalid input");
    }
    //returns istream input.
    return input;
}
//overload ostream function.
//Takes an ostream and an infiniteInt object as parameters.
ostream& operator<<(ostream& output, const InfiniteInt& list){
    //sets current to the other list head node.
    Node* current = list.head_;
    
    //if statement to check if InfiniteInt
    //object is negative.
    if (list.signFlag_){

        //if it is outputs "-" in front of list.
        output << "-";
        //while loop to traverse linked list.
        while(current != nullptr){

            //outputs current nodes value.
            output << current -> data;
            //sets current to the next node.
            current = current -> next;
        }
    //else statement for positive InfiniteInt object.
    } else {
        
        //same process as above.
        while(current != nullptr){
            output << current -> data;
            current = current -> next;
        }
    }
    //returns ostream output.
    return output;
}
