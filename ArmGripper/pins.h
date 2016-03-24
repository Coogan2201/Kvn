#define Joint_STEP_PIN          54 
#define Joint_DIR_PIN           55          //X
#define Joint_ENABLE_PIN        38

#define Base_STEP_PIN           26 
#define Base_DIR_PIN            28         //EX0
#define Base_ENABLE_PIN         24

#define YArm_STEP_PIN           60
#define YArm_DIR_PIN            61
#define YArm_ENABLE_PIN         56
#define YArm_MIN_PIN            14 

#define ZArm_STEP_PIN           46
#define ZArm_DIR_PIN            48
#define ZArm_ENABLE_PIN         62
#define ZArm_MIN_PIN            18


#define gripperPin 11         //gripper
#define wristPin 6            //wrist


//int xPinStatus;
int yPinStatus;
int zPinStatus;

float yPos;                   //arm plate
float zPos;                   //arm height
float jPos;                   // base position
float bPos;                   // joint position

byte incomingByte;
