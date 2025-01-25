#include <iostream>
#include <string>
using namespace std;

const int max_rooms = 10;

struct ROOMS {
    int roomnumber;
    bool isbooked;
    string guestname;
    string guestaddress;
    string guestphone;
    double payment;
};

// Global array declaration
ROOMS rooms[max_rooms];

// Function declarations
void displaymenu();
void bookroom();
void checkin();
void checkout();
void showdetails();
void initializerooms();
void returnToMenu();
void displayRoomDetails(int roomnumber);

int main() {
    initializerooms();
    int choice;
    do {
        displaymenu();
        cin >> choice;
        switch (choice) {
        case 1: bookroom(); break;
        case 2: checkin(); break;
        case 3: checkout(); break;
        case 4: showdetails(); break;
        case 5: cout << "Exiting system. Thank you!\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void displaymenu() {
    cout << "   --------- Welcome ---------   " << endl;
    cout << "---------- Hotel Management System Menu ----------" << endl;
    cout << "1. Book a Room" << endl;
    cout << "2. Check In" << endl;
    cout << "3. Check Out" << endl;
    cout << "4. Show Booked Room Details" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void initializerooms() {
    for (int i = 0; i < max_rooms; i++) {
        rooms[i].roomnumber = i + 1;
        rooms[i].isbooked = false;
    }
}

void bookroom() {
    char bookAnother;
    do {
        int roomnumber;
        cout << "Enter room number to book (1-" << max_rooms << "): ";
        cin >> roomnumber;
        if (roomnumber < 1 || roomnumber > max_rooms) {
            cout << "Invalid room number." << endl;
            returnToMenu();
            return;
        }

        if (rooms[roomnumber - 1].isbooked) {
            cout << "Room is already occupied." << endl;
            displayRoomDetails(roomnumber);
            cout << "Do you want to book another room? (y/n): ";
            cin >> bookAnother;
            if (bookAnother == 'n' || bookAnother == 'N') {
                returnToMenu();
                return;
            }
            continue;
        }

        cout << "Enter guest name: ";
        cin.ignore();
        getline(cin, rooms[roomnumber - 1].guestname);
        cout << "Enter guest address: ";
        getline(cin, rooms[roomnumber - 1].guestaddress);
        cout << "Enter guest phone: ";
        getline(cin, rooms[roomnumber - 1].guestphone);
        rooms[roomnumber - 1].isbooked = true;

        // Display the booked room details
        cout << "Room " << roomnumber << " has been booked." << endl;
        displayRoomDetails(roomnumber);

        cout << "Do you want to book another room? (y/n): ";
        cin >> bookAnother;
    } while (bookAnother == 'y' || bookAnother == 'Y');

    returnToMenu();
}

void checkin() {
    int roomnumber;
    cout << "Enter room number to check in (1-" << max_rooms << "): ";
    cin >> roomnumber;
    if (roomnumber < 1 || roomnumber > max_rooms || !rooms[roomnumber - 1].isbooked) {
        cout << "Invalid room number or room is not booked." << endl;
        returnToMenu();
        return;
    }

    // Assuming check-in process includes confirming the room booking
    cout << "Guest checked in to room " << roomnumber << "." << endl;

    returnToMenu();
}

void checkout() {
    int roomnumber;
    cout << "Enter room number to check out (1-" << max_rooms << "): ";
    cin >> roomnumber;
    if (roomnumber < 1 || roomnumber > max_rooms || !rooms[roomnumber - 1].isbooked) {
        cout << "Invalid room number or room is not booked." << endl;
        returnToMenu();
        return;
    }

    // Assuming checkout process includes calculating payment and resetting the room status
    rooms[roomnumber - 1].isbooked = false;
    cout << "Guest checked out from room " << roomnumber << "." << endl;

    returnToMenu();
}

void showdetails() {
    cout << "Booked Room Details:" << endl;
    for (int i = 0; i < max_rooms; i++) {
        if (rooms[i].isbooked) {
            cout << "Room Number: " << rooms[i].roomnumber << endl;
            cout << "Guest Name: " << rooms[i].guestname << endl;
            cout << "Guest Address: " << rooms[i].guestaddress << endl;
            cout << "Guest Phone: " << rooms[i].guestphone << endl;
            cout << "----------------------" << endl;
        }
    }

    returnToMenu();
}

void displayRoomDetails(int roomnumber) {
    if (rooms[roomnumber - 1].isbooked) {
        cout << "Room Number: " << rooms[roomnumber - 1].roomnumber << endl;
        cout << "Guest Name: " << rooms[roomnumber - 1].guestname << endl;
        cout << "Guest Address: " << rooms[roomnumber - 1].guestaddress << endl;
        cout << "Guest Phone: " << rooms[roomnumber - 1].guestphone << endl;
    }
    else {
        cout << "Room " << roomnumber << " is not booked." << endl;
    }
}

void returnToMenu() {
    char choice;
    cout << "Do you want to return to the main menu? (y/n): ";
    cin >> choice;
    if (choice == 'n' || choice == 'N') {
        cout << "Exiting system. Thank you!\n";
        exit(0);
    }
}

