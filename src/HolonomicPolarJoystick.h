#define JOY_Y_DEADBAND 20
#define JOY_X_DEADBAND 20

typedef struct
{
	float radians;
	float speed;
} PolarJoystick;

void getPolarJoy(float *radians, float *speed, TVexJoysticks joy_x = Ch2, TVexJoysticks joy_y = Ch1) {
	byte x_val = vexRT[joy_x];
	byte y_val = vexRT[joy_y];
	if((abs(x_val) < 20) && (abs(y_val) < 20)) {
		*radians = 0;
		*speed = 0;
	}
	else {
		*radians = (PI/2)-atan2(y_val,x_val);
		float *speed = sqrt((abs(y_val) * abs(y_val)) + (abs(x_val) * abs(x_val)));
		*speed = *speed/127;
		if(speed > 1) *speed = 1;
	}
}
