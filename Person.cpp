#include "Person.hpp"

Person::Person(double paramBodyWeight)
{
    bodyWeight = paramBodyWeight;
    totalAlcConsumed = 0.0;
}

void Person::consumedBevs(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc){
    int inputchoiceBev(1); // Variable fuer Menueausahl der konsumierten Getraenke
    int inputBevVolumeML; // Variable fuer Zwischenspeicherung User-Input der konsumierten Menge des ausgewaehlten Getraenks 
    
    for(auto var : paramBevs) //Initialisierung des Vektors fuer die konsumierten Mengen nach Size der moeglichen Auswahl jeweils mit Startwert 0.0
    {
        qtyPerBev.push_back(0.0);
    }
    
    std::cout << "\n+++" << std::endl;
    std::cout << "Welche Getraenke wurden konsumiert? \nWaehlen Sie aus und geben Sie jeweils die Menge in Milliliter (ml) an.\n" << std::endl;
    
    int choiceIndex = 1; //Auswahlindex des Getraenkemenues startet bei "1"
    for (size_t i = 0; i < paramBevs.size(); i++){ //Ausgabeloop fuer Auswahlmenue der moeglichen Getraenke in ParamBevs. Auswahlindex starte bei "1"
        std::cout << " * " << choiceIndex << "\t=> " << paramBevs.at(i) << " mit " <<  paramBevsAlc.at(i) << " % Alkoholgehalt." << std::endl;
        choiceIndex++;
    }
    
    std::cout << "--- oder ---" << std::endl;
    std::cout << " * Eingabe beenden => 0" << std::endl;

    while (inputchoiceBev != 0){ // User-nput Getraenkewahl und konsumierte Menge 
        std::cout << "\nGeben Sie bitte eine Ziffer ein." << std::endl;
        std::cout << "--> Auswahl Getraenk! ---ODER--- Eingabe beenden mit '0': ";
        std::cin >> inputchoiceBev; 
        if (inputchoiceBev != 0){
            std::cout << "--> Konsumierte Menge in ml: ";
            std::cin >> inputBevVolumeML;
            qtyPerBev.at(inputchoiceBev-1) += inputBevVolumeML; //User-Input konsumierte Menge je Getraenk am entsprechenden Index des Vektors qtyPerBev aufsummieren
        } else {
            std::cout << "\n--- Eingabe beendet.---\n" << std::endl;
        }
    }    
}

void Person::printResultBloodAlc(double paramResult){    
    std::cout <<  "\nBlutalkoholkonzentration etwa: " << std::setprecision(2) << paramResult << " Promille" << std::endl;
    std::cout << "============================================" << std::endl;
}

double Person::getBodyWeight(){
    return bodyWeight;
}