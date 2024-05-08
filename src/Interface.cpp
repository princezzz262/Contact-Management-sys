/*
 * Interface.cpp
 *
 *  Created on: 8 May 2024
 *      Author: mensa
 */

#include <iostream>
#include "Interface.h"
#include "Contacts.h" // Include Contacts.h to use the Contact struct

using namespace std;

// Display user interface
void Interface() {
    // Display visual information
    std::cout << " \n\n\n  ****CONTACT MANAGEMENT SYSTEM***** \n ________________________________________" << std::endl;
    std::cout << "\n>>> choose an operation to continue: \nNew: (n) \nRetrieve: (r) \nDelete All: (D) \nQuit: (q)" << std::endl;
    char choice;
    // Collect user choice or decision
    std::cout << ">...Enter Here: ";
    std::cin >> choice;
    std::cin.ignore();

    Contact contact;

    // Declare vector outside the switch statement
    std::vector<Contact> contacts;

    // Calling functions based on user's choice
    switch (choice) {
        case 'n':
            std::cout << "New domain selected" << std::endl;
            // Call the newContact function to create a new contact
            newContact(contact);
            Interface();
            break;
        case 'r':
            std::cout << "Retrieving saved Contacts\n---------------------------- \n " << std::endl;
            // Retrieve contacts from file
            contacts = readContactsFromFile("contacts.txt");
            // Display the retrieved contacts
            for (const auto& contact : contacts) {
                std::cout << "Name: " << contact.name << std::endl;
                std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
                std::cout << "Email: " << contact.cEmail << std::endl;
                std::cout << "----------------------" << std::endl;
            }
            Interface();
            break;
        case 'D':
            std::cout << "Delete domain selected" << std::endl;
            // Add functionality to delete a contact
            break;
        case 'q':
        	return ;
        	break;
        default:
            std::cout << "\n>...You are required to enter either n, f, or r to proceed" << std::endl;
            Interface();
    }
}
