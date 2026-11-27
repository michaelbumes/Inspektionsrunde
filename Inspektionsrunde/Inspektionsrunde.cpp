#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Bereinigter Nachbereitungsstand: Konstruktoren, Getter, Fahren und Laden.
// Kein Mitschnitt des letzten Livecodes.

class Sensor {
private:
    int anzahl = 0;
    int maximum = 0;
public:
    void erfassen(int messwert);
    int getAnzahl() const;
    int getMaximum() const;
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

class Roboter {
private:
    string name;
    int position;
    int akku;
    Sensor sensor;
public:
    Roboter(string startName, int startAkku);
    Roboter(string startName);
    string getName() const;
    int getPosition() const;
    int getAkku() const;
    void fahren();
    void zurueckfahren();
    void laden();
    void pruefe(Messpunkt& punkt, int wert);
    int getAnzahlMessungen() const;
    int getHoechsterMesswert() const;
};

int main() {
    Roboter roboter1("Robert", 40);

    vector<Messpunkt> runde;
    runde.push_back(Messpunkt("Pumpe", 80));
    runde.push_back(Messpunkt("Motor", 90));

    // Der Roboter liefert die Messwerte der Runde als Liste.
    vector<int> werte = {75, 92};

    for (int i = 0; i < runde.size(); i++) {
        roboter1.fahren();
        roboter1.pruefe(runde.at(i), werte.at(i));
    }

    // Bericht am Ende der Runde, direkt aus der Liste.
    for (int i = 0; i < runde.size(); i++) {
        cout << runde.at(i).getName() << ": " << runde.at(i).getMesswert();
        if (runde.at(i).istZuHoch()) {
            cout << " Warnung";
        }
        cout << "\n";
    }

    // Nach der Runde zur Ladestation zurueckkehren.
    roboter1.zurueckfahren();
    roboter1.zurueckfahren();
    roboter1.laden();
    cout << roboter1.getName() << ": Position " << roboter1.getPosition()
         << ", Akku " << roboter1.getAkku() << "\n";
    cout << roboter1.getName() << ": " << roboter1.getAnzahlMessungen()
         << " Messungen, hoechster Wert " << roboter1.getHoechsterMesswert() << "\n";
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

void Roboter::pruefe(Messpunkt& punkt, int wert) {
    sensor.erfassen(wert);
    punkt.messen(wert);
}

int Roboter::getAnzahlMessungen() const {
    return sensor.getAnzahl();
}

int Roboter::getHoechsterMesswert() const {
    return sensor.getMaximum();
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
    messwert = wert;
}

bool Messpunkt::istZuHoch() const {
    return messwert > grenzwert;
}

void Sensor::erfassen(int messwert) {
    if (anzahl == 0 || messwert > maximum) {
        maximum = messwert;
    }
    anzahl++;
}

int Sensor::getAnzahl() const {
    return anzahl;
}

int Sensor::getMaximum() const {
    return maximum;
}
