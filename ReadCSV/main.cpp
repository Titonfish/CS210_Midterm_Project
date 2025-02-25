#include <iostream>
#include "SchoolList.cpp"
#include "CSVReader.cpp"
using namespace std;

void findAndDisplay(SchoolList schoolList, const string& schoolName)
{
    const School* temp = schoolList.findByName(schoolName);
    if (temp == nullptr)
    {
        cout << "nullptr" << endl;
        return;
    }
    cout << temp->display() << endl;
}

int main()
{
    SchoolList schools;

    vector<vector<string>> data = CSVReader::readCSV("C:/Users/Charlie P/Documents/# Senior Files/Advanced Data Structures and Algorithms/MidtermRepo/CS210_Midterm_Project/ReadCSV/schools.csv");

    for (int i = 1; i < data.size(); i++)
    {
        vector<string> schoolData = data[i];

        schools.insertFirst(new School(schoolData[0], schoolData[1], schoolData[2], schoolData[3], schoolData[4]));
    }

    schools.display();

    cout << endl;

    cout << "Searching for an existing school: ";
    findAndDisplay(schools, "Eastwood Elementary");
    cout << "Searching for a non-existent school: ";
    findAndDisplay(schools, "Western High");

    cout << "Deleting an existing school: " << schools.deleteByName("Magnolia Elementary") << endl;
    cout << "Deleting a non-existent school: " << schools.deleteByName("Serendipity Middle School") << endl;

    cout << "Searching for the deleted school:";
    findAndDisplay(schools, "Magnolia Elementary");

    return 0;
}