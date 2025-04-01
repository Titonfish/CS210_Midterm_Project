//
// Created by Charlie P on 4/1/2025.
//

#include <iostream>
#include <vector>
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
    vector<vector<School*>> schools;
    int hashFunction(string key, int tableSize)
    {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % tableSize;
    }
public:
    SchoolHashTable()
    {
        schools = vector<vector<School*>>();
        schools.resize(23);
    }
    void insert(School* school)
    {
        int hashValue = hashFunction(school->name, schools.size());
        schools[hashValue].push_back(school);
    }
    void deleteByName(const string& name)
    {
        int hashValue = hashFunction(name, schools.size());
        for (int i=0; i<schools[hashValue].size(); i++)
        {
            if (schools[hashValue][i]->name == name)
            {
                schools[hashValue].erase(schools[hashValue].begin() + i);
            }
        }
    }
    School* findByName(const string& name)
    {
        int hashValue = hashFunction(name, schools.size());
        for (auto& i : schools[hashValue])
        {
            if (i->name == name)
            {
                return i;
            }
        }
        return nullptr;
    }
    void display()
    {
        for (int i=0;i<schools.size();i++)
        {
            cout << i << ": ";
            for (auto& curSchool : schools[i])
            {
                cout << curSchool->name;
                if (curSchool != schools[i][schools[i].size() - 1])
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }
};