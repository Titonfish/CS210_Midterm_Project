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
        return name + " " + address + " " + city + " " + state + " " + county;
    }
};

template<typename T>
class SchoolList
{
    School* head;

public:
    SchoolList() : head(nullptr) {}

    void insertFirst(School* newSchool)
    {
        newSchool->next = head;
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

    void display()
    {
        School* temp = head;
        while (temp != nullptr)
        {
            cout << temp->display() << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};