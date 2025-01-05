#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Room structure
struct Room {
    int roomNumber;
    bool isBooked;
    string customerName;
};

// Hotel class
class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int totalRooms) {
        for (int i = 1; i <= totalRooms; ++i) {
            Room room = {i, false, ""};
            rooms.push_back(room);
        }
    }

    void displayAvailableRooms() {
        cout << "\nAvailable Rooms:" << endl;
        for (const auto& room : rooms) {
            if (!room.isBooked) {
                cout << "Room " << room.roomNumber << "\n";
            }
        }
    }

    void bookRoom(int roomNumber, const string& customerName) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (!room.isBooked) {
                    room.isBooked = true;
                    room.customerName = customerName;
                    cout << "\nRoom " << roomNumber << " booked successfully for " << customerName << "!\n";
                } else {
                    cout << "\nRoom " << roomNumber << " is already booked!\n";
                }
                return;
            }
        }
        cout << "\nInvalid room number!\n";
    }

    void checkoutRoom(int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (room.isBooked) {
                    room.isBooked = false;
                    room.customerName = "";
                    cout << "\nRoom " << roomNumber << " is now available!\n";
                } else {
                    cout << "\nRoom " << roomNumber << " is not currently booked!\n";
                }
                return;
            }
        }
        cout << "\nInvalid room number!\n";
    }
};

int main() {
    int totalRooms;
    cout << "Enter the total number of rooms in the hotel: ";
    cin >> totalRooms;

    Hotel hotel(totalRooms);

    int choice;
    do {
        cout << "\n--- Hotel Management System ---\n";
        cout << "1. Display Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Checkout a Room\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                hotel.displayAvailableRooms();
                break;
            }
            case 2: {
                int roomNumber;
                string customerName;
                cout << "Enter room number to book: ";
                cin >> roomNumber;
                cin.ignore(); // To ignore leftover newline character
                cout << "Enter customer name: ";
                getline(cin, customerName);
                hotel.bookRoom(roomNumber, customerName);
                break;
            }
            case 3: {
                int roomNumber;
                cout << "Enter room number to checkout: ";
                cin >> roomNumber;
                hotel.checkoutRoom(roomNumber);
                break;
            }
            case 4: {
                cout << "Exiting the system. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again!\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

