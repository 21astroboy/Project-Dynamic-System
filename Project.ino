int MAXLVL = 255;

float kp = 3;
float ki = 0.0001;
float kd = 0.00001;
int des= 0;
int sens = 0;
int err = 0;
int errLast = 0;
float integ;
float output;
float dt;
float dif;



void setup() {
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop() {

des = analogRead(A0);
sens = analogRead(A1);

des = map(des, 0, 1023, 330, 530);

err = des - sens;

integ = integ + err;

dt = 0.005;


dif = (err-errLast)/dt;
errLast = err;

output = kp*err + ki*integ + kd*dif;

if (output < 0) output = 0;
if (output > 255) output = 255;

analogWrite(8,output);
analogWrite(9,0);
analogWrite(10, MAXLVL - output);
analogWrite(11,0);
Serial.print(des);
Serial.print(" ");
Serial.println(sens);
}
