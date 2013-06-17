
struct EEPromSensFunc {
  unsigned char TargetAdd [2] ;
  unsigned char TargetLine ;
  unsigned char Command ;
  unsigned char Data[6] ;
} ;

struct EEPromSensPin {
  struct EEPromSensFunc ShortMaster ;
  struct EEPromSensFunc LongMaster ;
  struct EEPromSensFunc ShortAuto ;
  struct EEPromSensFunc LongAuto ;
} ;

struct EEPromSensConf {
  unsigned char Config ;
  unsigned char Data ;
} ;

struct EEPromSens {
  struct EEPromSensPin Pin[6] ;
  unsigned char PAD [50] ;
  struct EEPromSensConf Config[6] ;
  unsigned char REPEAT_START ;
  unsigned char REPEAT_END ;
  unsigned char PAD2 [198] ;
} ;

struct EEPromTast {
  struct EEPromSensPin Pin[8] ;
  unsigned char PAD [20] ;
  struct EEPromSensConf Config[8] ;
  unsigned char REPEAT_START ;
  unsigned char REPEAT_END ;
  unsigned char PAD2 [164] ;
} ;

struct EEPromRelais {
  unsigned char RTFull[5] ;
  unsigned char PAD1[5] ;
  unsigned char RTShort[5] ;
  unsigned char PAD2[5] ;
  unsigned char UpDown[5] ;
} ;

struct EEPromBad {
  unsigned char Program[23][20] ;
  struct EEPromSensPin Pin ;
  unsigned char DelayTimer ;
} ;

struct EEPromLED {
  unsigned char Program[23][20] ;
} ;

struct EEPROM {
  unsigned char Magic[2];
  unsigned char BoardAdd[2] ;
  unsigned char BoardLine ;
  unsigned char BootAdd[2] ;
  unsigned char BootLine ;
  unsigned char BoardType ;
  unsigned char PAD ;
  union {
    struct EEPromSens Sensor ;
    struct EEPromTast Taster ;
    struct EEPromRelais Relais ;
    struct EEPromBad Bad ;
    struct EEPromLED LED ;
    unsigned char PAD[502]; 
  } Data ;
} ;

extern int MakeConfig (int Linie, int Knoten, struct EEPROM *EEprom) ;
extern int WriteConfig(struct EEPROM *EEprom) ;
extern void SendConfigByte (char Linie, unsigned short Knoten) ;
void SendConfig(struct EEPROM *EEprom, char Linie, unsigned short Knoten) ;
void SendFirmware(char Linie, unsigned short Knoten) ;
void SendFirmwareByte (char Linie, unsigned short Knoten,unsigned char *Response, char ResponseLen);
void ReadConfigByte (char Linie, USHORT Knoten, unsigned char Value) ;
void ReadConfig(char Linie, USHORT Knoten) ;
