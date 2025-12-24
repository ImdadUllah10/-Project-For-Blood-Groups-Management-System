#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function declarations
string FormatBloodGroup(string blood);
void app();
void Add();
void View();
void Search();
void Update();
void DonationCompatibility();
void Delete();

int main()
{
    cout << "-------------------------------------" << endl;
    cout << "    Blood Group Management System    " << endl;
    cout << "-------------------------------------" << endl;

    app();
    return 0;
}

// ---------------- Format Blood Group ----------------

string FormatBloodGroup(string blood)
{
    for (size_t i = 0; i < blood.length(); i++)
    {
        blood[i] = toupper(blood[i]);
    }
    return blood;
}

// ---------------- ADD RECORD ----------------

void Add()
{
    string name, bloodGroup, age, gender;

    cin.ignore(); // clear buffer

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Blood Group: ";
    getline(cin, bloodGroup);
    bloodGroup = FormatBloodGroup(bloodGroup);

    cout << "Enter Age: ";
    getline(cin, age);

    cout << "Enter Gender (Male/Female): ";
    getline(cin, gender);

    ofstream file("blood_data.txt", ios::app);

    if (file.is_open())
    {
        file << name << " | "
             << bloodGroup << " | "
             << age << " | "
             << gender << endl;

        file.close();
        cout << "Record added successfully!\n";
    }
    else
    {
        cout << "Error opening file!\n";
    }

    app(); // return to menu
}

// ---------------- VIEW RECORDS ----------------
void View()
{
    string line;
    ifstream file("blood_data.txt");

    if (file.is_open())
    {
        cout << "\n--- All Blood Records ---\n";
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No data file found!\n";
    }

    app();
}

// ---------------- SEARCH RECORD ----------------
void Search()
{
    string search, line;
    bool found = false;

    cin.ignore();
    cout << "Enter name or blood group to search: ";
    getline(cin, search);

    ifstream file("blood_data.txt");

    while (getline(file, line))
    {
        if (line.find(search) != string::npos)
        {
            cout << "Record Found: " << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No record found.\n";

    file.close();
    app();
}

// ---------------- UPDATE RECORD ----------------
void Update()
{
    string search, line;
    bool found = false;

    cin.ignore();
    cout << "Enter name to update: ";
    getline(cin, search);

    ifstream file("blood_data.txt");
    ofstream temp("temp.txt");

    while (getline(file, line))
    {
        if (line.find(search) != string::npos)
        {
            string name, blood, age, gender;

            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new blood group: ";
            getline(cin, blood);
            cout << "Enter new age: ";
            getline(cin, age);
            cout << "Enter new gender: ";
            getline(cin, gender);

            temp << name << " | "
                 << blood << " | "
                 << age << " | "
                 << gender << endl;

            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("blood_data.txt");
    rename("temp.txt", "blood_data.txt");

    if (found)
        cout << "Record updated successfully.\n";
    else
        cout << "Record not found.\n";

    app();
}

// ---------------- DELETE RECORD ----------------
void Delete()
{
    string search, line;
    bool found = false;

    cin.ignore();
    cout << "Enter name to delete: ";
    getline(cin, search);

    ifstream file("blood_data.txt");
    ofstream temp("temp.txt");

    while (getline(file, line))
    {
        if (line.find(search) == string::npos)
        {
            temp << line << endl;
        }
        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("blood_data.txt");
    rename("temp.txt", "blood_data.txt");

    if (found)
        cout << "Record deleted successfully.\n";
    else
        cout << "Record not found.\n";

    app();
}

// ---------------- Donation Compatibility ----------------

void DonationCompatibility()
{
    string blood;

    cin.ignore();
    cout << "Enter donor blood group: ";
    getline(cin, blood);

    cout << "\nThis blood group can donate to:\n";

    if (blood == "O-" || blood == "o-")
        cout << "All Blood Groups";
    else if (blood == "O+" || blood == "o+")
        cout << "O+, A+, B+, AB+";
    else if (blood == "A-" || blood == "a-")
        cout << "A-, A+, AB-, AB+";
    else if (blood == "A+" || blood == "a+")
        cout << "A+, AB+";
    else if (blood == "B-" || blood == "b-")
        cout << "B-, B+, AB-, AB+";
    else if (blood == "B+" || blood == "b+")
        cout << "B+, AB+";
    else if (blood == "AB-" || blood == "ab-")
        cout << "AB-, AB+";
    else if (blood == "AB+" || blood == "ab+")
        cout << "AB+ only";
    else
        cout << "Invalid blood group entered";

    cout << endl;
    app(); // return to menu
}


// ---------------- MENU ----------------
void app()
{
    int choice;

    cout << "\nChoose an option:\n";
    cout << "1. Add\n";
    cout << "2. View\n";
    cout << "3. Search\n";
    cout << "4. Update\n";
    cout << "5. Delete\n";
    cout << "6. Blood Donation Compatibility\n";
    cout << "7. Exit\n";
    cout << "Select: ";

    cin >> choice;

    switch (choice)
    {
    case 1: Add(); break;
    case 2: View(); break;
    case 3: Search(); break;
    case 4: Update(); break;
    case 5: Delete(); break;
    case 6: DonationCompatibility(); break;
    case 7: exit(0);
    default:
        cout << "Invalid option!\n";
        app();
    }
}
