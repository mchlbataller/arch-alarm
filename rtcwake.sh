#!/bin/bash

pactl set-sink-volume 0 100%
pactl set-sink-mute 0 0
rtcwake -m mem -s 60 && vlc-wrapper /home/michael/Music/alarm.mp3 --loop > logs
