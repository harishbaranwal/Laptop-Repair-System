#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct RepairRequest {
    int id;
    string customerName;
    string laptopModel;
    string problemDescription;
    string status; // Pending, In Progress, Completed
};

// Global vector to hold all requests
vector<RepairRequest> requests;

// Function to load existing requests from file
void loadRequests() {
    ifstream file("requests.txt");
    RepairRequest req;
    while (file >> req.id) {
        file.ignore();
        getline(file, req.customerName);
        getline(file, req.laptopModel);
        getline(file, req.problemDescription);
        getline(file, req.status);
        requests.push_back(req);
    }
    file.close();
}

// Function to save all requests to file
void saveRequests() {
    ofstream file("requests.txt");
    for (auto &req : requests) {
        file << req.id << endl;
        file << req.customerName << endl;
        file << req.laptopModel << endl;
        file << req.problemDescription << endl;
        file << req.status << endl;
    }
    file.close();
}

void addRepairRequest() {
    RepairRequest req;
    req.id = requests.empty() ? 1 : requests.back().id + 1;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, req.customerName);

    cout << "Enter Laptop Model: ";
    getline(cin, req.laptopModel);

    cout << "Enter Problem Description: ";
    getline(cin, req.problemDescription);

    req.status = "Pending";

    requests.push_back(req);
    saveRequests();

    cout << "Repair Request Added Successfully. Request ID: " << req.id << endl;
}

void updateRepairStatus() {
    int id;
    cout << "Enter Repair Request ID to update: ";
    cin >> id;

    bool found = false;
    for (auto &req : requests) {
        if (req.id == id) {
            cout << "Current Status: " << req.status << endl;
            cout << "Enter New Status (Pending/In Progress/Completed): ";
            cin.ignore();
            getline(cin, req.status);
            saveRequests();
            cout << "Status Updated Successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Request ID not found!\n";
    }
}

void generateReport() {
    cout << "\n--- Repair Report ---\n";
    for (const auto &req : requests) {
        cout << "\nRequest ID: " << req.id
             << "\nCustomer: " << req.customerName
             << "\nModel: " << req.laptopModel
             << "\nIssue: " << req.problemDescription
             << "\nStatus: " << req.status << "\n";
    }
}

void menu() {
    int choice;
    do {
        cout << "\n=== Laptop Repair System ===\n";
        cout << "1. Add Repair Request\n";
        cout << "2. Update Repair Status\n";
        cout << "3. Generate Report\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRepairRequest(); break;
            case 2: updateRepairStatus(); break;
            case 3: generateReport(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}

int main() {
    loadRequests();
    menu();
    return 0;
}
