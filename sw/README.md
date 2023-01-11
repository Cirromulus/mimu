framework-arduino-avr-attiny needs patching if less RAM is desired:

Go to your version of platformio packages (most likely `/home/$(whoami)/.platformio/packages/framework-arduino-avr-attiny`) and apply the patch there (`git apply path-to-patch`).