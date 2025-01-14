#!/bin/sh
clear && g++ example-06-jan-2025.cpp -o example-06-jan-2025.exe `pkg-config --cflags --libs gtkmm-4.0` -std=c++17 && ./example-06-jan-2025.exe
