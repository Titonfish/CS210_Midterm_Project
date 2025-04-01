#include <iostream>
#include <vector>
#include "CSVReader.cpp"
#include "SchoolHashTable.cpp"
using namespace std;

int main()
{
    SchoolHashTable schoolTable;

    cout << "Searching an empty table: " << endl;
    School* schoolSearch = schoolTable.findByName("Evergreen Montessori");
    cout << "- " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    const vector<vector<string>> data = CSVReader::readCSV("C:/Users/Charlie P/Documents/# Senior Files/Advanced Data Structures and Algorithms/MidtermRepo/CS210_Midterm_Project/HashTables/schools.csv");

    for (int i = 1; i < data.size(); i++)
    {
        const vector<string>& schoolData = data[i];

        School* newSchool = new School(schoolData[0], schoolData[1], schoolData[2], schoolData[3], schoolData[4]);

        schoolTable.insert(newSchool);
    }

    cout << endl << endl;

    schoolTable.display();

    cout << endl << endl;

    cout << "Searching for an existing school: " << endl;
    schoolSearch = schoolTable.findByName("Willow Creek Middle School");
    cout << "- " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    cout << "Searching for a non-existent school: " << endl;
    schoolSearch = schoolTable.findByName("Broken Limb High");
    cout << "- " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    cout << "Deleting an existing school: " << endl;
    bool schoolDelete = schoolTable.deleteByName("Redwood Elementary");
    cout << "- " << (boolalpha) << schoolDelete << endl;

    cout << "Searching for a deleted school: " << endl;
    schoolSearch = schoolTable.findByName("Redwood Elementary");
    cout << "- " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    cout << "Deleting a non-existent school: " << endl;
    schoolDelete = schoolTable.deleteByName("Turnpike University");
    cout << "- " << (boolalpha) << schoolDelete << endl;


}