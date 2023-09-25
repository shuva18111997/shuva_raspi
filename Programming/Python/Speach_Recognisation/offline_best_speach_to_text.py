from vosk import Model, KaldiRecognizer
import pyaudio

model = Model(r'C:\Users\Shuva_Lapi\Documents\Vosk Model\vosk-model-en-in-0.5')
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
        if (res_data.lower() == "light off" or res_data.lower() == "light of" or res_data.lower() == "light turn off" or res_data.lower() == "turn light of" or res_data.lower() == "turn light off"):
            print("ok, Light is Turned OFF")
        if (res_data.lower() == "fan on" or res_data.lower() == "fan turn on" or res_data.lower() == "turn fan on"):
            print("ok, Fan is Turned ON")
        if (res_data.lower() == "fan off" or res_data.lower() == "fan of" or res_data.lower() == "fan turn off" or res_data.lower() == "turn fan of" or res_data.lower() == "turn fan off"):
            print("ok, Fan is Turned OFF")
                    

