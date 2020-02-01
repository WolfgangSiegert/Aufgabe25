#include "Female.hpp"

double Female::calculateBloodAlc(std::vector<std::string> paramBevs,std::vector<double> paramBevsAlc){
    std::cout << "+++" << std::endl;
    std::cout << "Berechnung der Blutalkoholkonzentration fuer:" << std::endl;
    std::cout << "Eine Frau mit " <<  getBodyWeight() << " kg Koerpergewicht" << std::endl;
    std::cout << "nach dem Konsum von:" << std::endl;
    std::cout << std::endl;
    totalAlcConsumed = 0.0;
    for (size_t i = 0; i < paramBevsAlc.size(); i++){
        if (qtyPerBev.at(i) > 0){
            std::cout <<" * "<< qtyPerBev.at(i) << " ml "<< paramBevs.at(i) <<  " mit " << paramBevsAlc.at(i) << " % Alkoholgehalt" << std::endl;
            totalAlcConsumed += (qtyPerBev.at(i) * (paramBevsAlc.at(i)/100))* 0.8; //Aufrechnung des konsumierten Alkoholvoluens insgesamt fuer alle Getraenke
            /* code Test mit 600ml Bier 60kg Frau */
        }
    }
    return totalAlcConsumed / (getBodyWeight() * 0.55);            
}
