#include <cmath>
#include <limits>
#include "Person.hpp"
#include "CUtil.hpp"

Person::Person(double paramBodyWeight)
{
    bodyWeight = paramBodyWeight;
    referenceAppelation = "Eine Person";
    totalAlcConsumed = 0.0;
}

Person::Person(double paramBodyWeight,std::string paramRefAppelation)
{
    bodyWeight = paramBodyWeight;
    if (paramRefAppelation.empty()){
		referenceAppelation = "Eine Person";
	} else {
		referenceAppelation = paramRefAppelation;
	}
    totalAlcConsumed = 0.0;
}

void Person::consumedBevs(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc){
    unsigned int inputchoiceBev(1); // Variable fuer Menueausahl der konsumierten Getraenke
    unsigned int inputBevVolumeML; // Variable fuer Zwischenspeicherung User-Input der konsumierten Menge des ausgewaehlten Getraenks 
    CUtil CUtilitiesLOC;
    
    for(auto var : paramBevs) //Initialisierung des Vektors fuer die konsumierten Mengen nach Size der moeglichen Auswahl jeweils mit Startwert 0.0
    {
        qtyPerBev.push_back(0.0);
    }
    
    std::cout << "\n+++" << std::endl;
    std::cout << "Welche Getraenke wurden konsumiert?.\n" << std::endl;
    
    int choiceIndex = 1; //Auswahlindex des Getraenkemenues startet bei "1"
    for (size_t i = 0; i < paramBevs.size(); i++){ //Ausgabeloop fuer Auswahlmenue der moeglichen Getraenke in ParamBevs. Auswahlindex starte bei "1"
        std::cout << " * " << choiceIndex << "\t=> " << paramBevs.at(i) << " mit " <<  paramBevsAlc.at(i) << " % Alkoholgehalt." << std::endl;
        choiceIndex++;
    }
    
    std::cout << "--- oder ---" << std::endl;
    std::cout << " * Eingabe beenden => 0" << std::endl;

    while (inputchoiceBev != 0){ // User-Input Getraenkewahl und konsumierte Menge 
        std::cout << "\nGeben Sie bitte die Ziffer eines Getraenks ein und bestaetigen Sie mit Enter." << std::endl;
        std::cout << "--> Eingabe Nummer des Getraenks! ---ODER--- Eingabe beenden mit '0': ";
        //User-Input
        inputchoiceBev = CUtilitiesLOC.checkIntegerInput();	//Eingabe und Eingabe pruefen
     	if(inputchoiceBev < 0 || inputchoiceBev > paramBevs.size()){
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        		throw std::invalid_argument( "Geben Sie eine Ziffer aus dem Menue der Getraenke oder '0' ein.");
        }
        if (inputchoiceBev != 0){
            std::cout << "--> Konsumierte Menge in ml: ";
            //User-Input
            inputBevVolumeML = CUtilitiesLOC.checkIntegerInput(); //Eingabe und Eingabe pruefen
			if(inputBevVolumeML > 1e7){
				throw std::out_of_range("Die eingegebene Menge ist zu gross.");
			}
			inputBevVolumeML = std::abs(inputBevVolumeML);//negativen Input ggf. positiv setzen
			//Input korrekt           
            qtyPerBev.at(inputchoiceBev-1) += inputBevVolumeML; //User-Input konsumierte Menge je Getraenk am entsprechenden Index des Vektors qtyPerBev aufsummieren
				std::cout << "\nMoechten Sie weitere Getraenke eingeben?" << std::endl;        
        } else {
            std::cout << "\n--- Eingabe beendet.---\n" << std::endl;
        }
    }    
}

void Person::printOutCosumedBevsQty(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc){
    std::cout << "+++" << std::endl;
	std::cout << "Berechnung der Blutalkoholkonzentration fuer:" << std::endl;
	std::cout << referenceAppelation << " mit " <<  getBodyWeight() << " kg Koerpergewicht" << std::endl;
	std::cout << "nach dem Konsum von:\n" << std::endl;
    for (size_t i = 0; i < paramBevsAlc.size(); i++){ // Loop fuer Ausgabe der Konsumierten Getraenke und Mengen auf der Konsole
        if (qtyPerBev.at(i) > 0){
            std::cout <<" * "<< qtyPerBev.at(i) << " ml "<< paramBevs.at(i) <<  " mit " << paramBevsAlc.at(i) << " % Alkoholgehalt" << std::endl;
		}
	}
}

double Person::calculateTotalAlcConsumed(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc){
    totalAlcConsumed = 0.0;
    for (size_t i = 0; i < paramBevsAlc.size(); i++){ // Loop fuer Aufrechnung des konsumierten Alkoholvolumens insgesamt
        if (qtyPerBev.at(i) > 0){
            totalAlcConsumed += (qtyPerBev.at(i) * (paramBevsAlc.at(i)/100))* 0.8; //Aufrechnung des konsumierten Alkoholvoluens insgesamt fuer alle Getraenke
        }
    }
    return totalAlcConsumed;
}
   
void Person::printResultBloodAlc(double paramResult){    
    std::cout <<  "\nBlutalkoholkonzentration etwa: " << std::setprecision(2) << paramResult << " Promille" << std::endl;
    std::cout << "============================================" << std::endl;
}

double Person::getBodyWeight(){
    return bodyWeight;
}
