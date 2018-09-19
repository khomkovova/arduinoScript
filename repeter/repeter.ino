int a;
String str = "";
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
//Serial.write("osdaf");


char ch[123];
}

void loop() {
  
//  Serial.write(Serial.read());
  // put your main code here, to run repeatedly:
//sleep(50);

a = Serial.read();
if((a != -1) & (a != 0)){
Serial.println(a);
}
}
