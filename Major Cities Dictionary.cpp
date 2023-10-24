//  Abdallah Afifi
// 900225283


#include "bst.h"
#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>




int main() {
    BST tree;
    Dictionary dict;

    std::cout << "Welcome to the Major Cities Dictionary \n\n";
    std::cout << "-------------------------------------- \n\n";



    dict.generateDictionaryFromFile(tree, "List.csv");
    std::cout << "A Dictionary generated from Initial City List." << std::endl;

    dict.saveDictionaryToFile(tree, "Dictionary.csv");
    std::cout << "The Dictionary has been downloaded on your disk into (Dictionary.csv)." << std::endl;

    dict.loadDictionaryFromFile(tree, "Dictionary.csv");
    std::cout << "The Dictionary has been loaded from your disk into memory." << std::endl;


    while (true) {
        std::cout << "\n\nDictionary Options:" << std::endl;
        std::cout << "1. Search for a city" << std::endl;
        std::cout << "2. List all entries" << std::endl;
        std::cout << "3. Find distance between two cities" << std::endl;
        std::cout << "4. Save dictionary to file" << std::endl;
        std::cout << "5. Load dictionary from file" << std::endl;
        std::cout << "6. Add a city" << std::endl;
        std::cout << "7. Remove a city" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "\n\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            dict.searchCity(tree);
            break;
        case 2: {
            dict.listInOrder(tree.getroot());
            break;
        }
        case 3: {
            dict.findDistance(tree);
            break;
        }
        case 4: {
            dict.saveDictionaryToFile(tree, "Dictionary.csv");
            std::cout << "The Dictionary has been saved on your disk (Dictionary.csv)." << std::endl;
            break;
        }
        case 5: {
            dict.loadDictionaryFromFile(tree, "Dictionary.csv");
            std::cout << "The Dictionary has been loaded from your disk into memory." << std::endl;
            break;
        }
        case 6: {
            dict.addToDictionary(tree);
            break;
        }
        case 7: {
            dict.removeFromDictionary(tree);
            break;
        }
        case 8: {
            std::cout << "Exiting the program." << std::endl;
            return 0;
        }
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
