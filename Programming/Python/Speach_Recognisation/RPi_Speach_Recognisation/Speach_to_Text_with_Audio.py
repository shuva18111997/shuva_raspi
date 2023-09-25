"""
Link:- https://www.geeksforgeeks.org/python-convert-speech-to-text-and-text-to-speech/#:~:text=Translation%20of%20Speech%20to%20Text%3A,function%20may%20take%202%20arguments.&text=After%20initialization%2C%20we%20will%20make,may%20also%20take%202%20arguments.
Install Packages:-
python -m pip install speechrecognition
python -m pip install pyaudio
python -m pip install pyttsx3
sudo apt-get install flac
"""
# Python program to translate
# speech to text and text to speech


import speech_recognition as sr
import pyttsx3

# Initialize the recognizer
r = sr.Recognizer()

# Function to convert text to
# speech
def SpeakText(command):
	
	# Initialize the engine
	engine = pyttsx3.init()
	engine.say(command)
	engine.runAndWait()
	
	
# Loop infinitely for user to
# speak

while(1):
	
	# Exception handling to handle
	# exceptions at the runtime
	try:
		
		# use the microphone as source for input.
		with sr.Microphone() as source2:
			print("Say Something...")
			# wait for a second to let the recognizer
			# adjust the energy threshold based on
			# the surrounding noise level
			r.adjust_for_ambient_noise(source2, duration=0.2)
			
			#listens for the user's input
			audio2 = r.listen(source2)
			
			# Using google to recognize audio
			MyText = r.recognize_google(audio2, language = 'en-IN')
			MyText = MyText.lower()

			print("Did you say "+MyText)
			SpeakText(MyText)
			
	except sr.RequestError as e:
		print("Could not request results; {0}".format(e))
		
	except sr.UnknownValueError:
		print("unknown error occured")
