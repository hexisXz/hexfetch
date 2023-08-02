#!/bin/sh

git clone https://github.com/hexisXz/hexfetch.git && mv hexfetch ~/Hexfetch && cd Hexfetch && gcc hexfetch.c -o hexfetch && sudo mv hexfetch /bin/ && sudo rm -r ~/hexfetch
