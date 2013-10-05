#define maxMotorSpeed 127
#define numberOfMotors  4

//**-----------------------SUPPORT FUNCTIONS-----------------------------------**//

float FindMaxFloat(float a, float b,  float c = (0), float d = (0), float e = (0),
	  		float f = (0), float g = (0), float h = (0), float i = (0), float j = (0))
{
	float values[] = {a,b,c,d,e,f,g,h,i,j};
	float maxValue = 0;
	for(int z = 0; z < 9; z++) {
		if(abs(values[z]) > maxValue) maxValue = abs(values[z]);
	}
	return maxValue;
}





//**-----------------------MAIN FUNCTIONS------------------------------------**//

void HolonomicRadianOutput(float radians, float speed = 1, byte rotation = 0)
{
	// Please refer to README.txt for a full explanation of the formulas used.
	float frontLeftOutput 	= -maxMotorSpeed * cos(PI/4 - radians);
	float frontRightOutput 	=  maxMotorSpeed * cos(PI/4 + radians);
	float rearRightOutput 	=  maxMotorSpeed * cos(PI/4 - radians);
	float rearLeftOutput		= -maxMotorSpeed * cos(PI/4 + radians);

	frontLeftOutput += rotation;
	frontRightOutput += rotation;
	rearRightOutput += rotation;
	rearLeftOutput += rotation;


	float maxOutput = FindMaxFloat(frontLeftOutput, frontRightOutput, rearRightOutput, rearLeftOutput);
	// The goal is to rescale all values to -127<=out<=127. See README.txt for algebraic explanation.
	speed /= (maxMotorSpeed / maxOutput);


	frontLeftOutput *= speed;
	frontRightOutput *= speed;
	rearLeftOutput *= speed;
	rearRightOutput *= speed;

	motor[frontLeft] = (byte)frontLeftOutput;
	motor[frontRight] = (byte)frontRightOutput;
	motor[rearLeft] = (byte)rearLeftOutput;
	motor[rearRight] = (byte)rearRightOutput;
}

float HolonomicGetJoystick(TVexJoysticks joy_x, TVexJoysticks joy_y)
{

