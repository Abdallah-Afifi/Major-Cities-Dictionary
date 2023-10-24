//  Abdallah Afifi
// 900225283

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "bst.h"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


const double PI = 3.14159265358979323846;

class Dictionary {

public:

    double degreesToRadians(double degrees);
    double haversineDistance(const City& city1, const City& city2);
    void saveToFilePreOrder(TreeNode* node, std::ofstream& file);
    void listInOrder(TreeNode* node);
    void saveDictionaryToFile(BST& tree, const std::string& filename);
    void loadDictionaryFromFile(BST& tree, const std::string& filename);
    void addToDictionary(BST& tree);
    void removeFromDictionary(BST& tree);
    void generateDictionaryFromFile(BST& tree, const std::string& filename);
    void searchCity(BST& tree);
    void findDistance(BST& tree);


    













};
#endif 




