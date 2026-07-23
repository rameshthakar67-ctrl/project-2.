#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    // Default Constructor
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int num, const char *name, const char *src, const char *dest, const char *time)
    {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int num)
    {
        trainNumber = num;
    }

    void setTrainName(const char *name)
    {
        strcpy(trainName, name);
    }

    void setSource(const char *src)
    {
        strcpy(source, src);
    }

    void setDestination(const char *dest)
    {
        strcpy(destination, dest);
    }

    void setTrainTime(const char *time)
    {
        strcpy(trainTime, time);
    }

    // Getters
    int getTrainNumber()
    {
        return trainNumber;
    }

    const char *getTrainName()
    {
        return trainName;
    }

    const char *getSource()
    {
        return source;
    }

    const char *getDestination()
    {
        return destination;
    }

    const char *getTrainTime()
    {
        return trainTime;
    }

    // Input Train Details
    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Train Details
    void displayTrainDetails()
    {
        cout << "\nTrain Number : " << trainNumber << endl;
        cout << "Train Name   : " << trainName << endl;
        cout << "Source       : " << source << endl;
        cout << "Destination  : " << destination << endl;
        cout << "Train Time   : " << trainTime << endl;
    }

    // Static Function
    static int getTrainCount()
    {
        return trainCount;
    }
};

// Initialize Static Member
int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    // Add Train
    void addTrain()
    {
        if (totalTrains < 100)
        {
            cout << "\nEnter Details of Train " << totalTrains + 1 << endl;
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
        else
        {
            cout << "Train Storage Full!\n";
        }
    }

    // Display All Trains
    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No Train Records Found.\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\n------ Train " << i + 1 << " ------";
            trains[i].displayTrainDetails();
        }
    }

    // Search Train
    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found!\n";
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "Train Not Found.\n";
    }
};

int main()
{
    RailwaySystem rs;
    int choice, number;

    do
    {
        cout << "\n===== Railway Management System =====\n";
        cout << "1. Add Train\n";
        cout << "2. Display All Trains\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Display Train Count\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            rs.addTrain();
            break;

        case 2:
            rs.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number: ";
            cin >> number;
            rs.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Current Train Objects: "
                 << Train::getTrainCount() << endl;
            break;

        case 5:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
