//  Abdallah Afifi
// 900225283

#include "bst.h"
#include <iostream>
#include <queue>
#include <string>



TreeNode* BST::getroot() {
    return root;
}

TreeNode* BST::insert(TreeNode* node, const City& city) {
    if (!node) {
        return new TreeNode(city);
        inserted = true;
    }
    if (city.name < node->data.name) {
        node->left = insert(node->left, city);
        inserted = true;
    }
    else if (city.name > node->data.name) {
        node->right = insert(node->right, city);
        inserted = true;
    }
    else if (city.name == node->data.name) {
        inserted = false;
    }
    // Duplicate names are not inserted.
    return node;
}

TreeNode* BST::findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* BST::remove(TreeNode* node, const std::string& cityName) {
    if (!node) {
        return nullptr;
    }

    if (cityName < node->data.name) {
        node->left = remove(node->left, cityName);
    }
    else if (cityName > node->data.name) {
        node->right = remove(node->right, cityName);
    }
    else {
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        TreeNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data.name);
    }
    return node;
}

City BST::search(TreeNode* node, const std::string& cityName) const {
    if (!node) {
        return City();  // Returns an empty city if not found
    }
    if (cityName == node->data.name) {
        return node->data;
    }
    if (cityName < node->data.name) {
        return search(node->left, cityName);
    }
    else {
        return search(node->right, cityName);
    }
}

void BST::inOrder(TreeNode* node) const {
    if (!node) {
        return;
    }
    inOrder(node->left);
    std::cout << node->data.name << " (" << node->data.latitude << ", " << node->data.longitude << ") in " << node->data.country << std::endl;
    inOrder(node->right);
}

void BST::preOrder(TreeNode* node) const {
    if (!node) {
        return;
    }
    std::cout << node->data.name << " (" << node->data.latitude << ", " << node->data.longitude << ") in " << node->data.country << std::endl;
    preOrder(node->left);
    preOrder(node->right);
}

void BST::levelOrder(TreeNode* node) const {
    if (!node) {
        return;
    }
    std::queue<TreeNode*> queue;
    queue.push(node);
    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();
        std::cout << current->data.name << " (" << current->data.latitude << ", " << current->data.longitude << ") in " << current->data.country << std::endl;
        if (current->left) {
            queue.push(current->left);
        }
        if (current->right) {
            queue.push(current->right);
        }
    }
}

void BST::destroy(TreeNode* node) {
    if (!node) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Public methods
BST::BST() : root(nullptr) {}

BST::~BST() {
    destroy(root);
}

void BST::insert(const City& city) {
    root = insert(root, city);
}

void BST::remove(const std::string& cityName) {
    root = remove(root, cityName);
}

City BST::retrieve(const std::string& cityName) const {
    return search(root, cityName);
}

void BST::inOrder() const {
    inOrder(root);
}

void BST::preOrder() const {
    preOrder(root);
}

void BST::levelOrder() const {
    levelOrder(root);
}

bool BST::isEmpty() const {
    return !root;
}


