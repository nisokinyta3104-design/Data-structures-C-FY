#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Course
{
    string courseName;
    Course* next;
};

struct Student
{
    int rollNumber;
    string name;
    Course* courseHead;
    Student* next;
    Student* hashNext;
};

Student* head = NULL;
const int SIZE = 20;
Student* hashTable[SIZE] = {NULL};

int hashFunction(int roll)
{
    return roll % SIZE;
}

void registerStudent()
{
    Student* s = new Student;

    cout << "ENTER ROLL NUMBER: ";
    cin >> s->rollNumber;

    if (s->rollNumber < 0)
    {
        cout << "Roll number cannot be negative.\n";
        delete s;
        return;
    }

    int index = hashFunction(s->rollNumber);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNumber == s->rollNumber)
        {
            cout << "ROLL NUMBER ALREADY EXISTS!\n";
            delete s;
            return;
        }
        temp = temp->hashNext;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, s->name);

    s->courseHead = NULL;

    // Insert into Linked List
    s->next = head;
    head = s;

    // Insert into Hash Table using Chaining
    s->hashNext = hashTable[index];
    hashTable[index] = s;

    cout << "Student registered successfully!\n";
}

void updateStudent()
{
    int roll;

    cout << "Enter Roll Number to update: ";
    cin >> roll;

    if (roll < 0)
    {
        cout << "Invalid Roll Number.\n";
        return;
    }

    int index = hashFunction(roll);
    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNumber == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Current Name: " << temp->name << endl;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter New Student Name: ";
            getline(cin, temp->name);

            cout << "Student information updated successfully!\n";
            return;
        }

        temp = temp->hashNext;
    }

    cout << "Student not found.\n";
}
void enrollCourse()
{
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    if (roll < 0)
    {
        cout << "Invalid Roll Number.\n";
        return;
    }

    int index = hashFunction(roll);
    Student* temp = hashTable[index];

    while (temp != NULL && temp->rollNumber != roll)
    {
        temp = temp->hashNext;
    }

    if (temp == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string cname;
    cout << "Enter Course Name: ";
    getline(cin, cname);

    Course* c = temp->courseHead;

    while (c != NULL)
    {
        if (c->courseName == cname)
        {
            cout << "Student is already enrolled in this course.\n";
            return;
        }
        c = c->next;
    }

    Course* newCourse = new Course;
    newCourse->courseName = cname;

    newCourse->next = temp->courseHead;
    temp->courseHead = newCourse;

    cout << "Course enrolled successfully!\n";
}

void withdrawCourse()
{
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    if (roll < 0)
    {
        cout << "Invalid Roll Number.\n";
        return;
    }

    int index = hashFunction(roll);
    Student* temp = hashTable[index];

    while (temp != NULL && temp->rollNumber != roll)
    {
        temp = temp->hashNext;
    }

    if (temp == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string cname;
    cout << "Enter Course Name to withdraw: ";
    getline(cin, cname);

    Course* c = temp->courseHead;
    Course* prev = NULL;

    while (c != NULL && c->courseName != cname)
    {
        prev = c;
        c = c->next;
    }

    if (c == NULL)
    {
        cout << "Course enrollment not found.\n";
        return;
    }

    if (prev == NULL)
    {
        temp->courseHead = c->next;
    }
    else
    {
        prev->next = c->next;
    }

    delete c;

    cout << "Course withdrawn successfully!\n";
}

void removeStudent()
{
    int roll;

    cout << "Enter Roll Number to remove: ";
    cin >> roll;

    if (roll < 0)
    {
        cout << "Invalid Roll Number.\n";
        return;
    }

    int index = hashFunction(roll);

    Student* temp = hashTable[index];
    Student* prev = NULL;

    while (temp != NULL && temp->rollNumber != roll)
    {
        prev = temp;
        temp = temp->hashNext;
    }

    if (temp == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    // Remove from Hash Table
    if (prev == NULL)
    {
        hashTable[index] = temp->hashNext;
    }
    else
    {
        prev->hashNext = temp->hashNext;
    }

    // Remove from Linked List
    if (head == temp)
    {
        head = temp->next;
    }
    else
    {
        Student* current = head;

        while (current != NULL && current->next != temp)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            current->next = temp->next;
        }
    }

    // Delete all course enrollments
    Course* c = temp->courseHead;

    while (c != NULL)
    {
        Course* del = c;
        c = c->next;
        delete del;
    }

    delete temp;

    cout << "Student record removed successfully!\n";
}

void displayStudents()
{
    Student* temp = head;

    if (temp == NULL)
    {
        cout << "No student records available.\n";
        return;
    }

    cout << "\n---- All Student Records ----\n";

    while (temp != NULL)
    {
        cout << "\nRoll Number: " << temp->rollNumber << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Enrolled Courses: ";

        Course* c = temp->courseHead;

        if (c == NULL)
        {
            cout << "No courses enrolled.";
        }

        while (c != NULL)
        {
            cout << c->courseName;

            if (c->next != NULL)
                cout << ", ";

            c = c->next;
        }

        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- UNIVERSITY STUDENT REGISTRATION & COURSE ENROLLMENT SYSTEM ---\n";
        cout << "1. REGISTER STUDENT\n";
        cout << "2. UPDATE STUDENT INFORMATION\n";
        cout << "3. ENROLL STUDENT IN COURSE\n";
        cout << "4. WITHDRAW STUDENT FROM COURSE\n";
        cout << "5. REMOVE STUDENT RECORD\n";
        cout << "6. DISPLAY ALL STUDENTS\n";
        cout << "7. EXIT\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerStudent();
                break;

            case 2:
                updateStudent();
                break;

            case 3:
                enrollCourse();
                break;

            case 4:
                withdrawCourse();
                break;

            case 5:
                removeStudent();
                break;

            case 6:
                displayStudents();
                break;

            case 7:
                cout << "Exiting program. Thank You!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
