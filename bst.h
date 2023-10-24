//  Abdallah Afifi
// 900225283

#ifndef BST_H
#define BST_H

#include <string>


struct City {
    std::string name;
    std::string latitude;
    std::string longitude;
    std::string country;

    City(std::string n = "", std::string lat = "", std::string lon = "", std::string c = "")
        : name(n), latitude(lat), longitude(lon), country(c) {}
};

struct TreeNode {
    City data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const City& city) : data(city), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    // Private helper functions

    TreeNode* insert(TreeNode* node, const City& city);
    TreeNode* remove(TreeNode* node, const std::string& cityName);
    City search(TreeNode* node, const std::string& cityName) const;
    void inOrder(TreeNode* node) const;
    void preOrder(TreeNode* node) const;
    void levelOrder(TreeNode* node) const;
    void destroy(TreeNode* node);
    TreeNode* findMin(TreeNode* node);
    TreeNode* findMax(TreeNode* node);

public:
    BST();
    ~BST();
    TreeNode* getroot();
    void insert(const City& city);
    void remove(const std::string& cityName);
    City retrieve(const std::string& cityName) const;
    void inOrder() const;
    void preOrder() const;
    void levelOrder() const;
    bool isEmpty() const;
    bool inserted = false;

   
};

#endif
