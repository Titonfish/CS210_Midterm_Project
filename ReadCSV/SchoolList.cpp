#include <iostream>
using namespace std;

struct School
{
    string name;
    string address;
    string city;
    string state;
    string county;
    School* next;
    School(string name, string address, string city, string state, string county)
    : name(name), address(address), city(city), state(state), county(county), next(nullptr) {}

    string display() const
    {
        return name + ": " + address + ", " + city + " " + state + ", " + county;
    }
};

class SchoolList
{
    School* head;

public:
    SchoolList() : head(nullptr) {}

    void insertFirst(School* newSchool)
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

    void insertLast(School* newSchool)
    {
        newSchool->next = nullptr;
        if (head == nullptr)
        {
            head = newSchool;
        }
        else
        {
            School* temp = head;
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

        if (head->next->name == name)
        {
            School* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        School* temp = head;
        while (temp->next->name != name)
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

    School* findByName(const string& name)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        School* temp = head;
        while (temp->name != name)
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
        School* temp = head;
        while (temp != nullptr)
        {
            cout << temp->display() << endl;
            temp = temp->next;
        }
    }
};