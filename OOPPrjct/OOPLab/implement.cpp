#include "header.h"
#include <fstream>



// Definitions for person class
person::person() : name(" "), age(0), dept(" ") {}
//person::~person() {}
void person::get_data() {
    cout << "Enter the name of the person: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the age of the person: ";
    cin >> age;
    cout << "Enter the department of the person: ";
    cin.ignore();
    getline(cin, dept);
}
void person::display_data() {
    cout << "The name of the person is: " << name << endl;
    cout << "The age of the person is: " << age << endl;
    cout << "The department of the person is: " << dept << endl;
}
string person::get_n() { return name; }

// Definitions for manager class
manager::manager() : person(), js(0), es(0), post(" ") {}
//manager::~manager() {}
void manager::get_data() {
    person::get_data();
    cout << "Enter the post: ";
    cin >> post;
    cout << "Enter the joining session: ";
    cin >> js;
    cout << "Enter the ending session: ";
    cin >> es;
}
void manager::save_file(const string& str) {
  ofstream file(str, ios::out | ios::app);
  if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    file << get_n() << " " << post << " " << js << " " << es << endl;
    file.close();
    }
void manager::display_data() {
    person::display_data();
    cout << "The post is: " << post << endl;
    cout << "The joining session is: " << js << endl;
    cout << "The ending session is: " << es << endl;
}

// Definitions for member class
member::member() : person(), hall(" "), batch(0), contact_num(" ") {}
//member::~member() {}
void member::get_data() {
    person::get_data();
    cout << "Enter your hall name: ";
    
    getline(cin, hall);
    cout << "Enter your batch: ";
    cin >> batch;
    cout << "Enter your contact number: ";
    cin >> contact_num;
}
void member::display_output() {
    person::display_data();
    cout << "Hall name is: " << hall << endl;
    cout << "Batch no: " << batch << endl;
    cout << "Contact no: " << contact_num << endl;
}
string member::get_name() { return get_n(); }
string member::get_hall() { return hall; }
string member::get_contact() { return contact_num; }

void member::save_t_file(const string &str) {
  fstream file(str, ios::out | ios::app);
  if (!file) {
    cout << "Error opening file for reading!" << endl;
        return;
  }

  file << get_n() << " " << hall << " " << contact_num << endl;
  file.close();
}

bool member::operator==( member& other)  {
    return this->get_name() == other.get_name()&& hall == other.hall && contact_num == other.contact_num;
}


// Definitions for event class
event::event() : event_name(" "), event_date(" ") {}
/*event::~event() {
    for (auto attendee : attendees)
        delete attendee;
    attendees.clear()
}*/
void event::arr_event() {
    cout << "Enter the event name: ";
    cin.ignore();
    getline(cin, event_name);
    cout << "Enter the event date: ";
    getline(cin, event_date);
}
void event::regi_member(member* m) {
  attendees.push_back(m);
  cout << "-------------------" << endl;
    cout << "The member is registered for the event." << endl;
    m->display_output();
}
void event::show_event() {
    cout << "Event Name: " << event_name << endl;
    cout << "Event Date: " << event_date << endl;
    cout << "Attendees: " << endl;
    for (auto attendee : attendees) {
        attendee->display_output();
        cout << endl;
    }
}
void event::save_to_file(const string& fn) {
    ofstream file(fn, ios::out | ios::app);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    file << "Event Name: " << event_name << endl;
    file << "Event Date: " << event_date << endl;
    for (auto attendee : attendees)
        file << attendee->get_name() << " " << attendee->get_hall() << " " << attendee->get_contact() << endl;
    file.close();
}
void event::load_from_file(const string& fn) {
    ifstream file(fn, ios::in);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

void science_club::dis_ftr() {
    cout << "The features provided by our Science club include:" << endl;
    cout << "1-> Hands-on learning" << endl;
    cout << "2-> Collaboration and teamwork" << endl;
    cout << "3-> Innovation and creativity" << endl;
    cout << "4-> Exposure to real-world science" << endl;
    cout << "5-> Career guidance" << endl;
}

void science_club::add_admin() {
    int n;
    cout << "How many admins do you want to select: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        manager* temp = new manager;
        temp->get_data();
        admins.push_back(temp);
    }
    cout<<"-----------------------"<<endl;
    cout << "Enter the file to save the admins information: " << endl;
    string str;
    cin>>str;
    for (int i = 0; i < admins.size(); i++) {
        admins[i]->save_file(str);
      }
}

void science_club::show_structure() {
    if (admins.empty()) {
        cout << "No admins in the club." << endl;
        return;
    }
    cout << "\n--- Club Admins ---" << endl;
    for (size_t i = 0; i < admins.size(); i++) {
        cout << "Admin " << i + 1 << ":" << endl;
        admins[i]->display_data();
        cout << "-------------------" << endl;
    }
}

void science_club::add_mem() {
    int m;
    cout << "How many members do you want to include in your club: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        member* temp = new member;
        temp->get_data();
        for (int i = 0; i < mem.size(); i++) {
          if (temp != mem[i]) {
            cout<<"The member is not enlisted yet so we can add him/her -_-"<<endl;
            }
          }
        mem.push_back(temp);
    }
    cout << "------------------------" << endl;
    cout << "Enter the file to save the data (.txt): " << endl;
    string str;
    cin >> str;
    for (int i = 0; i < mem.size(); i++) {
      mem[i]->save_t_file(str);
      }
}

void science_club::show_mem() {
    if (mem.empty()) {
        cout << "No members in the club." << endl;
        return;
    }
    cout << "\n--- Club Members ---" << endl;
    for (size_t i = 0; i < mem.size(); i++) {
        cout << "Member " << i + 1 << ":" << endl;
        mem[i]->display_output();
        cout << "-------------------" << endl;
    }
}

void science_club::arrange_event() {
    event e;
    e.arr_event();
    cout << "How many members do you want to register: " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        member* temp = new member;
        temp->get_data();
        e.regi_member(temp);
    }
    cout << "-------------------" << endl;
    cout<<endl<<endl<<"The Event details are provided below:->>>>"<<endl;
    e.show_event();
    string fn;
    cout << "Enter the file name: " << endl;
    cin>>fn;
    e.save_to_file(fn);
    e.load_from_file(fn);
}

/*science_club::~science_club() {
    for (auto adm : admins) {
        delete adm;
    }
    admins.clear();
    for (auto mm : mem) {
        delete mm;
    }
    mem.clear();
}*/
void debate_club::dis_ftr() {
    cout << "The features provided by our Debate club include:" << endl;
    cout << "1-> Public speaking opportunities" << endl;
    cout << "2-> Leadership skills development" << endl;
    cout << "3-> Critical thinking enhancement" << endl;
    cout << "4-> Debate competitions and workshops" << endl;
    cout << "5-> Collaboration and teamwork" << endl;
}

void debate_club::add_admin() {
    int n;
    cout << "How many admins do you want to select: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        manager* temp = new manager;
        temp->get_data();
        admins.push_back(temp);
    }
    cout << "------------------" << endl;
    cout << "Enter the file to save the admins information(.txt): " << endl;
    string str;
    cin >> str;
    for (int i = 0; i < admins.size(); i++) {
      admins[i]->save_file(str);
      }
}

void debate_club::show_structure() {
    if (admins.empty()) {
        cout << "No admins in the club." << endl;
        return;
    }
    cout << "\n--- Club Admins ---" << endl;
    for (size_t i = 0; i < admins.size(); i++) {
        cout << "Admin " << i + 1 << ":" << endl;
        admins[i]->display_data();
        cout << "-------------------" << endl;
    }
}

void debate_club::add_mem() {
    int m;
    cout << "How many members do you want to include in your club: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        member* temp = new member;
        temp->get_data();
        for (int i = 0; i < mem.size(); i++) {
          if (temp != mem[i]) {
            cout<<"The member is not enlisted yet so we can add him/her -_-"<<endl;
            }
          }
        mem.push_back(temp);
    }
    cout << "------------------------" << endl;
    cout << "Enter the file to save the data (.txt): " << endl;
    string str;
    cin >> str;
    for (int i = 0; i < mem.size(); i++) {
      mem[i]->save_t_file(str);
      }
}

void debate_club::show_mem() {
    if (mem.empty()) {
        cout << "No members in the club." << endl;
        return;
    }
    cout << "\n--- Club Members ---" << endl;
    for (size_t i = 0; i < mem.size(); i++) {
        cout << "Member " << i + 1 << ":" << endl;
        mem[i]->display_output();
        cout << "-------------------" << endl;
    }
}

void debate_club::arrange_event() {
    event e;
    e.arr_event();
    cout << "How many members do you want to register: " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        member* temp = new member;
        temp->get_data();
        e.regi_member(temp);
    }
    cout << endl << endl << "The Event details are provided below:->>>>" << endl;
    e.show_event();
    string ss;
    cout << "Enter the file name: " << endl;
    cin >> ss;
    e.save_to_file(ss);
    e.load_from_file(ss);
}

/*debate_club::~debate_club() {
    for (auto adm : admins) {
        delete adm;
    }
    admins.clear();
    for (auto mm : mem) {
        delete mm;
    }
    mem.clear();
}*/

