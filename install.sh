#!/bin/sh

git clone https://github.com/hexisXz/hexfetch.git && mv hexfetch ~/ && cd hexfetch && gcc hexfetch.c -o hexfetch && sudo mv hexfetch /bin/
