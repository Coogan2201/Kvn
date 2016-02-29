#define X_STEP_PIN          54 
#define X_DIR_PIN           55
#define X_ENABLE_PIN        38
#define X_MIN_PIN           3

#define Y_STEP_PIN          60
#define Y_DIR_PIN           61
#define Y_ENABLE_PIN        56
#define Y_MIN_PIN           14 

#define Z1_STEP_PIN         46
#define Z1_DIR_PIN          48
#define Z1_ENABLE_PIN       62
#define Z_MIN_PIN           18

#define EX1_STEP_PIN        26
#define EX1_DIR_PIN         28
#define EX1_ENABLE_PIN      24

#define EX2_STEP_PIN        36
#define EX2_DIR_PIN         34
#define EX2_ENABLE_PIN      30

#define EthanolPump 6
#define WastePump 11
#define TrypsinPump 5
#define MediaPump 4
#define PBSPump 2


int mydata;
String mot;
String dis;
String dir;
String del;
float wellZHeight;
float wellVolume;
int xPinStatus;
int yPinStatus;
int zPinStatus;

float yPos;
float xPos;
float zPos;

int wellDown;


