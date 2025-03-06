#include <iostream>
#include <vector>
#include "CSVReader.cpp"
#include "SchoolBST.cpp"

int main()
{
    SchoolBST schoolTree;

    const vector<vector<string>> data = CSVReader::readCSV("C:/Users/Charlie P/Documents/# Senior Files/Advanced Data Structures and Algorithms/MidtermRepo/CS210_Midterm_Project/ReadCSV/schools.csv");

    for (int i = 1; i < data.size(); i++)
    {
        const vector<string>& schoolData = data[i];

        schoolTree.insert(new School(schoolData[0], schoolData[1], schoolData[2], schoolData[3], schoolData[4]));
    }

    cout << "Pre-Order Traversal: " << endl;
    schoolTree.preOrderTraversal();
    cout << endl;

    cout << "Post-Order Traversal: " << endl;
    schoolTree.postOrderTraversal();
    cout << endl;


}