//
// Created by Charlie P on 4/1/2025.
//

#include <iostream>
#include <unordered_map>
using namespace std;

struct School
{
    string name;
    string address;
    string city;
    string state;
    string county;
    School(string name, string address, string city, string state, string county)
    : name(name), address(address), city(city), state(state), county(county) {}

    string display() const
    {
        return name + ": " + address + ", " + city + " " + state + ", " + county;
    }
};

class SchoolHashTable
{
private:
    unordered_map<int, School> schools;
public:
    SchoolHashTable();
    ~SchoolHashTable();

    void insert(School* school);
    void deleteByName(string name);
    School findByName(string name);
    void display();
};