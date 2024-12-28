#include "header.h"
#include"implement.cpp"

using namespace std;

void displayMenu() {
    cout << "\n-----------------------------------------------" << endl;
    cout << "           🌟 Club Management System 🌟          " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1️⃣ Display Club Features" << endl;
    cout << "2️⃣ Add Club Administrators" << endl;
    cout << "3️⃣ Show Club Structure (Admins)" << endl;
    cout << "4️⃣ Add Club Members" << endl;
    cout << "5️⃣ Show Club Members" << endl;
    cout << "6️⃣ Arrange an Event" << endl;
    cout << "0️⃣ Exit" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void handleClubMenu(int clubType) {
    int choice;
    if (clubType == 1) {
      science_club s;
      char ch;
      do{
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: s.dis_ftr(); break;
            case 2: s.add_admin(); break;
            case 3: s.show_structure(); break;
            case 4: s.add_mem(); break;
            case 5: s.show_mem(); break;
            case 6: s.arrange_event(); break;
            case 0: cout << "Exiting the application. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
            }
            cout<<"Do you want to continue with Science club(y/n): ";
      cin>>ch;
      } while (ch != 'n');
    
      
    } else if (clubType == 2) {
      char ch;
      debate_club d;
      do {

      
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: d.dis_ftr(); break;
            case 2: d.add_admin(); break;
            case 3: d.show_structure(); break;
            case 4: d.add_mem(); break;
            case 5: d.show_mem(); break;
            case 6: d.arrange_event(); break;
            case 0: cout << "Exiting the application. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
      
      cout << "Do you want to continue with Debate club(y/n): ";
      cin>>ch;
    }while(ch!='n');
    }
}

int main() {
    char ch;

    do {
        cout << "-----------------------------------------------" << endl;
        cout << "      🌟 Welcome to the Club Management E-Service! 🌟" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        cout << "Your gateway to managing clubs, events, and members effortlessly!" << endl;
        cout << endl;
        cout << "✨ Features of this application include:" << endl;
        cout << "1️⃣ Manage Science and Debate Clubs with ease." << endl;
        cout << "2️⃣ Add, view, and organize members and administrators." << endl;
        cout << "3️⃣ Schedule and register events seamlessly." << endl;
        cout << "4️⃣ Save and load event details from files for future reference." << endl;
        cout << "5️⃣ Enhance collaboration and foster community spirit." << endl;
        cout << endl;
        cout << "----------*MeNu*---------" << endl;
        cout << "Enter the club to view and insert members and manage events: (1->Science club, 2->Debate club) " << endl;

        int c;
        cin >> c;

        if (c == 1 || c == 2) {
            handleClubMenu(c);
        } else {
            cout << "Invalid club type. Please enter 1 for Science club or 2 for Debate club." << endl;
        }

        cout << "Do you want to continue the program? Press 'a' to abort the program, any other key to continue: ";
        cin >> ch;

    } while (ch != 'a');

    return 0;
}
