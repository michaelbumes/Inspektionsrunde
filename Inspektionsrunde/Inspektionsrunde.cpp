#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Bereinigter Nachbereitungsstand: Konstruktoren, Getter, Fahren und Laden.
// Kein Mitschnitt des letzten Livecodes.

class Roboter {
private:
    string name;
    int position;
    int akku;
public:
    Roboter(string startName, int startAkku);
    Roboter(string startName);
    string getName() const;
    int getPosition() const;
    int getAkku() const;
    void fahren();
    void zurueckfahren();
    void laden();
};

int main() {
    vector<int> messwerte = {75, 80, 92};
    messwerte.push_back(64);
    for (int i = 0; i < messwerte.size(); i++) {
        cout << "Messung " << i + 1 << ": " << messwerte.at(i) << "\n";
    }

    Roboter roboter1("Robert", 20);
    Roboter roboter2("Nova");

    roboter1.fahren();
    roboter1.laden();
    cout << "Robert: Position " << roboter1.getPosition()
         << ", Akku " << roboter1.getAkku() << "\n";

    roboter1.zurueckfahren();
    roboter1.laden();
    cout << "Robert: Position " << roboter1.getPosition()
         << ", Akku " << roboter1.getAkku() << "\n";
    cout << roboter2.getName() << ": Position " << roboter2.getPosition()
         << ", Akku " << roboter2.getAkku() << "\n";
    return 0;
}

Roboter::Roboter(string startName, int startAkku) {
    name = startName;
    position = 0;
    if (startAkku >= 0 && startAkku <= 100) {
        akku = startAkku;
    } else {
        akku = 0;
    }
}

Roboter::Roboter(string startName) {
    name = startName;
    position = 0;
    akku = 100;
}

string Roboter::getName() const {
    return name;
}
int Roboter::getPosition() const {
    return position;
}
int Roboter::getAkku() const {
    return akku;
}

void Roboter::fahren() {
    if (position >= 3) {
        cout << name << " bleibt stehen: Endposition erreicht.\n";
    }
    else if (akku < 10) {
        cout << name << " bleibt stehen: Akku reicht nicht.\n";
    }
    else {
        position = position + 1;
        akku = akku - 10;
        cout << name << " faehrt zu Position " << position << ".\n";
    }
}

void Roboter::zurueckfahren() {
    if (position <= 0) {
        cout << name << " bleibt stehen: Anfangsposition erreicht.\n";
    }
    else if (akku < 10) {
        cout << name << " bleibt stehen: Akku reicht nicht.\n";
    }
    else {
        position = position - 1;
        akku = akku - 10;
        cout << name << " faehrt zurueck zu Position " << position << ".\n";
    }
}

void Roboter::laden() {
    if (position == 0) {
        akku = 100;
    }
}
