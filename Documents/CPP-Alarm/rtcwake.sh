#!/bin/bash

pactl set-sink-volume 0 175%
rtcwake -m mem -s 1200 && vlc-wrapper /home/michael/Music/alarm.mp3 --loop
