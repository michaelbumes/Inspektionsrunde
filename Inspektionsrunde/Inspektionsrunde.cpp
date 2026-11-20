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

class Messpunkt {
private:
    string name;
    int grenzwert;
    int messwert;
public:
    Messpunkt(string startName, int startGrenzwert);
    string getName() const;
    int getGrenzwert() const;
    int getMesswert() const;
    void messen(int wert);
    bool istZuHoch() const;
};

int main() {
    // Vier Fahrten zu je 10: zwei Messstellen besuchen und zurueckkehren.
    Roboter roboter1("Robert", 40);
    Messpunkt pumpe("Pumpe", 80);
    Messpunkt motor("Motor", 90);

    // Position 1: Pumpe pruefen.
    roboter1.fahren();
    pumpe.messen(75);
    cout << pumpe.getName() << ": " << pumpe.getMesswert()
         << ", zu hoch: " << pumpe.istZuHoch() << "\n";

    // Position 2: Motor pruefen.
    roboter1.fahren();
    motor.messen(92);
    cout << motor.getName() << ": " << motor.getMesswert()
         << ", zu hoch: " << motor.istZuHoch() << "\n";

    // An derselben Station den Grenzfall pruefen.
    motor.messen(90);
    cout << "Motor genau an der Grenze: " << motor.istZuHoch() << "\n";
    cout << "Pumpe unveraendert: " << pumpe.getMesswert() << "\n";

    // Nach der Inspektionsrunde zur Ladestation zurueckkehren.
    roboter1.zurueckfahren();
    roboter1.zurueckfahren();
    roboter1.laden();
    cout << roboter1.getName() << ": Position " << roboter1.getPosition()
         << ", Akku " << roboter1.getAkku() << "\n";
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

Messpunkt::Messpunkt(string startName, int startGrenzwert) {
    name = startName;
    grenzwert = startGrenzwert;
    messwert = 0;
}

string Messpunkt::getName() const {
    return name;
}

int Messpunkt::getGrenzwert() const {
    return grenzwert;
}

int Messpunkt::getMesswert() const {
    return messwert;
}

void Messpunkt::messen(int wert) {
    // Hier den neuen Messwert speichern.
}

bool Messpunkt::istZuHoch() const {
    return false; // Hier den Grenzwert pruefen.
}
