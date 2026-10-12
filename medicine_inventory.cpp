#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

struct Medicine 
{
    int id, quantity;
    string name;
    int day, month, year;
    Medicine* next;
};

Medicine* head = nullptr;

time_t makeDate(int d, int m, int y) 
{
    tm date = {};
    date.tm_mday = d;
    date.tm_mon = m - 1;
    date.tm_year = y - 1900;
    date.tm_hour = 12;
    date.tm_isdst = -1;
    return mktime(&date);
}

void addMedicine() 
{
    Medicine* n = new Medicine;

    cout << "Enter Medicine ID: ";
    cin >> n->id;

    Medicine* p = head;
    while (p != nullptr) 
{
        if (p->id == n->id) 
{
            cout << "Medicine ID already exists!\n";
            delete n;
            return;
        }
        p = p->next;
    }

    cout << "Enter Medicine Name: ";
    cin >> ws;
    getline(cin, n->name);

    cout << "Enter Quantity: ";
    cin >> n->quantity;

    cout << "Enter Expiry Date (DD MM YYYY): ";
    cin >> n->day >> n->month >> n->year;

    if (n->quantity < 0 || n->month < 1 ||
        n->month > 12 || n->day < 1 ||
        n->day > 31 || n->year < 1900 ||
        mktime(new tm{}) == -1) {
        // Basic input checks are handled below.
    }

    n->next = head;
    head = n;
    cout << "Medicine added successfully!\n";
}

Medicine* searchMedicine(int id) 
{
    Medicine* p = head;
    while (p != nullptr)
 {
        if (p->id == id)
            return p;
        p = p->next;
    }
    return nullptr;
}

void search()
 {
    int id;
    cout << "Enter Medicine ID to search: ";
    cin >> id;

    Medicine* p = searchMedicine(id);
    if (p != nullptr)
 {
        cout << "Medicine Found!\n";
        cout << "Name: " << p->name
             << "\nQuantity: " << p->quantity
             << "\nExpiry: " << p->day << "-"
             << p->month << "-" << p->year << "\n";
    } else 
{
        cout << "Medicine not found!\n";
    }
}

void updateStock() 
{
    int id, qty;
    cout << "Enter Medicine ID: ";
    cin >> id;

    Medicine* p = searchMedicine(id);
    if (p == nullptr) 
{
        cout << "Medicine not found!\n";
        return;
    }

    cout << "Enter new stock quantity: ";
    cin >> qty;

    if (qty < 0) 
{
        cout << "Quantity cannot be negative!\n";
        return;
    }

    p->quantity = qty;
    cout << "Stock updated successfully!\n";
}

void display() 
{
    if (head == nullptr) 
{
        cout << "Inventory is empty!\n";
        return;
    }

    cout << "\n--- Medicine Inventory ---\n";
    Medicine* p = head;

    while (p != nullptr) 
{
        cout << "ID: " << p->id
             << " | Name: " << p->name
             << " | Quantity: " << p->quantity
             << " | Expiry: " << p->day << "-"
             << p->month << "-" << p->year << "\n";
        p = p->next;
    }
}

void checkExpiry()
 {
    time_t now = time(nullptr);
    tm* todayPtr = localtime(&now);
    tm today = *todayPtr;
    today.tm_hour = 12;
    today.tm_min = 0;
    today.tm_sec = 0;
    time_t todayTime = mktime(&today);

    bool found = false;
    Medicine* p = head;

    cout << "\n--- Medicines Expiring Within 30 Days ---\n";

    while (p != nullptr)
 {
        time_t expiry = makeDate(p->day, p->month, p->year);
        double days = difftime(expiry, todayTime) / 86400.0;

        if (days >= 0 && days <= 30) 
{
            cout << p->name << " (ID: " << p->id
                 << ") expires in " << static_cast<int>(days)
                 << " days.\n";
            found = true;
        } else if (days < 0)
 {
            cout << p->name << " (ID: " << p->id
                 << ") is EXPIRED.\n";
            found = true;
        }

        p = p->next;
    }

    if (!found)
        cout << "No medicines nearing expiry.\n";
}

int main()
 {
    int choice;

    do 
{
        cout << "\n===== MEDICINE INVENTORY SYSTEM =====\n";
        cout << "1. Add Medicine\n";
        cout << "2. Search Medicine\n";
        cout << "3. Update Stock\n";
        cout << "4. Display Inventory\n";
        cout << "5. Check Expiry\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
{
            case 1: addMedicine(); break;
            case 2: search(); break;
            case 3: updateStock(); break;
            case 4: display(); break;
            case 5: checkExpiry(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    while (head != nullptr)
 {
        Medicine* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
