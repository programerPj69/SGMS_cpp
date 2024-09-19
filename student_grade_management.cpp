#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Student class
class Student {
private:
    string name;
    vector<float> grades;
    
public:
    Student(string studentName) {
        name = studentName;
    }

    // Function to add grades for a student
    void addGrade(float grade) {
        grades.push_back(grade);
    }

    // Function to calculate the average grade of the student
    float calculateAverage() {
        if (grades.empty()) return 0.0;
        
        float sum = 0;
        for (float grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    // Function to display student information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Grades: ";
        for (float grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
        cout << "Average Grade: " << calculateAverage() << endl;
    }

    // Function to get student's name
    string getName() {
        return name;
    }
};

// Function to display all students
void displayAllStudents(vector<Student>& students) {
    for (Student& student : students) {
        student.displayInfo();
        cout << "--------------------------" << endl;
    }
}

// Main function
int main() {
    vector<Student> students;
    int choice;
    
    do {
        cout << "\n--- Student Grade Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Grade for a Student" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter the student's name: ";
            cin.ignore();
            getline(cin, name);
            students.push_back(Student(name));
            cout << "Student added successfully!" << endl;

        } else if (choice == 2) {
            string name;
            float grade;
            bool found = false;
            
            cout << "Enter the student's name: ";
            cin.ignore();
            getline(cin, name);

            for (Student& student : students) {
                if (student.getName() == name) {
                    cout << "Enter the grade to add: ";
                    cin >> grade;
                    student.addGrade(grade);
                    cout << "Grade added successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found!" << endl;
            }

        } else if (choice == 3) {
            if (students.empty()) {
                cout << "No students to display." << endl;
            } else {
                displayAllStudents(students);
            }
        }
        
    } while (choice != 4);

    cout << "Exiting the program..." << endl;
    return 0;
}
