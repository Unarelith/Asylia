# Asylia

[![Build Status](https://travis-ci.com/Quent42340/Asylia.svg?branch=master)](https://travis-ci.com/Quent42340/Asylia)
[![Documentation](https://codedocs.xyz/Quent42340/Asylia.svg)](https://codedocs.xyz/Quent42340/Asylia/)
[![License](https://img.shields.io/badge/license-LGPLv2.1%2B-blue.svg)](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html)

- Asylia is a classic RPG game engine made with SDL 2.0 and written in C++.
- Asylia is a game that uses XML for configuration scripts, and Lua for modding/event management.

## Screenshots

 ![](http://sdz-upload.s3.amazonaws.com/prod/upload/Capture%20d%27%C3%A9cran%20-%2016052014%20-%2021%3A09%3A25.png)
 ![](https://sdz-upload.s3.amazonaws.com/prod/upload/Capture%20d%27%C3%A9cran%20-%2016052014%20-%2021%3A11%3A35.png)
 ![](http://sdz-upload.s3.amazonaws.com/prod/upload/Capture%20d%27%C3%A9cran%20-%2016052014%20-%2021%3A12%3A00.png)

## Keys

- Movement: <kbd>&larr;</kbd> <kbd>&uarr;</kbd> <kbd>&darr;</kbd> <kbd>&rarr;</kbd>
- Start: <kbd>Esc</kbd>
- A: <kbd>Enter</kbd>
- B: <kbd>Backspace</kbd>

## How to compile

- Dependencies:
    - [CMake](http://www.cmake.org/download/)
    - [GameKit](http://github.com/Quent42340/GameKit) (requires `SDL2` + `tinyxml2`, will switch to `SFML` starting from 2.6)
    - [Lua](http://www.lua.org)
    - _Linux users: Check your distribution repositories for packages._
- Run `cmake . && make -j8`
- Run the game, enjoy!

