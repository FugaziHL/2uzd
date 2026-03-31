
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

        switch (choice) {

        case 1: { // Pridėti mokinį
            if (studentCount >= MAX_STUDENTS) {
                cout << "Maksimalus mokiniu skaicius pasiektas.\n";
                break;
            }
            cout << "Iveskite mokinio varda: ";
            cin >> names[studentCount];

            cout << "Kiek pazymiu jis turi (0-10)? ";
            int count;
            cin >> count;

            if (count < 0) count = 0;
            if (count > MAX_GRADES) count = MAX_GRADES;

            gradeCount[studentCount] = count;

            for (int i = 0; i < count; i++) {
                cout << "Iveskite pazymi #" << (i + 1) << ": ";
                cin >> grades[studentCount][i];
            }

            studentCount++;
            cout << "Mokinys pridetas.\n";
            break;
        }

        case 2: { // Peržiūrėti visus mokinius
            if (studentCount == 0) {
                cout << "Sarasas tuscias.\n";
                break;
            }
            cout << "\nMokiniu sarasas:\n";
            for (int i = 0; i < studentCount; i++) {
                cout << i + 1 << ". " << names[i] << " (" << gradeCount[i] << " pazymiai)\n";
            }
            break;
        }

        case 3: { // Peržiūrėti konkretų mokinį
            cout << "Iveskite mokinio numeri: ";
            int idx;
            cin >> idx;
            idx--;

            if (idx < 0 || idx >= studentCount) {
                cout << "Tokio mokinio nera.\n";
                break;
            }

            cout << "Mokinys: " << names[idx] << "\nPazymiai: ";
            for (int i = 0; i < gradeCount[idx]; i++) {
                cout << grades[idx][i] << " ";
            }
            cout << "\n";
            break;
        }

        case 4: { // Atnaujinti pažymį
            cout << "Iveskite mokinio numeri: ";
            int idx;
            cin >> idx;
            idx--;

            if (idx < 0 || idx >= studentCount) {
                cout << "Tokio mokinio nera.\n";
                break;
            }

            cout << "Kuri pazymi norite pakeisti (1-" << gradeCount[idx] << ")? ";
            int g;
            cin >> g;
            g--;

            if (g < 0 || g >= gradeCount[idx]) {
                cout << "Tokio pazymio nera.\n";
                break;
            }

            cout << "Iveskite nauja pazymi: ";
            cin >> grades[idx][g];

            cout << "Pazymys atnaujintas.\n";
            break;
        }

        case 5: { // Pašalinti mokinį
            cout << "Iveskite pasalinamo mokinio numeri: ";
            int idx;
            cin >> idx;
            idx--;

            if (idx < 0 || idx >= studentCount) {
                cout << "Tokio mokinio nera.\n";
                break;
            }

            // Perkelti visus likusius studentus "aukštyn"
            for (int i = idx; i < studentCount - 1; i++) {
                names[i] = names[i + 1];
                gradeCount[i] = gradeCount[i + 1];
                for (int j = 0; j < MAX_GRADES; j++) {
                    grades[i][j] = grades[i + 1][j];
                }
            }

            studentCount--;
            cout << "Mokinys pasalintas.\n";
            break;
        }

        case 0:
            cout << "Programa baigiama.\n";
            break;

        default:
            cout << "Neteisingas pasirinkimas.\n";
        }

    } while (choice != 0);

    return 0;
}

