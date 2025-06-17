#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

using namespace std;

int committe(int x); // here x is the number of people involved

int main()
{
    cout << "===========\n";
    cout << "  Welcome \n";
    cout << "===========\n";
    cout << "==========================================================================================================\n";
    cout << "  This program is to assign order of multiple people the months in which they can collect their committe\n";
    cout << "==========================================================================================================\n\n";
    cout << "=============================================================\n";
    cout << "  Enter the Number of people participating in the committe:\n";
    cout << "=============================================================\n";

    int num1 = 0;
    committe(num1);
    return 0;
}

int committe(int x)
{
    int money;
    cin >> x;

    cout << "=========================================================\n";
    cout << "  Enter the monthly payment of each person in Rs  : "; cin >> money;
    cout << "\n=========================================================\n";

    string months[12] = { "January", "Februrary", "March", "April", "May", "June", "July", "August", "September", "Octuber", "Nevember", "December" };

    cout << "==============================================================\n";
    cout << "  The return of your committe is " << money * x << " Rs\n";
    cout << "==============================================================\n";

    int index, startMonth;
    cout << "==============================================================\n";
    cout << "  Enter the Number of the Month in which the committe starts (1 for January, 2 for February, etc.): "; cin >> startMonth;
    cout << "==============================================================\n";

    if (startMonth < 1 || startMonth > 12) {
        cout << "==================================\n";
        cout << "  Invalid Input! Please restart the program.\n";
        cout << "==================================\n";
        return 0;
    }
    else {
        index = startMonth - 1;
        cout << "============================================\n";
        cout << "  The First Month of committe will be " << months[index] << endl;
        cout << "============================================\n";

        int endMonth = (index + x - 1) % 12;

        cout << "============================================\n";
        cout << "  The Last Month of committe will be " << months[endMonth] << endl;
        cout << "============================================\n";
    }

    // Entering names
    vector<string> name(x);
    for (int i = 0; i < x; i++) {
        cout << "====================================\n";
        cout << "  Enter the Name of person " << i + 1 << ": "; cin >> name[i];
        cout << "====================================\n";
    }

    // Shuffle participants
    vector<int> num(x);
    for (int i = 0; i < x; i++) {
        num[i] = i;
    }
    random_shuffle(num.begin(), num.end());

    // Assign committe months
    int currentMonth = startMonth - 1;
    for (int i = 0; i < x; i++) {
        cout << "========================================================\n";
        cout << "Congratulations " << name[num[i]] << "! You win the " << i + 1 << " committe for the month of " << months[currentMonth] << endl;
        cout << "=========================================================\n";

        currentMonth = (currentMonth + 1) % 12;
    }

    return 0;
}