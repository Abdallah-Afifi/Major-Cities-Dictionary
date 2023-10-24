//  Abdallah Afifi
// 900225283

#include "dictionary.h"
#include "bst.h"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

double Dictionary::degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

double Dictionary::haversineDistance(const City& city1, const City& city2) {
    double lat1 = degreesToRadians(std::stod(city1.latitude));
    double lon1 = degreesToRadians(std::stod(city1.longitude));
    double lat2 = degreesToRadians(std::stod(city2.latitude));
    double lon2 = degreesToRadians(std::stod(city2.longitude));

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = pow(sin(dlat / 2.0), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double R = 6371.0;  // Earth radius in kilometers

    return R * c;
}

// Saves the tree in-order to the given file.
void Dictionary::saveToFilePreOrder(TreeNode* node, std::ofstream& file) {
    if (node) {
        file << node->data.name << ","
            << node->data.latitude << ","
            << node->data.longitude << ","
            << node->data.country << "\n";
        saveToFilePreOrder(node->left, file);
        saveToFilePreOrder(node->right, file);
    }
}

void Dictionary::listInOrder(TreeNode* node) {
    if (node) {
        listInOrder(node->left);
        std::cout << node->data.name << ","
            << node->data.latitude << ","
            << node->data.longitude << ","
            << node->data.country << "\n";
        listInOrder(node->right);
    }
}

void Dictionary::saveDictionaryToFile(BST& tree, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        saveToFilePreOrder(tree.getroot(), file);
    }
    file.close();
}

void Dictionary::loadDictionaryFromFile(BST& tree, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {  // Read lines from the file
        std::istringstream iss(line);
        City city;
        getline(iss, city.name, ',');
        getline(iss, city.latitude, ',');
        getline(iss, city.longitude, ',');
        getline(iss, city.country);

        tree.insert(city);
    }
    file.close();
}

void Dictionary::addToDictionary(BST& tree) {
    City city;
    std::cout << "Enter the city info that you wish to add: \n";
    getline(std::cin, city.name);
    getline(std::cin, city.latitude);
    getline(std::cin, city.longitude);
    getline(std::cin, city.country);
    tree.insert(city);
    if (tree.inserted) {
        saveDictionaryToFile(tree, "Dictionary.csv");
        loadDictionaryFromFile(tree, "Dictionary.csv");
        std::cout << "The city is added to the dictionary, and the updated dictionary has been saved. \n";
    }
    else
        std::cout << "The city is already in the Dictionary \n";
}

void Dictionary::removeFromDictionary(BST& tree) {
    City city;
    std::cout << "Enter the city info that you wish to remove: \n";
    getline(std::cin, city.name);
    tree.remove(city.name);
    saveDictionaryToFile(tree, "Dictionary.csv");
    loadDictionaryFromFile(tree, "Dictionary.csv");
    std::cout << "The city is removed from the dictionary, and the updated dictionary has been saved. \n";

}

void Dictionary::generateDictionaryFromFile(BST& tree, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {  // Read lines from the file
        std::istringstream iss(line);
        City city;
        getline(iss, city.name, ',');
        getline(iss, city.latitude, ',');
        getline(iss, city.longitude, ',');
        getline(iss, city.country);

        tree.insert(city);
    }
    file.close();
}

void Dictionary::searchCity(BST& tree) {
    std::string cityName;
    std::cout << "Enter a city name to search: ";
    getline(std::cin, cityName);

    City result = tree.retrieve(cityName);
    if (!result.name.empty()) {
        std::cout << "Found " << result.name << " in " << result.country << " with coordinates ("
            << result.latitude << ", " << result.longitude << ").\n";
    }
    else {
        std::cout << cityName << " not found.\n";
    }
}

void Dictionary::findDistance(BST& tree) {

    std::string firstName, secondName;
    std::cout << "Enter the first city for distance calculation: ";
    getline(std::cin, firstName);
    std::cout << "Enter the second city for distance calculation: ";
    getline(std::cin, secondName);

    City firstCity = tree.retrieve(firstName);
    City secondCity = tree.retrieve(secondName);

    if (!firstCity.name.empty() && !secondCity.name.empty()) {
        double distance = haversineDistance(firstCity, secondCity);
        std::cout << "The distance between " << firstCity.name << " and " << secondCity.name << " is " << distance << " km.\n";
    }
    else {
        std::cout << "One or both cities not found.\n";
    }
}