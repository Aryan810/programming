import os.path
from threading import Thread
import time
from inputimeout import inputimeout
from pygame import mixer
from mutagen.mp3 import MP3
print(MP3("phy_act.mp3").info.length)