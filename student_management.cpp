//Student management System
#include<iostream>
#include<fstream>
using namespace std;

//Introducing Class Student 
class Student{
    string name, rollno,address, search, branch, sem;
    fstream file;
    public:
    void addStudent();
    void searchStudent();
    void display();
    void courseDetails();

};

int main(){
    Student stu;
    char choice;
     do{ //to ensure the menu appears until you give choice 5
    cout<<"---------------------------"<<endl;
    cout<<"1- Add Student Record"<<endl;
    cout<<"2- View All Student Record"<<endl;
    cout<<"3- Search Student Record"<<endl;
    cout<<"4- Display Course details"<<endl;
    cout<<"5- Exit"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;

    switch(choice){
        case '1':
            cin.ignore();
            stu.addStudent();
        break;

        case '2': 
            cin.ignore();
            stu.display();
        break;

        case '3':
            cin.ignore();
            stu.searchStudent();
        break;

        case '4':
            cin.ignore();
            stu.courseDetails();
            break;

        case '5':
            return 0;
        break;

        default:
            cout<<"Invalid choice!"<<endl;
    }
} while(choice != '5');
return 0;
}

//Add student function:

void Student:: addStudent(){
    cout<<"Enter Student Roll Number : ";
    getline(cin,rollno);
    cout<<"Enter Student Name :";
    getline(cin,name);
    cout<<"Enter Student Address :";
    getline(cin,address);
    cout<<"Enter student Branch :";
    getline(cin,branch);
    cout<<"Enter student Semester :";
    getline(cin,sem);

    file.open("stuData.txt",ios :: out | ios :: app);
    file<<rollno<<";";
    file<<name<<";";
    file<<address<<";";
    file<<branch<<";";
    file<<sem<<endl;
    file.close();
    cout << "Student record added successfully!\n";

}

//Display function
void Student::display() {
    file.open("stuData.txt", ios::in);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(file, rollno, ';') &&
           getline(file, name, ';') &&
           getline(file, address, ';') &&
           getline(file, branch, ';') &&
           getline(file, sem, '\n')) {
        
        cout << "\n";
        cout << "Student Roll Number : " << rollno << endl;
        cout << "Student Name        : " << name << endl;
        cout << "Student Address     : " << address << endl;
        cout << "Student Branch      : " << branch << endl;
        cout << "Student Semester    : " << sem << endl;
    }

    file.close();
}

//Search For a Student

void Student::searchStudent() {
    bool found = false;
    cout << "Enter Student Roll Number : ";
    getline(cin, search);
    
    file.open("stuData.txt", ios::in);

    while (getline(file, rollno, ';') &&
           getline(file, name, ';') &&
           getline(file, address, ';') &&
           getline(file, branch, ';') &&
           getline(file, sem, '\n')) {
        
        if (rollno == search) {
            found = true;
            cout << endl;
            cout << "Student Roll Number : " << rollno << endl;
            cout << "Student Name        : " << name << endl;
            cout << "Student Address     : " << address << endl;
            cout << "Student Branch      : " << branch << endl;
            cout << "Student Semester    : " << sem << endl;
            break; // stop searching once found
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found!" << endl;
    }
}


//Course deatils of a student
void Student::courseDetails() {
    bool found = false;
    cout << "Enter student roll number : ";
    getline(cin, search);

    file.open("stuData.txt", ios::in);

    while (getline(file, rollno, ';') &&
           getline(file, name, ';') &&
           getline(file, address, ';') &&
           getline(file, branch, ';') &&
           getline(file, sem, '\n')) {
        
        if (rollno == search) {
            found = true;
            cout << endl;
            cout << "Student Roll Number : " << rollno << endl;
            cout << "Student Name        : " << name << endl;
            cout << "Student Branch      : " << branch << endl;
            cout << "Student Semester    : " << sem << endl;
            break; // stop searching after finding
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found!" << endl;
    }
}
