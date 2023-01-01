import serial
import alsaaudio
#from subprocess import call

m = alsaaudio.Mixer()
ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
    s = ser.readline().decode('utf-8').rstrip()
    if s != '':
        volume = int(s)
        volume *= 100
        volume //= 4040
        if (volume > 100):
            volume = 100
        m.setvolume(volume)


 
"""ser = serial.Serial('/dev/ttyACM0', 9600)
while True:
    s = ser.readline().decode('utf-8').rstrip()
    if s != '':
        volume = int(s)
        volume *= 16
        call(["amixer", "-q", "-D", "pulse", "set", "Master", str(volume)]) """