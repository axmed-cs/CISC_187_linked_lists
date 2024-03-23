/******************************************************************************

Ahmed Abdullahi

Chapter 18 programming assignment - Linked Lists

November 2023

This is the specification file for the BeadList Class

*******************************************************************************/
#ifndef BEADLIST_H
#define BEADLIST_H


class BeadList{
    private: 
        // structure for the list
        struct ListNode{
            std::string bead;
            struct ListNode *next;
        };
        
        struct ListNode *head;  // list head pointer
        
        public: 
        //Default contructor
        BeadList();
        
        // destructor
        ~BeadList();
        
        //Linked List operations
        void append(std::string);
        int insert(std::string, int);
        int deleteNode(int);
        void display() const;
        void search(std::string);
};
#endif