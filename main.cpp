
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_STUDENTS = 100;
    const int MAX_GRADES = 10;

    string names[MAX_STUDENTS];            // Mokinų vardai
    int grades[MAX_STUDENTS][MAX_GRADES];  // Jų pažymiai
    int gradeCount[MAX_STUDENTS] = {0};    // Kiek pažymių turi kiekvienas mokinys
    int studentCount = 0;

    int choice;

    do {
        cout << "\n===== Meniu =====\n";
        cout << "1. Prideti mokini\n";
        cout << "2. Perziureti visus mokinius\n";
        cout << "3. Perziureti mokinio pazymius\n";
        cout << "4. Atnaujinti mokinio pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkite: ";
        cin >> choice;

    return 0;
}
