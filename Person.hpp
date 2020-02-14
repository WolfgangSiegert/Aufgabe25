#pragma once
#include <string>
#include <vector>
#include "iostream"
//#include <streambuf>
//#include <fstream>
#include <iomanip>

/**
 * Oberklasse für die abgeleiteteten Klassen Personentypen: Female, Male , Child
 */
class Person
{
public:
    std::vector<int> qtyPerBev;  /** Haelt die konsumierten Mengen der verfuegbaren Getraenke nach Ausfuerung consumedBevs*/
    double totalAlcConsumed;  /** Haelt das konsumierte Alkoholvolumen gesamt nach Ausfuerung consumedBevs und calculateBoodAlc*/

    Person(){};
    virtual ~Person(){}; //https://stackoverflow.com/questions/47702776/how-to-properly-delete-pointers-when-using-abstract-classes
    Person(double parambodyWeight);
	Person(double paramBodyWeight,std::string paramRefAppelation);
    /**
     * Holt den Wert des Koerpergewichtes des jeweiligen Personenobjektes
     * 
     * @returns double  private bodyweight des Objektes. diese Variable speichert das Koerpergewicht
     */
    double getBodyWeight();

    /**
     * Gbt das Ergebnis der Blutakoholberechnung in der Konsole aus.
     * 
     * @pre Person::calculatBloodAlc wurde ausgefuehrt
     * @param paramResult Ergebnis der Berechnung-->Blutalkoholwert als double
     */
    void printResultBloodAlc(double paramResult);

    /**
     * Ermoeglicht aus der Konsole die Eingabe konsumierter Getraenke mit jeweiligen Mengen:
     * Getraenke gemaess Parameter paramBevs--> dieser gibt auch die Size fuer Person::qtyPerBevs
     * Mengen werden in Person::qtyPerBev -->vektor<double> gehalten
     * 
     * @param paramBevs vector<string> Vektor, der Namen der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBevsAlc
     * @param paramBevsAlc vector<double> Vektor, der Alkoholvolumina der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBvs
     */
    void consumedBevs(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc);
    
    /**
     * Gibt konsumierte Getraenke mit Mengen aus Person::qtyPerBevs und den Parametern auf der Konsole aus
     * 
     * @pre Person::consumedBevs() wurde ausgefuehrt
     * @param paramBevs vector<string> Vektor, der Namen der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBevsAlc
     * @param paramBevsAlc vector<double> Vektor, der Alkoholvolumina der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBvs
     */ 
    void printOutCosumedBevsQty(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc);

    /**
     * Errechnet aus Person::qtyPerBevs und den Parametern das insgesamt konsumierte Alkoholvolumen und speichet dieses in Person::totalAlcConsumed
     * 
     * @pre Person::consumedBevs() wurde ausgefuehrt
     * @param paramBevs vector<string> Vektor, der Namen der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBevsAlc
     * @param paramBevsAlc vector<double> Vektor, der Alkoholvolumina der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBvs
     * @returns double -->errechnetes insgesamt konsumiertes Alkoholvolumen fuer Person und durch Person::consumedBevs eingegbene Mengen 
     */    
    double calculateTotalAlcConsumed(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc);
 
    /**
     * DEPRECATED
     * Errechnet aus Person::qtyPerBevs und den Parametern das insgesamt konsumierte Alkoholvolumen und speichet dieses in Person::totalAlcConsumed
     * Gibt konsumierte Getraenke mit Mengen auf der Konsole aus und
     * Berechnet als Rueckgabewert den Blutalkoholwert aus Person::getBodyWeight(), Person::totalAlcConsumed und jeweiligem Koeffizienten der Unterklasse Female,Male oder Child
     * 
     * @pre Person::consumedBevs() wurde ausgefuehrt
     * @param paramBevs vector<string> Vektor, der Namen der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBevsAlc
     * @param paramBevsAlc vector<double> Vektor, der Alkoholvolumina der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBvs
     * @returns double -->errechneter Blutalkoholwert insgesamt fuer Person und durch Person::consumedBevs eingegbene Mengen 
     *
	 *virtual double calculateBloodAlc(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc) = 0;
	 * 
	 * DEPRECATED
     */
    
    /**
     * Berechnet als Rueckgabewert den Blutalkoholwert aus Person::getBodyWeight(), Person::calculateTotalAlcConsumed und jeweiligem Koeffizienten der Unterklasse Female,Male oder Child
     * 
     * @pre Person::consumedBevs() wurde ausgefuehrt fuer @param
     * @pre Person::calculateTotalAlcConsumed() wurde ausgeführt fuer @param
     * @param paramTotalAlcConsumed double, gesamtes konsumiertes Alkoholvolumen
     * @returns double -->errechneter Blutalkoholwert insgesamt fuer Person und durch Person::consumedBevs eingegbene Mengen 
     */
    virtual double calculateBloodAlcShort(double paramTotalAlcConsumed) = 0;
private:
    double bodyWeight; /** Haelt Koerpergewicht der Person*/
    std::string referenceAppelation; /** Haelt Anrede der Personart*/    
    };

