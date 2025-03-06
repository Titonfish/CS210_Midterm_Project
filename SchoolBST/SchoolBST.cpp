#include <iostream>
#include <queue>
using namespace std;

struct School
{
    string name;
    string address;
    string city;
    string state;
    string county;
    School* left;
    School* right;
    School(string name, string address, string city, string state, string county)
    : name(name), address(address), city(city), state(state), county(county), left(nullptr), right(nullptr) {}

    string display() const
    {
        return name + ": " + address + ", " + city + " " + state + ", " + county;
    }
};

class SchoolBST
{
private:
    School* root;
    School* insertNode(School* node, School* school)
    {
        if (node == nullptr)
        {
            return school;
        }
        if (school->name < node->name)
        {
            node->left = insertNode(node->left, school);
        }
        else
        {
            node->right = insertNode(node->right, school);
        }
        return node;
    }
    School* findNode(School* node, string name)
    {
        if (node == nullptr || node->name == name)
        {
            return node;
        }
        return (name < node->name) ? findNode(node->left, name) : findNode(node->right, name);
    }
    void deleteTree(School* node)
    {
        if (node == nullptr)
        {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    void deleteNode(School* node, string name)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->name == name)
        {
            delete(node);
            return;
        }
        (name < node->name) ? deleteNode(node->left, name) : deleteNode(node->right, name);
    }
    void preOrderTraversalHelper(School* node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->name[0] << node->name[1] << " ";
        preOrderTraversalHelper(node->left);
        preOrderTraversalHelper(node->right);
    }
    void postOrderTraversalHelper(School* node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraversalHelper(node->left);
        postOrderTraversalHelper(node->right);
        std::cout << node->name[0] << node->name[1] << " ";
    }
public:
    SchoolBST() : root(nullptr) {}
    ~SchoolBST()
    {
        deleteTree(root);
    }
    void insert(School* school)
    {
        root = insertNode(root, school);
    }
    School* findByName(string name)
    {
        return findNode(root, name);
    }
    void deleteByName(string name)
    {
        deleteNode(root, name);
    }
    void preOrderTraversal()
    {
        if (root == nullptr)
        {
            std::cout << "Empty Tree" << std::endl;
            return;
        }
        preOrderTraversalHelper(root);
        std::cout << std::endl;
    }
    void postOrderTraversal()
    {
        if (root == nullptr)
        {
            std::cout << "Empty Tree" << std::endl;
            return;
        }
        postOrderTraversalHelper(root);
        std::cout << std::endl;
    }
};