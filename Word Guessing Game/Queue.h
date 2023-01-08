#pragma once
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
using namespace std;

// *********************************************************************************************
// Declaration of class Node
// *********************************************************************************************
class QNode
{
public:
    // Value in a node
    string words;

    // Pointer to the next node
    QNode* next;

    // Constructor for creating a new node in qeueu
    QNode(string nodeValue)
    {
        words = nodeValue;
        next = NULL;
    }
};

// *********************************************************************************************
// Declaration of class queue
// *********************************************************************************************
class Queue
{
private:
    // The front of the queue
    QNode* front;

    // The rear of the queue
    QNode* rear;

    // Number of items in the queue
    int numItems;

public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    // Queue operations
    void enqueue(string);       // Insert into queue
    void dequeue(string&);      // Remove from queue and display/compare
    bool isEmpty() const;       // Identify whether the queue is empty
    void clear();               // Destroy queues
    void wordDisplay(char);     // Display the questions of the words
    void rules();               // Rule of the game

    // Friend function to compare answer of group 1 and group 2
    friend void compare(char, Queue, Queue, string, string);
};


#endif
