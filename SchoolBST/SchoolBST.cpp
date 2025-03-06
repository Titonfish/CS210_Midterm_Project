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