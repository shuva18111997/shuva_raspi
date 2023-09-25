/*

#######################################
           # All Keys #
#######################################
//HID.begin(HID_KEYBOARD);
USB_HID_MOUSE
USB_HID_KEYBOARD
USB_HID_JOYSTICK
USB_HID_KEYBOARD_MOUSE
USB_HID_KEYBOARD_MOUSE_JOYSTICK
USB_HID_KEYBOARD_JOYSTICK
######################################
//Keyboard.write(KEY_LEFT_GUI);
KEY_LEFT_CTRL
KEY_LEFT_SHIFT
KEY_LEFT_ALT
KEY_LEFT_GUI
KEY_RIGHT_CTRL
KEY_RIGHT_SHIFT
KEY_RIGHT_ALT
KEY_RIGHT_GUI
KEY_UP_ARROW
KEY_DOWN_ARROW
KEY_LEFT_ARROW
KEY_RIGHT_ARROW
KEY_BACKSPACE
KEY_TAB
KEY_RETURN 
KEY_ESC
KEY_INSERT 
KEY_DELETE 
KEY_PAGE_UP
KEY_PAGE_DOWN
KEY_HOME 
KEY_END
KEY_CAPS_LOCK
KEY_F1 
KEY_F2 
KEY_F3 
KEY_F4 
KEY_F5 
KEY_F6 
KEY_F7 
KEY_F8 
KEY_F9 
KEY_F10
KEY_F11
KEY_F12
MOUSE_LEFT 
MOUSE_MIDDLE 
MOUSE_RIGHT
MOUSE_ALL
*/
#include <USBComposite.h>

USBHID HID;
HIDKeyboard Keyboard(HID);

void setup() {
  HID.begin(HID_KEYBOARD);
  while (!USBComposite);
  Keyboard.begin();
  delay(3000);
  Keyboard.write(KEY_LEFT_GUI);
  delay(500);
  Keyboard.print("Dev-C++");
  delay(1500);
  Keyboard.println();
  delay(4500);
  Keyboard.press(KEY_RIGHT_CTRL);
  Keyboard.write('n');
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print("#include<stdio.h");
  Keyboard.write(KEY_RIGHT_ARROW);
  Keyboard.println();
  Keyboard.print("main(");
  Keyboard.write(KEY_RIGHT_ARROW);
  Keyboard.println();
  Keyboard.println("{");
  Keyboard.print("printf(\"Hi Shuva");
  Keyboard.write(KEY_RIGHT_ARROW);
  Keyboard.write(KEY_RIGHT_ARROW);
  Keyboard.print(";");
  Keyboard.write(KEY_F11);
  delay(1000);
  Keyboard.println("Auto_Typing_C");
}

void loop() {}
