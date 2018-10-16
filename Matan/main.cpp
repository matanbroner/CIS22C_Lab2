
#include <iostream>
#include "Stack.h"
#include "DerivedCurrencies.h"
using namespace std;
int main(int argc, const char * argv[]) {
    
    cout << "_____________________________________________" << endl;
    cout << "Welcome to the CIS 22C List and Stack Program" << endl;
    cout << "---------------------------------------------" << endl << endl;

    cout << "Creating integer Linked-List with data [3, 56, 76, 12, 14, 2, 43]" << endl;
    List<int> intList;
    intList.addAtHead(3);
    intList.addAtPos(1, 56);
    intList.addAtPos(2, 76);
    intList.addAtPos(3, 12);
    intList.addAtPos(4, 14);
    intList.addAtPos(5, 2);
    intList.addAtTail(43);
    cout << "Current integer list printed:\n";
    intList.printList();
    cout << endl;

    cout << "Sorting integer list in ascending order..." << endl;
    intList.sortListAcsending();
    cout << "Current integer list printed:\n";
    intList.printList();
    cout << endl;

    cout << "Sorting integer list in descending order..." << endl;
    intList.sortListDecsending();
    cout << "Current integer list printed:\n";
    intList.printList();
    cout << endl;

    cout << "Attempting to add value 7 at index -3 in the integer list..." << endl;
    intList.addAtPos(-3, 7);
    cout << endl;

    cout << "Attempting to add value 10 at index 23 in the integer list..." << endl;
    intList.addAtPos(23, 10);
    cout << endl;

    cout << "Now displaying the ability to use an array of Stacks in order to hold student test scores..." << endl;
    Stack<double> testScores[2];
    double testScoreArray[2][3] =
    {
        {87.5, 65.8, 99.6},
        {98.6, 76.54, 88.32}
    };
    cout << endl;
    cout << "Test scores for 3 tests for students Jimmy and Hannah:" << endl;
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) cout << "Jimmy: ";
        else cout << "Hannah: ";
        for (int j = 0; j < 3; j++)
        {
            testScores[i].push(testScoreArray[i][j]);
            cout << "[" << testScoreArray[i][j] << "] ";
        }
        cout << endl;
    }

    cout << "Sorting Jimmy and Hannah's tests scores in descending order..." << endl;
    testScores[0].sortStackDescending();
    testScores[1].sortStackDescending();
    cout << "Dropping each student's lowest test grade..." << endl << endl;
    cout << "Jimmy's dropped test grade: " << testScores[0].pop() << endl;
    cout << "Hannah's dropped test grade: " << testScores[1].pop() << endl;
    cout << endl;

    cout << "Test scores for remaining tests for students Jimmy and Hannah after drop:" << endl;
    for (int i = 0; i < 2; i++)
    {
        if (i == 0) cout << "Jimmy: ";
        else cout << "Hannah: ";
        for (int j = 0; j < testScores[i].stackCount(); j++)
        {
            cout << "[" << testScoreArray[i][j] << "] ";
        }
        cout << endl;
    }
    cout << endl << endl;

    cout << "Now displaying the ability to hold ADT's inside your Stack ADT, using the Dollar class..." << endl;
    Stack<Dollar> dollarStack;
    cout << "Adding Dollar values of: 12.56, 43.6567, 54.21, 43.21, and a default Dollar object" << endl;
    dollarStack.push(Dollar(12.56));
    dollarStack.push(Dollar(43.6567));
    dollarStack.push(Dollar(54.21));
    dollarStack.push(Dollar(43.21));
    dollarStack.push(Dollar());
    cout << "Sorting stack in ascending order and then popping each value off until stack is empty:" << endl;
    dollarStack.sortStackAscending();
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << dollarStack.pop();
        cout << "Current stack count: " << dollarStack.stackCount() << endl << endl;
    }
    
    cout << "Now using the general 'add' method to display a pre-sorted string linked-list:" << endl;
    List<string> strList;
    strList.add("A");
    strList.add("hello");
    strList.add("good");
    strList.add("T");
    strList.add("C++");
    strList.add("javaScript");
    strList.add("HoMeWork");
    strList.printList();
    return 0;
}

