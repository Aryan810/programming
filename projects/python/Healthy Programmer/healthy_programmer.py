import os
from threading import Thread
from pygame import mixer
from datetime import datetime
from time import sleep, time
from inputimeout import inputimeout

TEMPFILE = "temp.txt"
def get_date():
    return datetime.now().strftime("%d %b, %Y --- %I:%M %p")
def get_day():
    return datetime.now().strftime("%d %b, %Y")
def get_time():
    return datetime.now().strftime("%I:%M %p")


class Player:

    def __init__(self, type_: int):
        self.type = type_
        self.files = ["water", "eye_ex", "phy_act"]
        self.audio_length = [2.298, 2.795, 2.246]  # duration of alarms of self.files list respectively.
        self.to_play = True
        self.loops = 5
        self.time_gap_in_loops = 0.5
        self.today_water = 0
        self.glass_capacity = 240
        mixer.init()
        mixer.music.set_volume(0.5)

    def start(self):
        Thread(target=self.check_to_halt).start()
        self.to_play = True
        self.play()

    def edit_temp(self):

        def reset():
            with open(TEMPFILE, "w") as f1:
                f1.write(get_day())
            with open(TEMPFILE, "a") as f2:
                f2.write(f"{get_time()}>{self.glass_capacity}")

        if os.path.exists(TEMPFILE):
            with open(TEMPFILE, "r+") as f:
                if f.readlines(0) == get_day():
                    x = f.readlines()
                    self.today_water = ((len(x)-1)*self.glass_capacity) + self.glass_capacity
                    # we are adding self.glass_capacity because the just drunk water is not adding in file yet.
                    f.write(f"{get_time()}>{self.glass_capacity}")
                else:
                    reset()
        else:
            reset()

    def play(self):
        mixer.music.load(f"{self.files[self.type]}.mp3")
        for i in range(self.loops):
            if not self.to_play:
                break
            mixer.music.play(1, fade_ms=int(self.time_gap_in_loops*1000))
            sleep(self.audio_length[self.type] + self.time_gap_in_loops)
        self.to_play = False

    def log(self, string: str):
        if os.path.exists(f"{self.files[self.type]}.txt"):
            with open(f"{self.files[self.type]}.txt", "a") as f:
                f.write(string)
        else:
            with open(f"{self.files[self.type]}.txt", "w") as f:
                f.write(string)
        self.edit_temp()

    def check_to_halt(self):
        print("entered in halt function")
        try:
            while self.to_play:
                try:
                    inp = inputimeout(prompt=">> ", timeout=5)
                except Exception:
                    inp = ""
                # print("INPUT:", inp)
                if inp == "1":
                    # print("music stopped")
                    mixer.music.stop()
                    self.to_play = False
                    # print("logging")
                    self.log(f"{get_date()}: TASK > {self.files[self.type]} DONE\n")
                    print("a is false now!")
        except Exception as e:
            print("error 0:", e)


class Main:

    def __init__(self):
        self.playing = False  # any alarm is playing or not
        self.ref_time = 1   # time after which we have to refresh our loop to see if it is a time to play a alarm.
        self.start_time = [time(), time(), time()]
        self.files = ["water", "eyes", "phy_act"]
        self.alarm_gape = [60, 40, 70]
        self.alarm_gape = list(map(lambda x: (x*60), self.alarm_gape))
        print(self.alarm_gape)
        # it is the gape of time in minutes after which we have to invoke alarm for
        # water, eye excersize and physical activity respectively.

    def get_time_elapsed(self):
        return list(map(lambda t: time()-t, self.start_time))
        # returns a list containing time elapsed after the last play of alarm for
        # water, eye_ex, and phy_act respectively

    def start(self):
        try:
            while True:
                t = self.get_time_elapsed()
                sleep(self.ref_time)
                for i, time_elapsed in enumerate(t):
                    # print(f"checking: {self.files[i]}, time elapsed: {str(time_elapsed)}")
                    if (((self.alarm_gape[i]-time_elapsed)/self.alarm_gape[i]) * 100) < 2:
                        self.playing = True
                        Player(i).start()
                        self.playing = False
                        self.start_time[i] = time()
        except Exception as e:
            print("error: ", e)


if __name__ == '__main__':
    Main().start()
