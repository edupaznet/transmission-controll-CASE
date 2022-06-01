//*********************************************************************************
// Pin declarations
//********************************************************************************
#define Neutral 12    // detect Neutral signal
#define Fwd 11       // detect Forward signal
#define Rev 10      // detect Reverse signal
#define M6 15          // M6 Solenoid
#define M5 17
#define M4 7
#define M3 6
#define M2 5
#define M1 4
#define wireC1 3      //  connect to terminal C1 of the shifter
#define wireB1 2      //  connect to terminal B1 of the shifter

//*******************************************************************************
// Global Variables
//*******************************************************************************

bool valorNeutral;
bool prevValorNeutral;    
bool valorFwd; 
bool valorRev; 
bool valorC1;
bool valorB1;
bool flag1;
bool flag2;
bool flag3;
bool flag4;
bool M6Ready = false; // flag for when M6 is let go
bool M6State = false; // for M6 is on or not.

unsigned long shifterMoveMillis;  // when the movement was made
unsigned long M6TurnedOnAt;  // when led was turned on
unsigned long turnOnDelay = 1000; // wait to turn on M6


//************************************************************  
