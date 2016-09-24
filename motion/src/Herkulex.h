#ifndef Herkulex_h
#define Herkulex_h

const int DATA_SIZE	  =   30;		// buffer for input data
const int DATA_MOVE  =	 50;		// max 50 servos <---- change this for more servos!
const int TIME_OUT   =     5;        //timeout serial communication

// SERVO HERKULEX COMMAND - See Manual p40
const int HEEPWRITE  =  0x01; 	//Rom write
const int HEEPREAD   =  0x02; 	//Rom read
const int HRAMWRITE	 =  0x03; 	//Ram write
const int HRAMREAD	 =  0x04; 	//Ram read
const int HIJOG		 =  0x05; 	//Write n servo with different timing
const int HSJOG		 =  0x06; 	//Write n servo with same time
const int HSTAT	 	 =  0x07; 	//Read error
const int HROLLBACK	 =  0x08; 	//Back to factory value
const int HREBOOT	 =  0x09; 	//Reboot

// SERVO HERKULEX ACK
const int ACK_EEPWRITE  =   0x41; 	//Rom write
const int ACK_EEPREAD   =   0x42; 	//Rom read
const int ACK_RAMWRITE	=   0x43; 	//Ram write
const int ACK_RAMREAD	=   0x44; 	//Ram read
const int ACK_IJOG		=   0x45; 	//Write n servo with different timing
const int ACK_SJOG		=   0x46; 	//Write n servo with same time
const int ACK_STAT	 	=   0x47; 	//Read error
const int ACK_ROLLBACK	=   0x48; 	//Back to factory value
const int ACK_REBOOT	=   0x49; 	//Reboot


// HERKULEX LED - See Manual p29
const int LED_GREEN =	 0x01;
const int LED_BLUE  =    0x02;
const int LED_CYAN  =    0x03;
const int LED_RED   = 	 0x04;
const int LED_GREEN2= 	 0x05;
const int LED_PINK  =    0x06;
const int LED_WHITE =    0x07;

// HERKULEX STATUS ERROR - See Manual p39
const int H_STATUS_OK				    = 0x00;
const int H_ERROR_INPUT_VOLTAGE 		= 0x01;
const int H_ERROR_POS_LIMIT			    = 0x02;
const int H_ERROR_TEMPERATURE_LIMIT	    = 0x04;
const int H_ERROR_INVALID_PKT			= 0x08;
const int H_ERROR_OVERLOAD			    = 0x10;
const int H_ERROR_DRIVER_FAULT  		= 0x20;
const int H_ERROR_EEPREG_DISTORT		= 0x40;

// HERKULEX Broadcast Servo ID
const int BROADCAST_ID = 0xFE;

class HerkulexClass {
public:
 
  void  initialize();
  int   status(int servoID);
  void  ACK(int valueACK);
  int   model();
  void  set_ID(int ID_Old, int ID_New);
  void  clearError(int servoID);

  void  torqueON(int servoID);
  void  torqueOFF(int servoID);

  void  moveAll(int servoID, int Goal, int iLed);
  void  moveSpeedAll(int servoID, int Goal, int iLed);
  void  moveAllAngle(int servoID, float angle, int iLed);
  void  actionAll(int pTime);
  void  addData(int GoalLSB, int GoalMSB, int set, int servoID);
  void  moveSpeedOne(int servoID, int Goal, int pTime, int iLed);
  void  moveOne(int servoID, int Goal, int pTime, int iLed);
  void  moveOneAngle(int servoID, float angle, int pTime, int iLed);

  int   getPosition(int servoID);
  float getAngle(int servoID);
  int   getSpeed(int servoID);

  void  reboot(int servoID);
  void  setLed(int servoID, int valueLed);

  void  writeRegistryRAM(int servoID, int address, int writeint);
  void  writeRegistryEEP(int servoID, int address, int writeint);


// private area
private:
  int  checksum1(int* data, int lenghtString);
  int  checksum2(int XOR);

  int port;

  int pSize;
  int pID;
  int cmd;
  int lenghtString;
  int ck1;
  int ck2;

  int conta;

  int XOR;
  int playTime;

  int data[DATA_SIZE];
  int dataEx[DATA_MOVE+8];
  int moveData[DATA_MOVE];

};

extern HerkulexClass Herkulex;

#endif // Herkulex_h
