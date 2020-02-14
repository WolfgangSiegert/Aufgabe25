#pragma once
#include <iostream>
#include <regex>

/**
 * Klasse mit algemeinen Helfer Funktionen fuer:
 * - Pruefung von User-Input
 */
class CUtil
{   
    public:
        /**
         * Funktion fragt aus der Console User-Input ab und prueft, ob dieser einem Double-Wert (nur Format <Ziffern 0-9><Trennzeichen '.'><Ziffern 0-9>) entspricht.
         * Verwendung von Regular Expression: "-?[0-9]+|-?[0-9]+.?[0-9]+"
         * 
         * @returns double --> Double User-Input 
         */
		double checkDoubleInput();
                /**
         * Funktion fragt aus der Console User-Input ab und prueft, ob dieser einem Integer-Wert (nur Ziffern 0-9) entspricht.
         * Verwendung von Regular Expression: "-?[0-9]+"
         * 
         * @returns integer --> Integer Ganzzahl User-Input 
         */
		int checkIntegerInput();
};
