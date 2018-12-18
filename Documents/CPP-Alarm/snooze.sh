#!/bin/bash
pactl set-sink-volume 0 175%
rtcwake -m mem -s 60 && vlc-wrapper /home/michael/Music/alarm.mp3 --loop