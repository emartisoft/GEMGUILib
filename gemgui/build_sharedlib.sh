#!/bin/sh
g++ -Wall -fexceptions -O2 -c gemform.cpp -o gemform.o -I/include/ -fPIC
g++ -Wall -fexceptions -O2 -c gemlabel.cpp -o gemlabel.o -I/include/ -fPIC
g++ -Wall -fexceptions -O2 -c gembutton.cpp -o gembutton.o -I/include/ -fPIC
g++ -Wall -fexceptions -O2 -c gemcombox.cpp -o gemcombox.o -I/include/ -fPIC
g++ -Wall -fexceptions -O2 -c gemmenu.cpp -o gemmenu.o -I/include/ -fPIC
g++ -Wall -fexceptions -O2 -c gemmenubaritem.cpp -o gemmenubaritem.o -I/include/ -fPIC
g++ -Wall -fexceptions -O2 -c gemtextbox.cpp -o gemtextbox.o -I/include/ -fPIC
g++ -Wall -fexceptions -O2 -c gemdialog.cpp -o gemdialog.o -I/include/ -fPIC
g++ -shared *.o -o ../libgemgui.so -s
rm -f *.o
sudo cp ../libgemgui.so /lib/
sudo mkdir -p /usr/share/gem/
sudo cp AtariST8x16SystemFont.ttf /usr/share/gem/
sudo cp gembuttons.bmp /usr/share/gem/
sudo cp gemactive.bmp /usr/share/gem/

