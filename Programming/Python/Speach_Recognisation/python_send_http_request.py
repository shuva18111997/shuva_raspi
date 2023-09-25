import speech_recognition as sr
import requests

r = sr.Recognizer()
speech = sr.Microphone()
while True:
    with speech as source:
        print("say something!…")
        audio = r.adjust_for_ambient_noise(source)
        audio = r.listen(source)
    try:
        recog = r.recognize_google(audio, language = 'en-IN')

        print("You said: " + recog)
        if(recog.lower() == "light on"):
            x = requests.get('https://shuvaiotapp.000webhostapp.com/featch_data.php?Update=1&Light=true')
        if(recog.lower() == "light off"):
            x = requests.get('https://shuvaiotapp.000webhostapp.com/featch_data.php?Update=1&Light=false')
        if(recog.lower() == "fan on"):
            x = requests.get('https://shuvaiotapp.000webhostapp.com/featch_data.php?Update=1&Fan=true')
        if(recog.lower() == "fan off"):
            x = requests.get('https://shuvaiotapp.000webhostapp.com/featch_data.php?Update=1&Fan=false')
            
    except sr.UnknownValueError:
        print("Google Speech Recognition could not understand audio")
    except sr.RequestError as e:
        print("Could not request results from Google Speech Recognition service; {0}".format(e))

