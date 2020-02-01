#pragma once
/* #include <string>
#include <vector>
#include "iostream"
#include <cmath>
#include <string>
#include <streambuf>
#include <fstream>
#include <iomanip> */
#include "Person.hpp"

class Child : public Person
{   
    using Person::Person;
    public:
            /**
         * Errechnet aus Person::qtyPerBevs und den Parametern das insgesamt konsumierte Alkoholvolumen und speichert dieses in Person::totalAlcConsumed
         * Gibt konsumierte Getraenke mit Mengen auf der Konsole aus und
         * Berechnet als Rueckgabewert den Blutalkoholwert aus Person::getBodyWeight(), Person::totalAlcConsumed und jeweiligem Koeffizienten der Unterklasse Female,Male oder Child
         * 
         * @pre Person::consumedBevs() wurde ausgefuehrt
         * @param paramBevs vector<string> Vektor, der Namen der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBevsAlc
         * @param paramBevsAlc vector<double> Vektor, der Alkoholvolumina der verfuegbaren Getraenke enthaelt -->Werte bei Index synchron zu paramBvs
         * @returns double -->errechneter Blutalkoholwert insgesamt fuer Person und durch Person::consumedBevs eingegbene Mengen 
         */
        double calculateBloodAlc(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc) override;
};
