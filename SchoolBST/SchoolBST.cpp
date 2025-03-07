#include <iostream>

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
        return findNode((name < node->name) ? node->left : node->right, name);
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
        if (node->left != nullptr && node->left->name == name)
        {
            delete node->left;
            node->left = nullptr;
            return;
        }
        if (node->right != nullptr && node->right->name == name)
        {
            delete node->right;
            node->right = nullptr;
            return;
        }

        deleteNode((name < node->name) ? node->left : node->right, name);
    }
    void preOrderTraversalHelper(School* node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->name << " ";
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
        std::cout << node->name << " ";
    }
    void inOrderTraversalHelper(School* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversalHelper(node->left);
        std::cout << node->name << " ";
        inOrderTraversalHelper(node->right);
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