/**
 * AOP WS2019/20 Pruefungsprojekt
 * 25 Blutalkoholkonzentrationsabschaetzer
 
Aehnlich wie bei der Aufgabe zur Klassenhierarchie bei den Fahrraedern soll hier eine Klassenhier-
archie erstellt werden, die es ermoeglicht, die Blutalkoholkonzentration nach der Widmark-Formel
abzuschaetzen. 
Fuer den Mann soll gelten:
mg /(mp · 0, 68)
Fuer die Frau soll gelten:
mg /(mp · 0, 55)
Fuer Kleinkinder soll gelten:
mg /(mp · 0, 75)
Wobei mp das Gewicht (Masse) der Person in Kilogramm ist (vor dem Trinken des Alkohols!). 
mg ist die Masse des Alkohols in Gramm.
Die Masse an Alkohol bestimmt sich durch die Multiplikation
des Volumenprozentanteils mit dem Volumen des alkoholischen Getraenkes multipliziert mit
0.8g/cm3.
Speichern Sie den Alkoholgehalt in Volumenprozent von verschiedenen Getraenken in ihrem
Programm und ermoeglichen dem Nutzer im Hauptprogramm auszuwaehlen, welche Getraenke er
getrunken hat. Nach Angabe der weiteren notwendigen Informationen soll das Programm ihm
dann seine Blutalkoholkonzentration ausgeben.
+++++++
Entwurf-->
Zwei konstante Vektoren halten jeweils Namen und Alkoholgehalt der auswaehlbaren Getraenkein den gleichen Indexen.
Ein dritter Vektor am Personenobjekt speichert wieder mit synchronem Index ggf. eingegbene konsumierte Mengen.
Eingabe,Verarbeitung, Ausgabe ueber Objektfunktionen
 
grober Programmablauf:
-Ausagbe--> fuer wenn soll der Blutalkoholwert berechnet werden

-Eingabe--> Frau=1, Mann=2, Kind=3
--> switch case fuer Instanzierung des ensprechenden Objektes der Unterklassen

-Ausgabe--> koerpergewicht in kg eingeben!

-Eingabe--> Koerpergewicht dann-->
-Objektinstanz mit Konstruktor(Koerpergewicht)

-Instanz.konsumierteGetraenke{-->Eingabe Getraenke und jeweils Menge in ml}
-Instanz.berechneBlutalkohol {--> Berechnung Alkoholmasse gesamt+Blutalkohol}
-Ausgabe konsumierte Getraennke und Menge und -->
-Resultat der Berechnung: Blutalkoholwert

#TODO: diverse Eingabefehler abfangen, keine getranke mit menge 0 ausgeben,ueberlauf result erstes mal checken.
#TODO: weiter Kapselung,Test

@author Wolfgang Siegert MIB19-II-BIN
@version 0.1 1/30/20
*/

//#include <vector>
//#include <iostream>
//#include <string>
//#include <streambuf>
//#include <fstream>
//#include <array>
#include <iomanip>
#include <limits>
#include "Female.hpp"
#include "Male.hpp"
#include "Child.hpp"

/**
 * Startet User-Input, die verarbeitende Logik und Output des Promillerechners
 */
void runCode();

void runCode(){
    int inputPersonChoice; // Variable fuer User-Input der Personenauswahl
    double inputPersonWeight; //Variable fuer User-Input des Koerpergewichts
    const std::vector<std::string> bevsNamesVector = {"Bier","Wein","Likoer","Sekt"}; //Variable haelt global die Namen der Getraenke synchron mit bevsAlcPerCentVector 
    const std::vector<double> bevsAlcPerCentVector = {5.0,14.0,22.2,12.4};            //Variable haelt global die Alkoholvolumenprozente der Getraenke synchron mit bevsNamesVector 
    //Personenmenue und Abfrage der Auswahl
    std::cout << "\nFuer welche Person wollen Sie den Blutalkoholwert berechnen?\n\n * Frau => 1 \n * Mann => 2\n * Kind => 3 " << std::endl;
    std::cout << "\nGeben Sie bitte eine Ziffer ein." << std::endl;
    std::cout << "--> Auswahl Person: ";
    std::cin >> inputPersonChoice;
    //Eingabe pruefen
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        throw std::invalid_argument( "Geben Sie eine Ziffer 1,2 oder 3 ein.");
    }
    if (inputPersonChoice > 0 && inputPersonChoice <= 3)
    {   //Abfrage des Koerpergewichtes
        std::cout << "\n+++" << std::endl;
        std::cout << "Geben Sie bitte das Koerpergewicht der Person (in kg) vor dem Trinken ein.\n--> Koerpergewicht: ";
        std::cin >> inputPersonWeight;
        switch (inputPersonChoice)
        {
        case 1:{
            /* Verarbeitung fuer Auswahl Frau */
            Female fem(inputPersonWeight); //Konstruktor Initialisierung konkrte Person mit Koerpergewicht
            fem.consumedBevs(bevsNamesVector,bevsAlcPerCentVector); //Eingabe der konsumierten Mengen
            double result = fem.calculateBloodAlc(bevsNamesVector,bevsAlcPerCentVector); //Berechnung Blutalkoholkonzentration, Summierung der Gesamtalkoholmenge und Ausgabe der konsumierten Mengen aus Konsole
            fem.printResultBloodAlc(result); //Ausgabe des Erbgebnisses Blutalkoholwert auf Konsole
            break;
            }
        case 2:{
            /* Verarbeitung fuer Auswahl Mann */
            Male male(inputPersonWeight); //Konstruktor Initialisierung konkrte Person mit Koerpergewicht
            male.consumedBevs(bevsNamesVector,bevsAlcPerCentVector); //Eingabe der konsumierten Mengen
            double result = male.calculateBloodAlc(bevsNamesVector,bevsAlcPerCentVector); //Berechnung Blutalkoholkonzentration, Summierung der Gesamtalkoholmenge und Ausgabe der konsumierten Mengen aus Konsole
            male.printResultBloodAlc(result); //Ausgabe des Erbgebnisses Blutalkoholwert auf Konsole
            break;
            }
        case 3:{
            /* Verarbeitung fuer Auswahl Kind */
            Child child(inputPersonWeight); //Konstruktor Initialisierung konkrte Person mit Koerpergewicht
            child.consumedBevs(bevsNamesVector,bevsAlcPerCentVector); //Eingabe der konsumierten Mengen
            double result = child.calculateBloodAlc(bevsNamesVector,bevsAlcPerCentVector); //Berechnung Blutalkoholkonzentration, Summierung der Gesamtalkoholmenge und Ausgabe der konsumierten Mengen aus Konsole 
            child.printResultBloodAlc(result); //Ausgabe des Erbgebnisses Blutalkoholwert auf Konsole
            break;
            }
        default:
            throw std::invalid_argument( "Eingabefehler!\nGeben Sie eine Ziffer 1,2 oder 3 ein.");
            break;
        }    
    } else {//#TODO error handling
        throw std::invalid_argument( "Geben Sie eine Ziffer 1,2 oder 3 ein.");
    }
}

int main() {
    char runAgainThenYchar ('y'); //Steuerung der Wiederholten Ausfuehrung des Programms ueber diese Variable
    std::cout << "\tBlutalkoholrechner 0.1" << std::endl;
	std::cout << "###########################################" << std::endl;	
    while (runAgainThenYchar == 'y') {	
        try{
            runCode(); //startet die vearbeitende Logik
        } /* end of Try */
        catch(std::invalid_argument&  invArgExcep){
            std::cerr << "\nFehler! Bitte geben Sie nur erlaubte Optionen ein.\n" << invArgExcep.what() << "\n";           
        }
        catch(std::out_of_range& outOfRangeExcep){
            std::cerr << "\nFehler! Der eingegebene Wert ist zu groß.\n";           
        }
        catch(std::exception& stdExcep){
            std::cerr << "\nunbekannter Fehler\n";
        }
        std::cout << "\nNoch ein Mal? Geben Sie 'y' ein: "; 
        std::cin >> runAgainThenYchar; //Bei Eingabe von klein "y" erneute Ausfuehrung , ansonsten Ende des Programms
    }
    return 0;
}
