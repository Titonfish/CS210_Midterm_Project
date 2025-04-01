#include <iostream>
#include <vector>
#include "CSVReader.cpp"
#include "SchoolHashTable.cpp"
using namespace std;

int main()
{
    SchoolHashTable schoolTable;

    const vector<vector<string>> data = CSVReader::readCSV("C:/Users/Charlie P/Documents/# Senior Files/Advanced Data Structures and Algorithms/MidtermRepo/CS210_Midterm_Project/HashTables/schools.csv");

    for (int i = 1; i < data.size(); i++)
    {
        const vector<string>& schoolData = data[i];

        School* newSchool = new School(schoolData[0], schoolData[1], schoolData[2], schoolData[3], schoolData[4]);

        schoolTable.insert(newSchool);
    }

    schoolTable.display();
}