#include <iostream>
#include <vector>
#include "School.cpp"
#include "CSVReader.cpp"
#include "timer.h"
#include "SchoolLinkedList.cpp"
#include "SchoolBST.cpp"
#include "SchoolHashTable.cpp"
using namespace std;

void testLinkedList(const vector<vector<string>>& illinoisSchoolData, const vector<vector<string>>& usaSchoolData, const double percentage);
void testBST(const vector<vector<string>>& illinoisSchoolData, const vector<vector<string>>& usaSchoolData, const double percentage);
void testHashTable(const vector<vector<string>>& illinoisSchoolData, const vector<vector<string>>& usaSchoolData, const double percentage);

int main()
{
    const vector<vector<string>> illinoisSchoolData = CSVReader::readCSV("C:/Users/Charlie P/Documents/# Senior Files/Advanced Data Structures and Algorithms/MidtermRepo/CS210_Midterm_Project/DatasetPerformance/Illinois_Schools.csv");
    const vector<vector<string>> usaSchoolData = CSVReader::readCSV("C:/Users/Charlie P/Documents/# Senior Files/Advanced Data Structures and Algorithms/MidtermRepo/CS210_Midterm_Project/DatasetPerformance/USA_Schools.csv");

    for (double i=0.1; i<=1;i+=0.1)
    {
        cout << (i * 100) << "% of USA School List:\n-----------------------------------" << endl;
        testLinkedList(illinoisSchoolData, usaSchoolData, i);
        cout << endl << endl;
        testBST(illinoisSchoolData, usaSchoolData, i);
        cout << endl << endl;
        testHashTable(illinoisSchoolData, usaSchoolData, i);
        cout << endl << endl;
    }
}

void testLinkedList(const vector<vector<string>>& illinoisSchoolData, const vector<vector<string>>& usaSchoolData, const double percentage)
{
    Timer timer;

    cout << "Linked List" << endl;
    SchoolLinkedList schoolLinkedList;

    timer.restart();
    for (int i = 1; i < usaSchoolData.size()* percentage; i++)
    {
        const vector<string>& schoolData = usaSchoolData[i];

        schoolLinkedList.insertLast(new SchoolListNode(new School(
            (schoolData.size() >= 1 ? schoolData[0] : ""),
            (schoolData.size() >= 2 ? schoolData[1] : ""),
            (schoolData.size() >= 3 ? schoolData[2] : ""),
            (schoolData.size() >= 4 ? schoolData[3] : ""),
            (schoolData.size() >= 5? schoolData[4] : "")
            )));
    }
    cout << "- Time to insert all USA schools: " << timer.get_time() << " microseconds" << endl;

    timer.restart();
    for (int i = 1; i < illinoisSchoolData.size(); i++)
    {
        schoolLinkedList.findByName(illinoisSchoolData[i][0]);
    }
    cout << "- Time to find all Illinois schools: " << timer.get_time() << " microseconds" << endl;

    timer.restart();
    for (int i = 1; i < illinoisSchoolData.size(); i++)
    {
        schoolLinkedList.deleteByName(illinoisSchoolData[i][0]);
    }
    cout << "- Time to delete all Illinois schools: " << timer.get_time() << " microseconds" << endl;
}
void testBST(const vector<vector<string>>& illinoisSchoolData, const vector<vector<string>>& usaSchoolData, const double percentage)
{
    Timer timer;

    cout << "Binary Search Tree" << endl;
    SchoolBST schoolBST;

    timer.restart();
    for (int i = 1; i < usaSchoolData.size() * percentage; i++)
    {
        const vector<string>& schoolData = usaSchoolData[i];

        schoolBST.insert(new SchoolBSTNode(new School(
            (schoolData.size() >= 1 ? schoolData[0] : ""),
            (schoolData.size() >= 2 ? schoolData[1] : ""),
            (schoolData.size() >= 3 ? schoolData[2] : ""),
            (schoolData.size() >= 4 ? schoolData[3] : ""),
            (schoolData.size() >= 5? schoolData[4] : "")
            )));
    }
    cout << "- Time to insert all USA schools: " << timer.get_time() << " microseconds" << endl;

    timer.restart();
    for (int i = 1; i < illinoisSchoolData.size(); i++)
    {
        schoolBST.findByName(illinoisSchoolData[i][0]);
    }
    cout << "- Time to find all Illinois schools: " << timer.get_time() << " microseconds" << endl;

    timer.restart();
    for (int i = 1; i < illinoisSchoolData.size(); i++)
    {
        schoolBST.deleteByName(illinoisSchoolData[i][0]);
    }
    cout << "- Time to delete all Illinois schools: " << timer.get_time() << " microseconds" << endl;
}
void testHashTable(const vector<vector<string>>& illinoisSchoolData, const vector<vector<string>>& usaSchoolData, const double percentage)
{
    Timer timer;

    cout << "Hash Table" << endl;
    SchoolHashTable schoolHashTable;

    timer.restart();
    for (int i = 1; i < usaSchoolData.size()* percentage; i++)
    {
        const vector<string>& schoolData = usaSchoolData[i];

        schoolHashTable.insert(new School(
            (schoolData.size() >= 1 ? schoolData[0] : ""),
            (schoolData.size() >= 2 ? schoolData[1] : ""),
            (schoolData.size() >= 3 ? schoolData[2] : ""),
            (schoolData.size() >= 4 ? schoolData[3] : ""),
            (schoolData.size() >= 5? schoolData[4] : "")
            ));
    }
    cout << "- Time to insert all USA schools: " << timer.get_time() << " microseconds" << endl;

    timer.restart();
    for (int i = 1; i < illinoisSchoolData.size(); i++)
    {
        schoolHashTable.findByName(illinoisSchoolData[i][0]);
    }
    cout << "- Time to find all Illinois schools: " << timer.get_time() << " microseconds" << endl;

    timer.restart();
    for (int i = 1; i < illinoisSchoolData.size(); i++)
    {
        schoolHashTable.deleteByName(illinoisSchoolData[i][0]);
    }
    cout << "- Time to delete all Illinois schools: " << timer.get_time() << " microseconds" << endl;
}