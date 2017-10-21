# ESC tool

This is a GUI written using the Qt toolkit to configure Electronic Speed
Controllers(ESC) like VESC&copy;, FOCBOX, ESK1.1, OLLIN ESC1.1 and probably
others which use the BLDC firmware.


This is based on Benjamin Vedders work (https://github.com/vedderb/vesc_tool).
So mostly his work and kudos to him.

In this fork i removed the trademark stuff i don't like, and added my wanted
features. See my BLDC repository for a matching firmware:
https://github.com/derlucas/bldc


## eBike - Pedelec App

Currently i'm implementing a new application for Electric vehicles (app_ev).
There are options for analog inputs for Accelleration and Braking. Inputs for
PAS Detector and Wheel Rotation detectors.

The goal is to be able to replace regular eBike controllers with this \*ESC and
have all the nice config options we like.

With this App, you are able to make a legal eBike (some countries need detection
for pedaling etc).

Please look at the BLDC repository for recent status information.


## other changes to the original Software

This fork removes some unnecessary behaviour/stuff from the original Software
and makes it easier for others to use this great piece of software without
worrying about Trademark issues.

- removed all trademarked Logos
- removed all trademarked Wording / Brand
- removed the update-version online Check
- removed the First-Start Wizard where you need to accept the warranty/disclaimer
- changed the License information to be in the file COPYING


Happy further forking and using. Thanks Benjamin for your work.  
