// motorMovement.h

#ifndef _MOTORMOVEMENT_h
#define _MOTORMOVEMENT_h



#define X_STEP_PIN          54 
#define X_DIR_PIN           55
#define X_ENABLE_PIN        38
#define X_MIN_PIN           3

#define Y_STEP_PIN          60
#define Y_DIR_PIN           61
#define Y_ENABLE_PIN        56
#define Y_MIN_PIN           14 

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN           18

#define EthanolPump 11
#define WastePump 6
#define TrypsinPump 5
#define MediaPump 4
#define PBSPump 2

class motorMovement
{
public:
	void move(char, char, float);
	void homeAxes();
	void changeMedia(int);
	void cellPassage(int);
	void relMover(int, int);
};
#endif

