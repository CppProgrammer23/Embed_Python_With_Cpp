from vidstream import ScreenShareClient
import threading

#sender
client=ScreenShareClient('192.168.1.116',6010)
t=threading.Thread(target=client.start_stream)
t.start()

while input('')!='STOP':
    continue
client.stop_stream()