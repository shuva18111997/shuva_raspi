from vosk import Model, KaldiRecognizer
import pyaudio
import RPi.GPIO as GPIO       ## Import GPIO library
Red_Led_Pin = 3
Green_Led_Pin = 5
GPIO.setmode(GPIO.BOARD)      ## Use board pin numbering
GPIO.setup(Red_Led_Pin, GPIO.OUT)      ## Setup GPIO Pin 3 to OUT
GPIO.setup(Green_Led_Pin, GPIO.OUT)      ## Setup GPIO Pin 5 to OUT
GPIO.output(Red_Led_Pin,False)  ## Turn off Led
GPIO.output(Green_Led_Pin,False)  ## Turn off Led

model = Model(r'/home/pi/Documents/Programming/Python/Speach_Recognisation/vosk-model-small-en-in-0.4')
recognizer = KaldiRecognizer(model, 16000)

cap = pyaudio.PyAudio()
stream = cap.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=8192)
stream.start_stream()

while True:
    data = stream.read(4096)
    if len(data) == 0:
        break
    
    if recognizer.AcceptWaveform(data):
        res_data = recognizer.Result()[14:-3]
        print(res_data)
        if (res_data.lower() == "light on" or res_data.lower() == "light turn on" or res_data.lower() == "turn light on"):
            print("ok, Light is Turned ON")
            GPIO.output(Red_Led_Pin,True)  ## Turn on Led
        if (res_data.lower() == "light off" or res_data.lower() == "light of" or res_data.lower() == "light turn off" or res_data.lower() == "turn light of" or res_data.lower() == "turn light off"):
            print("ok, Light is Turned OFF")
            GPIO.output(Red_Led_Pin,False)  ## Turn off Led
        if (res_data.lower() == "fan on" or res_data.lower() == "fan turn on" or res_data.lower() == "turn fan on"):
            print("ok, Fan is Turned ON")
            GPIO.output(Green_Led_Pin,True)  ## Turn on Led
        if (res_data.lower() == "fan off" or res_data.lower() == "fan of" or res_data.lower() == "fan turn off" or res_data.lower() == "turn fan of" or res_data.lower() == "turn fan off"):
            print("ok, Fan is Turned OFF")
            GPIO.output(Green_Led_Pin,False)  ## Turn off Led
                    

