
#include "person.h"

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete email;
    delete phone;
}


Person::Person(string f_name, string l_name, string b_date, string email_addr, string phone_nbr){
    // TODO: Complete this method!
    // phone and email strings are in full version
    birthdate = new Date(b_date);
    int finder = email_addr.find(")");
    string email_typ = email_addr.substr(0,finder);
    string addr = email_addr.substr(finder);
    finder = phone_nbr.find(")");
    string phone_typ = phone_nbr.substr(0,finder);
    string nbr = phone_nbr.substr(finder);
    email = new Email(email_typ, addr);
    phone = new Phone*(phone_typ, nbr);

}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    std::getline(std::cin,type);
    cout << "Email address: ";
    // code here
    string emailAddr;
    std::getline(std::cin,emailAddr);
    email = new Email(type,emailAddr)

    cout << "Type of phone number: ";
    // code here
    std::getline(std::cin,type);
    cout << "Phone number: ";
    // code here
    string phoneNum;
    std::getline(std::cin,phoneNum);
    phone = new Phone(type, phoneNum);
    
}

void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    string fn, ln, bd, l4, l5, buf;
    fstream fin;
    fin.open(filename);
    fin >> fn >> ln >> bd >> l4 >> l5 >> buf;
        f_name = fn;
        l_name = ln;
        birthdate = new Date(bd);
        //from https://www.w3schools.blog/c-check-if-string-contains-substring
        if(l4.find("@") != string::npos){
            email = new Email(l4);
            phone = new Phone(l5);
        }
        else{
            email = new Email(l5);
            phone = new Phone(l4);
        }
    
    fin.close();
}

bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
}

void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();
}

string Person::get_name(){
    string fullName = l_name + ", " + f_name;
    return fullName;
}
