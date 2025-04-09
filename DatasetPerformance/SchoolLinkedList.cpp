#include <iostream>
using namespace std;

struct SchoolListNode
{
    School* school;
    SchoolListNode* next;
    SchoolListNode(School* school)
    : school(school), next(nullptr) {}
};

class SchoolLinkedList
{
    SchoolListNode* head;

public:
    SchoolLinkedList() : head(nullptr) {}

    void insertFirst(SchoolListNode* newSchool)
    {
        if (head == nullptr)
        {
            newSchool->next = nullptr;
        }
        else
        {
            newSchool->next = head;
        }
        head = newSchool;
    }

    void insertLast(SchoolListNode* newSchool)
    {
        newSchool->next = nullptr;
        if (head == nullptr)
        {
            head = newSchool;
        }
        else
        {
            SchoolListNode* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newSchool;
        }
    }

    bool deleteByName(const string& name)
    {
        if (head == nullptr)
        {
            return false;
        }

        SchoolListNode* temp = head;

        if (head->school->name == name)
        {
            head = head->next;
            delete temp;
            return true;
        }

        while (temp->next != nullptr)
        {
            if (temp->next->school->name == name)
            {
                SchoolListNode* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    School* findByName(const string& name)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        SchoolListNode* temp = head;
        while (temp->school->name != name)
        {
            if (temp->next == nullptr)
            {
                return nullptr;
            }
            temp = temp->next;
        }
        return temp->school;
    }

    void display()
    {
        SchoolListNode* temp = head;
        while (temp != nullptr)
        {
            cout << temp->school->display() << endl;
            temp = temp->next;
        }
    }
};