#include <iostream>
#include <vector>
#include "CSVReader.cpp"
#include "SchoolBST.cpp"

// Code is left for testing various cases

int main()
{
    SchoolBST schoolTree;

    /*
    cout << "Searching an empty tree: " << endl;
    School* schoolSearch = schoolTree.findByName("Blue Ridge High School");
    cout << "- " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    cout << "Deleting from an empty tree: " << endl;
    schoolTree.deleteByName("Harbor View High School");
    cout << endl;
    */

    const vector<vector<string>> data = CSVReader::readCSV("C:/Users/Charlie P/Documents/# Senior Files/Advanced Data Structures and Algorithms/MidtermRepo/CS210_Midterm_Project/ReadCSV/schools.csv");

    for (int i = 1; i < data.size(); i++)
    {
        const vector<string>& schoolData = data[i];

        schoolTree.insert(new School(schoolData[0], schoolData[1], schoolData[2], schoolData[3], schoolData[4]));
    }

    cout << "In-Order Traversal: " << endl;
    schoolTree.displayInOrder();
    cout << endl;

    cout << "Pre-Order Traversal: " << endl;
    schoolTree.displayPreOrder();
    cout << endl;

    cout << "Post-Order Traversal: " << endl;
    schoolTree.displayPostOrder();
    cout << endl;

    /*
    cout << "Searching for a school in the tree: " << endl;
    schoolSearch = schoolTree.findByName("Oceanview High School");
    cout << "- " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    cout << "Searching for a school that doesn't exist: " << endl;
    schoolSearch = schoolTree.findByName("Breakneck Elementary");
    cout << "- " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    cout << "Deleting an element in a tree: " << endl;
    schoolTree.deleteByName("Valley View Middle School");

    cout << "- Searching for a school that was just deleted: " << endl;
    schoolSearch = schoolTree.findByName("Valley View Middle School");
    cout << "  - " << (schoolSearch == nullptr ? "nullptr" : schoolSearch->display()) << endl;

    cout << "Deleting a school that doesn't exist: " << endl;
    schoolTree.deleteByName("Camelhump High");
    */

    cout << "Type 'display [NAME OF SCHOOL]' to display info of that school" << endl;
    cout << "Type 'delete [NAME OF SCHOOL]' to delete that school" << endl;
    cout << "Type 'quit' to quit" << endl;

    string userInput;
    while (true)
    {
        cout << "> ";
        getline(cin, userInput);

        if (userInput.substr(0, 7) == "display")
        {
            School* foundSchool = schoolTree.findByName(userInput.substr(8));
            cout << (foundSchool == nullptr ? "nullptr" : foundSchool->display()) << endl;
        }
        else if (userInput.substr(0, 6) == "delete")
        {
            schoolTree.deleteByName(userInput.substr(7));
        }
        else if (userInput.substr(0, 4) == "quit")
        {
            return 0;
        }

        cout << endl;
    }
}