1.	Check the smb.conf, apache2.conf, php.ini files is available or not.
2.	Check the "Programming" Folder is available or not in "home/pi/Documents".
3.	Then Copy Arduino Folder and install Arduino
4.	Then Copy the "ngrok" and first authenticate it then run. Link:- https://www.dexterindustries.com/howto/access-your-raspberry-pi-from-outside-your-home-or-local-network/
5.	The set the clock format ==> %d/%b/%y %a %I:%M%p
6.	Enable SPI & I2C from Raspi-config to use TFT_Display of Raspberry PI.
7.  Then copy this commands and run in terminal.
8.  Please check the Remote Desktop is off only SSH enable so the "thinclient_driver" is not present in desktop.
9. If Raspberry Pi can't Upgrade ==> https://pimylifeup.com/raspbian-repository-mirror/
10. Then download the setup from github using

git clone https://github.com/shuva18111997/shuva_raspi

cp -r /home/pi/shuva_raspi/* /home/pi/Documents/
sudo rm -r /home/pi/shuva_raspi

just run the file using this command ==> cd /home/pi/Documents/Initial_RPi and then type sudo chmod +x run.sh and ./run.sh

11. Turn On WiFi:- sudo ifconfig wlan0 up

12. To give WiFi_Credentials:- sudo raspi-config nonint do_wifi_ssid_passphrase shuva shuva@123
