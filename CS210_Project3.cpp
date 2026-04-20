#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

public:
    void LoadFile(string fileName);
    void WriteBackupFile(string fileName);
    void SearchItem(string item);
    void PrintAllFrequencies();
    void PrintHistogram();
};

void GroceryTracker::LoadFile(string fileName) {
    ifstream inFile(fileName);
    string item;

    if (!inFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    while (inFile >> item) {
        itemFrequency[item]++;
    }

    inFile.close();
}

void GroceryTracker::WriteBackupFile(string fileName) {
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cout << "Error creating backup file." << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}

void GroceryTracker::SearchItem(string item) {
    if (itemFrequency.count(item) > 0) {
        cout << item << " was purchased " << itemFrequency[item] << " time(s)." << endl;
    }
    else {
        cout << item << " was purchased 0 time(s)." << endl;
    }
}

void GroceryTracker::PrintAllFrequencies() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void GroceryTracker::PrintHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    GroceryTracker tracker;
    int choice = 0;
    string item;

    tracker.LoadFile("CS210_Project_Three_Input_File.txt");
    tracker.WriteBackupFile("frequency.dat");

    do {
        cout << "\nCorner Grocer Menu" << endl;
        cout << "1. Search for item frequency" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> item;
            tracker.SearchItem(item);
            break;

        case 2:
            cout << endl;
            tracker.PrintAllFrequencies();
            break;

        case 3:
            cout << endl;
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter 1, 2, 3, or 4." << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}