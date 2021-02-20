# This Python file uses the following encoding: utf-8

#from gtts import gTTS
#import playsound
#import speech_recognition as sr
#
#
#def talk(txt):
#    tts = gTTS(text=txt, lang='en')
#    tts.save('start.mp3')
#    playsound.playsound('start.mp3')
#
#
#def getAudio():
#    a = sr.Recognizer()
#    with sr.Microphone() as s:
#        audio = a.listen(s)
#        said = ''
#        try:
#            said = a.recognize_google(audio)
#            #print(said)
#        except Exception as e:
#            print(e)
#    return said.encode('ascii')
