This repository contains two Arduino sketches to accompany the video, "XBee_s1_UNO_to_UNO".  Sawtooth data is sent from one UNO (Arduino) to another UNO using two XBee radios (Series 1 by Digi International), each on a Wireless SD shield (Arduino).  Data received is then plotted on an LCD (2.8" TFT Touch Shield, v1.1 by Adafruit).

Settings for the XBee units were made by using the Mac application "CoolTerm" and a Sparkfun Explorer with AT Commands.  They are as follows:

        	Sender		Receiver
ATID		2171		2171
ATMY		1		0
ATDH		0		0
ATDL		0		1
ATBD		3		3

For Windows users, the application "X-CTU" may be used.  The terminal window should have "echo" turned on.  Typing "+++" and waiting for the "OK" will allow settings to be checked or changed.  ATWR followed by Enter will save the configuration if changes are made.

ATID may be any number from 0 to 65535, provided that it is identical for both units.  ATBD = 3 corresponds to a baud rate of 9600.

When uploading the Arduino sketches to the XBee units, set the Serial Select switch on the Wireless shield to “USB”.  After uploading, set  the switch to “Micro” to run.