import pyaudio
import speech_recognition as sr
import serial

arduinoData = serial.Serial('COM4',9600)

r = sr.Recognizer()

with sr.Microphone() as source:

    print("Please wait. Calibrating microphone...")
    r.adjust_for_ambient_noise(source, duration=5)

    while True:
    
        print("Listening...")
        audio = r.listen(source)

        try:
            text = r.recognize_google(audio)
            print(text)
            print(text[0])
            print(text[1])
            arduinoData.write('{}'.format(text[0]).encode())
            arduinoData.write('{}'.format(text[1]).encode())

        except:
            print('Error')

