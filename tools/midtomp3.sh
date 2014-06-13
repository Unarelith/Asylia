#!/bin/sh
timidity $1.mid -Ow -o - | lame - -b 128 $1.mp3
