#include <iostream>
using namespace std;
#include "School.cpp"

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

        if (head->next->school->name == name)
        {
            SchoolListNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        SchoolListNode* temp = head;
        while (temp->next->school->name != name)
        {
            if (temp->next->next == nullptr)
            {
                return false;
            }
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp;

        return true;
    }

    SchoolListNode* findByName(const string& name)
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
        return temp;
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