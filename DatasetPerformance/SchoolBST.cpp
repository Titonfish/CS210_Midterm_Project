#include <iostream>
using namespace std;
#include "School.cpp"

struct SchoolBSTNode
{
    School* school;
    SchoolBSTNode* left;
    SchoolBSTNode* right;
    SchoolBSTNode(School* school)
    : school(school), left(nullptr), right(nullptr) {}
};

class SchoolBST
{
private:
    SchoolBSTNode* root;
    SchoolBSTNode* insertNode(SchoolBSTNode* node, SchoolBSTNode* school)
    {
        if (node == nullptr)
        {
            return school;
        }
        if (school->school->name < node->school->name)
        {
            node->left = insertNode(node->left, school);
        }
        else
        {
            node->right = insertNode(node->right, school);
        }
        return node;
    }
    SchoolBSTNode* findNode(SchoolBSTNode* node, string name)
    {
        if (node == nullptr || node->school->name == name)
        {
            return node;
        }
        return findNode((name < node->school->name) ? node->left : node->right, name);
    }
    void deleteTree(SchoolBSTNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    void deleteNode(SchoolBSTNode* node, string name)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->left != nullptr && node->left->school->name == name)
        {
            delete node->left;
            node->left = nullptr;
            return;
        }
        if (node->right != nullptr && node->right->school->name == name)
        {
            delete node->right;
            node->right = nullptr;
            return;
        }

        deleteNode((name < node->school->name) ? node->left : node->right, name);
    }
    void preOrderTraversalHelper(SchoolBSTNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->school->name << " ";
        preOrderTraversalHelper(node->left);
        preOrderTraversalHelper(node->right);
    }
    void postOrderTraversalHelper(SchoolBSTNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraversalHelper(node->left);
        postOrderTraversalHelper(node->right);
        std::cout << node->school->name << " ";
    }
    void inOrderTraversalHelper(SchoolBSTNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversalHelper(node->left);
        std::cout << node->school->name << " ";
        inOrderTraversalHelper(node->right);
    }
public:
    SchoolBST() : root(nullptr) {}
    ~SchoolBST()
    {
        deleteTree(root);
    }
    void insert(SchoolBSTNode* school)
    {
        root = insertNode(root, school);
    }
    SchoolBSTNode* findByName(string name)
    {
        return findNode(root, name);
    }
    void deleteByName(string name)
    {
        deleteNode(root, name);
    }
    void displayPreOrder()
    {
        if (root == nullptr)
        {
            std::cout << "Empty Tree" << std::endl;
            return;
        }
        preOrderTraversalHelper(root);
        std::cout << std::endl;
    }
    void displayPostOrder()
    {
        if (root == nullptr)
        {
            std::cout << "Empty Tree" << std::endl;
            return;
        }
        postOrderTraversalHelper(root);
        std::cout << std::endl;
    }
    void displayInOrder()
    {
        if (root == nullptr)
        {
            std::cout << "Empty Tree" << std::endl;
            return;
        }

        inOrderTraversalHelper(root);
        std::cout << std::endl;
    }
};