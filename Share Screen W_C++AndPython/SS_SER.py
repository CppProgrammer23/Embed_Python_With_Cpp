from vidstream import StreamingServer
import threading


def share():
    serv=StreamingServer('192.168.1.116',6010)
    t=threading.Thread(target=serv.start_server)
    t.start()
    print('Start sharing..')

    while input('')!='STOP':
        continue
    print('Stop sharing')
    serv.stop_server()
    t._stop()