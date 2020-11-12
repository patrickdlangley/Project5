// Collin Roe
// 2/2/20
// Pointers
// this program works with pointers to pass values
// I could not get the program to work properly and I could not figure out the issue

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//checks to make sure time is valid
void Check_Time(int timed)
{
    while (true) {
        if (0 < timed <= 60)
            break;
        else {
            cout << "Invalid Input. Enter again: " << endl;
            cin >> timed;
        }
    }
}

//finds low value
int* Find_Low(int array[])
{
    int* a = new int;
    *a = 1000000;
    for (int i = 0; i < 4; i++)
    {
        if (*a > array[i])
        {
            *a = array[i];
        }
    }
    return a;
}

//finds high value
int* Find_High(int array[])
{
    int* a = new int;
    *a = -1000000;
    for (int i = 0; i < 4; i++)
    {
        if (*a < array[i])
        {
            *a = array[i];
        }
    }
    return a;
}

//gets time funcion returns 
double Get_Times()
{

    int sum = 0;
    double average;
    int timed[4];

    for (int i = 0; i < 4; i++) {

        cout << "Enter the runners 4 times" << endl;
        cin >> timed[i];

        Check_Time(timed[i]);
    }

    int* largest = Find_High(timed);
    int* smallest = Find_Low(timed);

    //loop to find sum of all times
    for (int x = 0; x < 4; x++) {
        sum = sum + timed[x];
    }
    cout << sum << " " << *largest << " " << *smallest << endl;

    average = (sum - *largest - *smallest) / 2;

    return average;
}







int main()
{

    string sprinterName[5];
    double avgTime[5];

    //loop for 5 sprinters
    for (int i = 0; i < 5; i++) {

        cout << "Enter runners name" << endl;
        cin.get();
        getline(cin, sprinterName[i]);
        avgTime[i] = Get_Times();
    }



    for (int y = 0; y < 5; y++) {
        cout << sprinterName[y] << " has average time of: " << avgTime[y] << endl;

    }

    return 0;
}
