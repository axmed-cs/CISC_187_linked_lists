/******************************************************************************

Ahmed Abdullahi

Chapter 18 programming assignment - Linked Lists

November 2023

This is the Implementation file for the BeadList Class

*******************************************************************************/
#include <iostream>
#include <string>
#include "BeadList.h"
using namespace std;


/************************************
BeadList default contructor
************************************/
BeadList::BeadList()
{
    head = nullptr;
}

/************************************
BeadList destructor
************************************/
BeadList::~BeadList(){
    ListNode *nodePtr;  // traverse the List
    ListNode *nextNode; // next node pointer
    
    //point node at head of List
    nodePtr = head;
    
    //while nodePtr is at the head of the list
    while(nodePtr != nullptr){
        //points to the next node
        nextNode = nodePtr->next;
        
        //delete the current node
        delete nodePtr;
        
        //position nodePtr to the next node
        nodePtr = nextNode;
    }
}



/************************************
BeadList append (add at end of list)
************************************/
void BeadList::append(string input){
    ListNode *newNode; //new node pointer
    ListNode *nodePtr; // traverse through the list
 
     //validate input
   if (!(input=="turquoise"||input=="coral"||input=="gold"||input=="copper")){  
            exit(EXIT_FAILURE);
        }
    
    // allocate new node and store input there
    newNode = new ListNode; 
    newNode->bead = input;
    newNode->next = nullptr;
    
    //if list is empty make newNode the first node
    //other wise traverse list and add newNode at the end
    if (!head){
        head = newNode;
    }
    else{
        nodePtr = head;
        
        while(nodePtr->next){
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}


/************************************
BeadList insert (anywhere in the list)
************************************/
int BeadList::insert(string input, int n){
    ListNode *newNode;                //new node pointer
    ListNode *nodePtr;                // traverse through the list
    ListNode *previousNode = nullptr; // points to the previous node
    
    //validate input
   if (!(input=="turquoise"||input=="coral"||input=="gold"||input=="copper")){  
            exit(EXIT_FAILURE);
        }
   
   
    // allocate new node and store input there
    newNode = new ListNode; 
    newNode->bead = input;
    
   
    // if list is empty make head point to new node 
    if (!head){
        head = newNode;
        newNode->next = nullptr;
        
        //confirmation 
        cout << "We have inserted it at position 0 since list is empty." << endl;
        
    }
    else{
        int counter = 0;
        nodePtr = head;
        previousNode = nullptr;
        
        //skip all the nodes whose position is not at n
        while(nodePtr!=nullptr && counter != n){
            previousNode = nodePtr;
            nodePtr = nodePtr->next; 
            counter++;
        }
        
        //if newNode is the first in the list
        // insert it before all the node
        if(previousNode == nullptr && n == 0){
            head = newNode;
            newNode->next = nodePtr;
            //confirmation 
             cout << "We have inserted it." << endl;
        
        }
        else{
            //if counter is equal to n then insert new node
            if(counter == n){
            //insert new node
            previousNode->next = newNode;
            newNode->next = nodePtr; 
            //confirmation 
            cout << "We have inserted it." << endl;
            }
        
        //error message
        if(counter < n){
            cout << "Error, that bead position does not exist..." << endl;
            return(-1);
        }    
        }
    }
    return 0;
}


/************************************
BeadList deleteNode (anywhere in the list)
************************************/
int BeadList::deleteNode(int n){
    ListNode *nodePtr; //new node pointer
    ListNode *previousNode; //points to previous node
    int counter = 0;
    //If the list is empty do nothing
    if(!head){
        cout << "Error, list is empty..." << endl;
        return(-1);
    }
    // if position is at head then delete head
    if (n == 0){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        cout << "Bead position " << n << " has been deleted..." << endl;
    }
    else {
        //Initialize nodePtr to the head of list
        nodePtr = head;
        
        //skip all the nodes whos position is not parameter n
        while(nodePtr != nullptr && counter != n){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            counter++;
        }
        
        //If nodePtr is not at end of list then delete nodePtr
        if (nodePtr && counter == n){
            previousNode->next = nodePtr->next;
            delete nodePtr;
            cout << "Bead position " << n << " has been deleted..." << endl;
        }
    }
    
    //Error message if there is no bead at specified position
    if (counter < n) {
        cout << "Error, that bead position does not exist..." << endl;
        return(-1);
    }
    if (counter == 1 && (head->next==nullptr)) {
        cout << "Error, that bead position does not exist..." << endl;
        return(-1);
    }
    return(0);
}


/************************************
BeadList display
************************************/
void BeadList::display() const{
    int counter = 0;
    ListNode *nodePtr; //traverse through list
    
    //position nodePtr at head of list
    nodePtr = head;
    
    //while nodePtr points to a node, traverse the List and print
    while(nodePtr){
        cout << "Position(" << counter << ") - " << nodePtr->bead << endl;
        nodePtr = nodePtr->next;
        counter++;
    }
}

/************************************
BeadList search
************************************/
void BeadList::search(string input){
    int counter = 0;
    int found = 0;
    ListNode *nodePtr; //traverse through list
    
    //position nodePtr at head of list
    nodePtr = head;
    
    //while nodePtr points to a node, traverse the List
    while(nodePtr){
        if(nodePtr->bead == input){
              cout << "Found at Position(" << counter << ") - " << nodePtr->bead << endl;
              found++;
        }
        nodePtr = nodePtr->next;
        counter++;
    }
    
    // If specified bead isn't found display error message
    if (found == 0){
        cout << "Error, bead not found..." << endl;
    }
        
}





