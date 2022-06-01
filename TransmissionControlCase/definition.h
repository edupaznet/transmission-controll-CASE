//*********************************************************************************
// Pin declarations
//********************************************************************************
#define Neutral 12    // detect Neutral signal
#define Fwd 11       // detect Forward signal
#define Rev 10      // detect Reverse signal
#define M6 15          // 
#define M5 17
#define M4 7
#define M3 6
#define M2 5
#define M1 4
#define wireC1 3
#define wireB1 2

//*****************************************************
// Global Variables
//*****************************************************

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
bool M6Ready = false; // flag for when button is let go
bool M6State = false; // for M6 is on or not.

unsigned long buttonPushedMillis;  // when button was released
unsigned long M6TurnedOnAt;  // when led was turned on
unsigned long turnOnDelay = 1000; // wait to turn on M6


//************************************************************  
