#include "Queue.h"
#include <iostream>
#include <string>
using  namespace std;

// *********************************************************************************************
// Function main menu
// *********************************************************************************************
void firstmenu()
{
    // Create a main menu
    system("cls");
    cout << "\t ---------------------------------------\n";
    cout << "\t ----WELCOME TO WORD GUESSING GAME------ \n";
    cout << "\t 1. Read me\n";
    cout << "\t 2. Play a game for Group 1\n";
    cout << "\t 3. Play a game for Group 2\n";
    cout << "\t 4. Result\n";
    cout << "\t 5. Exit\n";
    cout << "\t Please enter your choice (1-5)\n";
}

// *********************************************************************************************
// Function of Menu
// *********************************************************************************************
char menu(string& group1, string& group2)
{
    // Declaration
    char option;

    // *********************************************************************************************
    // Display the welcoming program
    // *********************************************************************************************
    cout << "-------------------------------------------------\n";
    cout << "===== Hello! Welcome to Word Guessing Game ======\n";
    cout << "Select categories:\n";
    cout << "  [1]: Animal, [2]: Food, [3]: General\n";
    cout << "Choose: ";
    cin >> option;

    // Input validation of option
    while (option != '1' && option != '2' && option != '3')
    {
        cout << "Invalid character, please choose carefully\n";
        cin >> option;
    }

    // *********************************************************************************************
    // Choosing a group name
    // *********************************************************************************************
    cout << "Enter Group 1 name : ";
    cin.ignore();
    getline(cin, group1);
    cout << "Enter Group 2 name : ";
    getline(cin, group2);
    cout << "-------------------------------------------------\n";
    return option;
}

// *********************************************************************************************
// Function main
// *********************************************************************************************
int main()
{
    // Declaration
    Queue G1, G2, ori, ori2;
    char options, choice;
    string word1, word2, word3, word4, group1, group2;

    // Loop to input validation
    do
    {
        // Function og main menu
        firstmenu();
        cin >> choice;

        // Loop to input validation of choices
        while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5')
        {
            cout << "\tInvalid Choice\n";
            cout << "\tPlease Re-Enter : ";
            cin >> choice;
        }

        // *********************************************************************************************
        // Choice 1
        // *********************************************************************************************
        if (choice == '1')
        {
            // Output the rules by calling the function rule in class
            G1.rules();
            system("pause");
        }

        // *********************************************************************************************
        // Choice 2
        // *********************************************************************************************
        else if (choice == '2')
        {
            // Display the words question
            options = menu(group1, group2);
            G1.wordDisplay(options);

            // *********************************************************************************************
            // Group 1 turn
            // *********************************************************************************************
            cout << "-------------------------------------------------\n";
            cout << "Group " << group1 << "'s turn\n";
            cout << "-------------------------------------------------\n";

            // Loop to prompt players to enter the words
            for (int i = 0; i < 2; i++)
            {
                cout << "\nPlayer " << i + 1 << " Group " << group1 << " guess is: " << endl;
                for (int i = 0; i < 4; i++)
                {
                    cout << "Word [" << (i + 1) << "]: ";
                    cin >> word1;
                    G1.enqueue(word1);
                }
            }
            cout << endl;
            system("pause");

        }
        // *********************************************************************************************
        // Choice 3
        // *********************************************************************************************
        else if (choice == '3')
        {
            // Display the word question
            G2.wordDisplay(options);

            // *********************************************************************************************
            // Group 2 turn
            // *********************************************************************************************
            cout << "-------------------------------------------------\n";
            cout << "Group " << group2 << "'s turn\n";
            cout << "-------------------------------------------------\n";

            // Loop to prompt players to enter the words
            for (int i = 0; i < 2; i++)
            {
                cout << "\nPlayer " << i + 1 << " Group " << group2 << " guess is: " << endl;
                for (int i = 0; i < 4; i++)
                {
                    cout << "Word [" << (i + 1) << "]: ";
                    cin >> word2;
                    G2.enqueue(word2);
                }
            }
            system("pause");
        }
        // *********************************************************************************************
        // Choice 4
        // *********************************************************************************************
        else if (choice == '4')
        {
            // *********************************************************************************************
            // Dequeue the names and display them.
            // *********************************************************************************************
            cout << "-------------------------------------------------\n";
            cout << "Final Result\n";
            cout << "-------------------------------------------------\n";

            // Output the comparison
            compare(options, G1, G2, group1, group2);
            cout << endl;
            system("pause");
        }
        else if (choice == '5')
        {
            G1.clear();
            G2.clear();
            break;
        }
        else
        {
            cout << "Wrong choice, try again\n\n";
        }

    } while (choice != '5');

    cout << "-------------------------------------------------";
    cout << "\n\t\tEnd of Program\n";
    cout << "-------------------------------------------------\n";

    return 0;
}