#include "Female.hpp"

/**
 * DEPRECATED
double Female::calculateBloodAlc(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc){
    std::cout << "+++" << std::endl;
    std::cout << "Berechnung der Blutalkoholkonzentration fuer:" << std::endl;
    std::cout << "Eine Frau mit " <<  getBodyWeight() << " kg Koerpergewicht" << std::endl;
    std::cout << "nach dem Konsum von:\n" << std::endl;

    totalAlcConsumed = 0.0;
    for (size_t i = 0; i < paramBevsAlc.size(); i++){ // Loop fuer Ausgabe der Konsumierten Getraenke und Mengen auf der Konsole und Aufrechnung des konsumierten Alkoholvolumens insgesamt
        if (qtyPerBev.at(i) > 0){
            std::cout <<" * "<< qtyPerBev.at(i) << " ml "<< paramBevs.at(i) <<  " mit " << paramBevsAlc.at(i) << " % Alkoholgehalt" << std::endl;
            totalAlcConsumed += (qtyPerBev.at(i) * (paramBevsAlc.at(i)/100))* 0.8; //Aufrechnung des konsumierten Alkoholvoluens insgesamt fuer alle Getraenke
            // code Test mit 600ml Bier 60kg Frau 
        }
    }
    return totalAlcConsumed / (getBodyWeight() * 0.55);            
}
* DEPRECATED
*/

double Female::calculateBloodAlcShort(double paramTotalAlcConsumed){
 	return paramTotalAlcConsumed / (getBodyWeight() * 0.55);
}
