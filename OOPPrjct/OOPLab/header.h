#ifndef HEADER_H
#define HEADER_H


#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using  namespace std; 

class person {
private:
    string name;
    int age;
    string dept;

protected:
    person();
   // virtual ~person();

    virtual void get_data();
    virtual void display_data();
    virtual string get_n();
};

class manager : public person {
private:
    int js;
    int es;
    string post;

public:
    manager();
   // ~manager() override;

    void get_data() override;
    void display_data() override;
    void save_file(const string &str);
};

class member : public person {
private:
    string hall;
    int batch;
    string contact_num;

public:
    member();
   // ~member() override;

    void get_data() override;
    void display_output();
    void save_t_file(const string &str);
    string get_name();
    string get_hall();
    string get_contact();
    bool operator==( member& other) ; // operator overloading

};

class event {
private:
    string event_name;
    string event_date;
    vector<member*> attendees;

public:
    event();
    //~event();

    void arr_event();
    void regi_member(member* m);
    void show_event();
    void save_to_file(const string& fn);
    void load_from_file(const string& fn);
};

class club {
protected:
    string cn;
    int est;
    vector<manager*> admins;
    vector<member*> mem;

    club():cn(" "),est(0){}
    //virtual ~club();

    virtual void dis_ftr() = 0;
    virtual void add_admin() = 0;
    virtual void show_structure() = 0;
    virtual void show_mem() = 0;
    virtual void add_mem() = 0;
    virtual void arrange_event() = 0;
};

class science_club : public club {
public:
    void dis_ftr() override;
    void add_admin() override;
    void show_structure() override;
    void add_mem() override;
    void show_mem() override;
    void arrange_event() override;
    //~science_club() override;
};

class debate_club : public club {
public:
    void dis_ftr() override;
    void add_admin() override;
    void show_structure() override;
    void add_mem() override;
    void show_mem() override;
    void arrange_event() override;
  //  ~debate_club() override;
};
#endif


