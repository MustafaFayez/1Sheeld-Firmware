/*

  Project:       1Sheeld Firmware 
  File:          ATmega Firmata.cpp

  Compiler:      avr-gcc 3.4.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "1sheelds_functions.h"

int main(void)
{ 
	initialization();
	catchTimeForSomeVariables();
	while (1)
	{		
		newMillis = millis();
		checkDigitalPinStatus();
		#ifdef IOS_VERSION
		checkDataAvailabilityInRx0Buffer(); 
		checkArduinoRx0BufferSpace();
		#endif // IOS_VERSION
		processDataFromApp();
		checkBluetoothResetResponse();
		checkAppConnection();
		sendDataToApp();
	}
}

