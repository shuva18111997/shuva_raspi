1.	Check the smb.conf, apache2.conf, php.ini files is available or not.
2.	Check the "Programming" Folder is available or not in "home/pi/Documents".
3.	Then Copy Arduino Folder and install Arduino
4.	Then Copy the "ngrok" and first authenticate it then run. Link:- https://www.dexterindustries.com/howto/access-your-raspberry-pi-from-outside-your-home-or-local-network/
5.	The set the clock format ==> %d/%b/%y %a %I:%M%p
6.	Enable SPI & I2C from Raspi-config to use TFT_Display of Raspberry PI.
7.  Then copy this commands and run in terminal.
8.  Please check the Remote Desktop is off only SSH enable so the "thinclient_driver" is not present in desktop.
9. If Raspberry Pi can't Upgrade ==> https://pimylifeup.com/raspbian-repository-mirror/

sudo chmod -R 777 /home/pi && git clone https://github.com/WiringPi/WiringPi.git && cd WiringPi && ./build && cd && sudo rm -r WiringPi && sudo apt-get upgrade -y && sudo apt-get update -y && sudo apt-get install xrdp samba samba-common-bin gparted minicom putty cmake qbittorrent mosquitto mosquitto-clients apache2 php7.4 libapache2-mod-php7.4 php7.4-mbstring php7.4-mysql php7.4-curl php7.4-gd php7.4-zip php7.4-sqlite sqlite3 sqlitebrowser libmono-system-windows-forms4.0-cil avrdude gcc-avr -y && sudo cp /home/pi/Documents/Initial_RPi/smb.conf /etc/samba && sudo cp /home/pi/Documents/Initial_RPi/mosquitto.conf /etc/mosquitto && sudo systemctl restart mosquitto && sudo cp /home/pi/Documents/Initial_RPi/apache2.conf /etc/apache2 && sudo cp /home/pi/Documents/Initial_RPi/000-default.conf /etc/apache2/sites-available && sudo cp /home/pi/Documents/Initial_RPi/php.ini /etc/php/7.4/apache2 && sudo systemctl reload apache2 && cd /home/pi/Documents/Ngrok && ./ngrok authtoken 1VpXKXCaOf462BozThxeFruWlnG_rsem3bn8hxiQHHXFkuV8 && cd && cd /home/pi/Documents && mkdir AVRDUDESS && cd /home/pi/Documents/AVRDUDESS && sudo cp /home/pi/Documents/Initial_RPi/AVRDUDESS-2.14-portable.zip /home/pi/Documents/AVRDUDESS && unzip /home/pi/Documents/AVRDUDESS/AVRDUDESS-2.14-portable.zip && sudo rm /home/pi/Documents/AVRDUDESS/AVRDUDESS-2.14-portable.zip && cd && sudo cp /home/pi/Documents/Initial_RPi/AVRDUDESS.sh /home/pi/Desktop && sudo chmod +x /home/pi/Desktop/AVRDUDESS.sh && sudo pip install esptool esp-idf-monitor

sudo pip3 install st7789 && sudo cp /home/pi/Documents/Initial_RPi/kill_script.sh /home/pi/Desktop && sudo chmod +x /home/pi/Desktop/kill_script.sh && sudo nano /etc/rc.local

8. Add this line to rc.local file, and then save it.

############################################################################################
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.

# Print the IP address
_IP=$(hostname -I) || true
if [ "$_IP" ]; then
  printf "My IP address is %s\n" "$_IP"
fi

sudo python /home/pi/Documents/RPi_Programs/RaspberryPi_TFT_Display/WiFi_Connection.py &

exit 0
############################################################################################