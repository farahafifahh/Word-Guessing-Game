#include "Queue.h"
#include <string>
#include <iostream>
using  namespace std;

// *********************************************************************************************
// The constructor creates an empty Queue
// *********************************************************************************************
Queue::Queue()
{
    front = NULL;
    rear = NULL;
    numItems = 0;
}

// *********************************************************************************************
// Destructor
// *********************************************************************************************
Queue::~Queue()
{
    clear();
}

// *********************************************************************************************
// Function enqueue inserts the words item at the rear of the queue
// *********************************************************************************************
void Queue::enqueue(string item)
{
    QNode* newNode = NULL;

    // Create a new node and store the new words there
    newNode = new QNode(item);

    // Adjust front and rear if necessary
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    numItems++; // Update numItems
}

// *********************************************************************************************
// Function dequeue removes the words at the front of the queue, and copies it into item
// *********************************************************************************************
void Queue::dequeue(string& item)
{
    QNode* temp = NULL;

    if (isEmpty())
    {
        cout << "No other words left to dequeue.\n";
    }
    else
    {
        // Save the front node words in item
        item = front->words;

        // Remove the front node and delete it
        temp = front;
        front = front->next;

        // Update the numitems
        numItems--;
    }
}

// *********************************************************************************************
// Function isEmpty returns true if q is empty, else false
// *********************************************************************************************
bool Queue::isEmpty() const
{
    // To identify whether the queue is empty of not
    bool status;

    if (numItems > 0)
        status = false;
    else
        status = true;

    return status;
}

// *********************************************************************************************
// Function clear dequeues all the elements in the queue
// *********************************************************************************************
void Queue::clear()
{
    // Dummy variable for dequeue
    string words;

    // Loop to clear all the queues
    while (!isEmpty())
        dequeue(words);
}

// *********************************************************************************************
// Display the category
// *********************************************************************************************
void Queue::wordDisplay(char choice)
{
    // Use switch statement to generate the output of each choice
    switch (choice)
    {
    case '1':
        cout << "\nThis is the Animal category\n";
        cout << "[1] d_g__g\n[2] l__n\n[3] t_g__\n[4] du__\n\n";             // dugong, lion, tiger, duck
        break;
    case '2':
        cout << "\nThis is the Food category\n";
        cout << "[1] b_r__r\n[2] d__g_n_t\n[3] n____e\n[4] le___\n\n";       // burger, doughnut, noodle, lemon
        break;
    case '3':
        cout << "\nThis is the General category\n";
        cout << "[1] p_l_o_\n[2] l__p\n[3] t_b__\n[4] b____et\n\n";          // pillow, lamp, table, blanket
        break;
    default:
        break;
    }

}

// *********************************************************************************************
// Game rules
// *********************************************************************************************
void Queue::rules()
{
    // Output the rules of the game
    cout << "-------------------------------------------------\n";
    cout << "           :: GAME RULE ::\n";
    cout << "+ Please sit in 2 people in 1 group\n";
    cout << "+ Each correct word get 1 point\n";
    cout << "+ There are 5 words in each categories\n";
    cout << "+ Each player in a group must guess all 5 words\n";
    cout << "-------------------------------------------------\n";
}

// *********************************************************************************************
// Comparison and choices
// *********************************************************************************************
void compare(char choice, Queue G1, Queue G2, string group1, string group2)
{
    // Declaration
    Queue ori, ori2;
    string word1, word2, word3, word4;

    // *********************************************************************************************
    // Choice 1
    // *********************************************************************************************
    if (choice == '1')
    {
        // To enqueue the original word for animal category group 1
        ori.enqueue("dugong");
        ori.enqueue("lion");
        ori.enqueue("tiger");
        ori.enqueue("duck");
        ori.enqueue("dugong");
        ori.enqueue("lion");
        ori.enqueue("tiger");
        ori.enqueue("duck");

        // To enqueue the original word for animal category group 2
        ori2.enqueue("dugong");
        ori2.enqueue("lion");
        ori2.enqueue("tiger");
        ori2.enqueue("duck");
        ori2.enqueue("dugong");
        ori2.enqueue("lion");
        ori2.enqueue("tiger");
        ori2.enqueue("duck");


        // Declaration
        int correct = 0;

        cout << "\nAttempt of Group " << group1 << endl;
        cout << "Guess words vs Original words\n";
        cout << "--------------------\n";

        // Loop to count the correct word for group 1 in animal category
        for (int i = 0; i < 8; i++)
        {
            G1.dequeue(word1);
            ori.dequeue(word3);
            cout << word1 << "\t\t\t" << word3 << endl;
            if (word1 == word3)
            {
                correct++;      // Count the same word only
            }
        }

        // Declaration
        int correct2 = 0;
        cout << "\nAttempt of Group " << group2 << endl;
        cout << "Guess words vs Original words\n";
        cout << "--------------------\n";

        // Loop to count the correct word for group 2 in animal category
        for (int j = 0; j < 8; j++)
        {
            G2.dequeue(word2);
            ori2.dequeue(word4);
            cout << word2 << "\t\t\t" << word4 << endl;
            if (word2 == word4)
            {
                correct2++;      // Count the same word only
            }
        }
        // Output the result
        cout << "\nThe details as below\n";
        cout << "Group " << group1 << ": " << correct << "/" << 8 << endl;
        cout << "Group " << group2 << ": " << correct2 << "/" << 8 << endl;

        // Compare which one group is the highest and winner
        if (correct > correct2)
            cout << "The winner is group " << group1 << ". Congratulations!!!" << endl;
        else if (correct2 > correct)
            cout << "The winner is group " << group2 << ". Congratulations!!!" << endl;
        else
            cout << "Group " << group1 << " and Group " << group2 << " Match is Draw.\n";
        cout << "-------------------------------------------------\n";
        cout << endl;

    }
    // *********************************************************************************************
    // Choice 2
    // *********************************************************************************************
    else if (choice == '2')
    {
        // To enqueue the original word for food category group 1
        ori.enqueue("burger");
        ori.enqueue("doughnut");
        ori.enqueue("noodle");
        ori.enqueue("lemon");
        ori.enqueue("burger");
        ori.enqueue("doughnut");
        ori.enqueue("noodle");
        ori.enqueue("lemon");

        // To enqueue the original word for food category group 2
        ori2.enqueue("burger");
        ori2.enqueue("doughnut");
        ori2.enqueue("noodle");
        ori2.enqueue("lemon");
        ori2.enqueue("burger");
        ori2.enqueue("doughnut");
        ori2.enqueue("noodle");
        ori2.enqueue("lemon");

        // Declaration
        int correct = 0;
        cout << "\nAttempt of Group " << group1 << endl;
        cout << "Guess words vs Original words\n";
        cout << "--------------------\n";

        // Loop to count the correct word for group 1 in food category
        for (int i = 0; i < 8; i++)
        {
            G1.dequeue(word1);
            ori.dequeue(word3);
            cout << word1 << "\t\t\t" << word3 << endl;
            if (word1 == word3)
            {
                correct++;          // Count the same word only
            }
        }

        // Declaration
        int correct2 = 0;
        cout << "\nAttempt of Group " << group2 << endl;
        cout << "Guess words vs Original words\n";

        // Loop to count the correct word for group 2 in food category
        cout << "--------------------\n";
        for (int j = 0; j < 8; j++)
        {
            G2.dequeue(word2);
            ori2.dequeue(word4);
            cout << word2 << "\t\t\t" << word4 << endl;
            if (word2 == word4)
            {
                correct2++;         // Count the same word only
            }
        }
        // Output the result
        cout << "\nThe details as below\n";
        cout << "Group " << group1 << ": " << correct << "/" << 8 << endl;
        cout << "Group " << group2 << ": " << correct2 << "/" << 8 << endl;

        // Compare which one group is the highest and winner
        if (correct > correct2)
            cout << "The winner is group " << group1 << ". Congratulations!!!" << endl;
        else if (correct2 > correct)
            cout << "The winner is group " << group2 << ". Congratulations!!!" << endl;
        else
            cout << "Group " << group1 << " and Group " << group2 << " Match is Draw.\n";
        cout << "-------------------------------------------------\n";
        cout << endl;

    }
    // *********************************************************************************************
    // Choice 3
    // *********************************************************************************************
    else if (choice == '3')
    {
        // To enqueue the original word for general category group 1
        ori.enqueue("pillow");
        ori.enqueue("lamp");
        ori.enqueue("table");
        ori.enqueue("blanket");
        ori.enqueue("pillow");
        ori.enqueue("lamp");
        ori.enqueue("table");
        ori.enqueue("blanket");

        // To enqueue the original word for general category group 2
        ori2.enqueue("pillow");
        ori2.enqueue("lamp");
        ori2.enqueue("table");
        ori2.enqueue("blanket");
        ori2.enqueue("pillow");
        ori2.enqueue("lamp");
        ori2.enqueue("table");
        ori2.enqueue("blanket");

        // Declaration
        int correct = 0;
        cout << "\nAttempt of Group " << group1 << endl;
        cout << "Guess words vs Original words\n";
        cout << "--------------------\n";

        // Loop to count the correct word for group 1 in general category
        for (int i = 0; i < 8; i++)
        {
            G1.dequeue(word1);
            ori.dequeue(word3);
            cout << word1 << "\t\t\t" << word3 << endl;
            if (word1 == word3)
            {
                correct++;          // Count the same word only
            }
        }

        // Declaration
        int correct2 = 0;
        cout << "\nAttempt of Group " << group2 << endl;
        cout << "Guess words vs Original words\n";
        cout << "--------------------\n";

        // Loop to count the correct word for group 2 in general category
        for (int j = 0; j < 8; j++)
        {
            G2.dequeue(word2);
            ori2.dequeue(word4);
            cout << word2 << "\t\t\t" << word4 << endl;
            if (word2 == word4)
            {
                correct2++;         // Count the same word only
            }
        }
        // Output the result
        cout << "\nThe details as below\n";
        cout << "Group " << group1 << ": " << correct << "/" << 8 << endl;
        cout << "Group " << group2 << ": " << correct2 << "/" << 8 << endl;

        // Compare which one group is the highest and winner
        if (correct > correct2)
            cout << "The winner is group " << group1 << ". Congratulations!!!" << endl;
        else if (correct2 > correct)
            cout << "The winner is group " << group2 << ". Congratulations!!!" << endl;
        else
            cout << "Group " << group1 << " and Group " << group2 << " Match is Draw.\n";
        cout << "-------------------------------------------------\n";
        cout << endl;
    }
}
