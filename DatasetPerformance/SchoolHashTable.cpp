//
// Created by Charlie P on 4/1/2025.
//

#include <iostream>
#include <vector>
using namespace std;

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
        schools.resize(54799);
    }
    void insert(School* school)
    {
        int hashValue = hashFunction(school->name, schools.size());
        schools[hashValue].push_back(school);
    }
    bool deleteByName(const string& name)
    {
        int hashValue = hashFunction(name, schools.size());
        for (int i=0; i<schools[hashValue].size(); i++)
        {
            if (schools[hashValue][i]->name == name)
            {
                schools[hashValue].erase(schools[hashValue].begin() + i);
                return true;
            }
        }

        return false;
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