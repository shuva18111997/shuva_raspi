sudo chmod -R 777 /home/pi
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi
./build
cd
sudo rm -r WiringPi
sudo sed -i 's/http:\/\/raspbian.raspberrypi.org\/raspbian/http:\/\/mirror.aarnet.edu.au\/pub\/raspbian\/raspbian/' /etc/apt/sources.list
sudo apt-get upgrade -y
sudo apt-get update -y
sudo apt-get install xrdp samba samba-common-bin gparted minicom putty screen i2c-tools cmake qbittorrent mosquitto mosquitto-clients apache2 php7.4 libapache2-mod-php7.4 php7.4-mbstring php7.4-mysql php7.4-curl php7.4-gd php7.4-zip php7.4-sqlite sqlite3 sqlitebrowser libmono-system-windows-forms4.0-cil avrdude gcc-avr -y
sudo cp /home/pi/Documents/Initial_RPi/smb.conf /etc/samba
sudo cp /home/pi/Documents/Initial_RPi/mosquitto.conf /etc/mosquitto
sudo systemctl restart mosquitto
sudo cp /home/pi/Documents/Initial_RPi/apache2.conf /etc/apache2
sudo cp /home/pi/Documents/Initial_RPi/000-default.conf /etc/apache2/sites-available
sudo cp /home/pi/Documents/Initial_RPi/php.ini /etc/php/7.4/apache2
sudo systemctl reload apache2
cd /home/pi/Documents/Ngrok
./ngrok authtoken 1VpXKXCaOf462BozThxeFruWlnG_rsem3bn8hxiQHHXFkuV8
cd /home/pi/Documents
mkdir AVRDUDESS
cd /home/pi/Documents/AVRDUDESS
sudo cp /home/pi/Documents/Initial_RPi/AVRDUDESS-2.14-portable.zip /home/pi/Documents/AVRDUDESS
unzip /home/pi/Documents/AVRDUDESS/AVRDUDESS-2.14-portable.zip
sudo rm /home/pi/Documents/AVRDUDESS/AVRDUDESS-2.14-portable.zip
sudo cp /home/pi/Documents/Initial_RPi/AVRDUDESS.sh /home/pi/Desktop
sudo chmod +x /home/pi/Desktop/AVRDUDESS.sh
sudo raspi-config nonint do_vnc 0
sudo raspi-config nonint do_spi 0
#sudo raspi-config nonint do_i2c 0
sudo pip install --upgrade pip
sudo pip install st7789 esptool esp-idf-monitor
sudo cp /home/pi/Documents/Initial_RPi/kill_script.sh /home/pi/Desktop
sudo chmod +x /home/pi/Desktop/kill_script.sh
sudo cp /home/pi/Documents/Initial_RPi/esptool /usr/bin
sudo chmod +x /usr/bin/esptool
sudo sed -i '$s/.*/sudo python \/home\/pi\/Documents\/RPi_Programs\/RaspberryPi_TFT_Display\/WiFi_Connection.py \&\n\nexit 0/' /etc/rc.local
sudo raspi-config nonint do_composite 0
sudo reboot
