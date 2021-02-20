# How to setup the project, a Qt project

_**Why I used Qt and not PyQt?**_

Simple answer: this was dedicated to a mobile deployement and the cross platform I used it doesn't support Python, it does only support Python Scripts to link them with C++.

an other answer: because I want to use the powerful of the 2 languages combined together.

_**Now let's dive into the config:**_

Use MSVC compiler and not MinGW.

You have to get the Portaudio.dll which can be found in an anaconda environment (I will link the .dll file here, if you got some problems getting it)

In the constructor, you have to put your directory file where you added the Python Scripts.

You have to an external library to link Python lib in .pro as I made.
