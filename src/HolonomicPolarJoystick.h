#define JOY_Y_DEADBAND 20
#define JOY_X_DEADBAND 20

typedef struct
{
	float radians;
	float speed;
} PolarJoystick;

void getValues(PolarJoystick &joy, TVexJoysticks joy_x, TVexJoysticks joy_y) {
	byte x_val = vexRT[joy_x];
	byte y_val = vexRT[joy_y];
	if((abs(x_val) < 20) && (abs(y_val) < 20)) {
		joy.radians = 0;
		joy.speed = 0;
	}
	else {
		joy.radians = (PI/2)-atan2(y_val,x_val);
		float speed = sqrt((abs(y_val) * abs(y_val)) + (abs(x_val) * abs(x_val)));
		speed = speed/127;
		if(speed > 1) speed = 1;
		joy.speed = speed;
	}
}
