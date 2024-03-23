/******************************************************************************

Ahmed Abdullahi

Chapter 18 programming assignment - Linked Lists

November 2023

*******************************************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include "BeadList.h"
using namespace std;


// main
int main()
{
    //holds user input
    string inputString;   
    int inputNumber;
    
    //Beadlist object initialization
    BeadList list;
                      
    // while loop
    char option = 0;
  while (option != 6)
  {
    //Display menu
    cout <<  endl << endl << "********************************" << endl;
    cout << "Bead Necklace - Display Menu" << endl;
    cout << "********************************" << endl;
    cout << "1.  Append a bead" << endl;
    cout << "2.  Insert a bead" << endl;
    cout << "3.  Delete a bead" << endl;
    cout << "4.  Print all beads" << endl;
    cout << "5.  Search for a bead" << endl;
    cout << "6.  Exit" << endl << endl;
    
    //input option
    cout << "Please choose an option from the numbers above or enter 6 to exit: ";
    cin >> option;
    cout << endl;
    
    // switch case from user option
    switch(option)
    {
    case '1': 
        // case 1 will append a node to the List
    
        cout << "Enter one of the following bead colors that you would like to add to the necklace:" << endl;
        cout << "(turquoise, coral, gold, or copper)" << endl << endl;
        
        //get user input for bead color
        cin.ignore();
        getline(cin, inputString);
        
        //convert user input to lowercase
        std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        
        //validate user input
        while (!(inputString=="turquoise"||inputString=="coral"||inputString=="gold"||inputString=="copper")){  
            cout << "Error, Please enter a valid bead color (turquoise, coral, gold, or copper): " << endl;
            getline(cin, inputString);
            std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        }
        
        // append the user input
        list.append(inputString);
        
        //confirmation message
        cout << "Good news, " << inputString << " was added to the necklace!";
        
        break;
    
    case '2':   
        // case 2 will insert a node to the List

        cout << "Enter one of the following bead colors that you would like to add to the necklace:" << endl;
        cout << "(turquoise, coral, gold, or copper)" << endl << endl;
        
        //get user input for bead color
        cin.ignore();
        getline(cin, inputString);
        //convert user input to lowercase
        std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        
        //validate user input
        while (!(inputString=="turquoise"||inputString=="coral"||inputString=="gold"||inputString=="copper")){  
            cout << "Error, Please enter a valid bead color (turquoise, coral, gold, or copper): " << endl;
            getline(cin, inputString);
            std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        }
        
        //get user input for node position
        cout << "Enter a position you would like me to insert it in: " << endl;
        cin >> inputNumber;
        cin.ignore();
        
        //validate user input
        while(inputNumber < 0){
            cout << "Error, Please enter a number greater than 0..." << endl;
            cin >>inputNumber;
            cin.ignore();
        }
        
        // insert the user input at the position
        list.insert(inputString, inputNumber);
        break;
    
    case '3':    
        //case 3 will delete the node that the user specifies    
        
        // get bead position
        cout << endl << "Please enter the position of the bead you would like to remove." << endl;
        cin >> inputNumber;
        cin.ignore();
        cout << endl;
        
        //validate the user input
        while(inputNumber < 0){
            cout << "Error, Please enter a number greater than 0..." << endl;
            cin >>inputNumber;
            cin.ignore();
        }
        
        //call the function to delete the node
        list.deleteNode(inputNumber);
        
        break;
    
    case '4':    
        //case 4 will display all beads and their positions
        
        //call the function to display all nodes/positions
        list.display();
        break;
        
    case '5':    
        //case 5 will search for specified beads
        
        //get user input for bead color
        cout << "Enter color to search for: " << endl;
        cin.ignore();
        getline(cin, inputString);
        std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        
        //validate user input
        while (!(inputString=="turquoise"||inputString=="coral"||inputString=="gold"||inputString=="copper")){  
            cout << "Error, Please enter a valid bead color (turquoise, coral, gold, or copper): " << endl;
            getline(cin, inputString);
            std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        }
        // search for the user input
        list.search(inputString);
        
        break;
           
    case '6':
        // case 3 will close program
        cout << "Bye, we hope you enjoy your new necklace." << endl;
        exit(0);
       
        break;
       
    default:  
    
        // validation for menu option
        cout << "That is not a valid menu option." << endl;
        
        break;
    
    }//end switch
 
    
  }//end the while loop
 
    return 0;
}//end main

