// connect to the serial port
// set the baud rate of the serial port
// read the serial port 
// send data to the serial port


//#ifndef _serialUSB_h_
//#define _serialUSB_h_

#include <iostream>
#include <fstream>
#include <SerialStream.h>
#include <stdlib.h>
#include <string>
#include <SerialPort.h>

using namespace LibSerial;

class serialUSB
{
	 public:
	   SerialStream serial_port ;
	   serialUSB(const char* const SERIAL_PORT_DEVICE ,int baudrate );   //constructor //const char* const is a constant pointer to a constant char 
	   void writeUSB(int* s,int array_length);
	  
};

