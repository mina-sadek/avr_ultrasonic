# avr_ultrasonic
An ATMega328p based project that reads distance using ultrasonic sensor module, and displays it on Graphical LCD

# Overview
The ultrasonic module used is the 4-pin HC-SR04, can be found here: https://www.sparkfun.com/products/13959.

Its sensing range is 2cm to 400cm

It has VCC, GND pins for powering the module, and 2 pins to interface with the microcontroller.

Pins used with the MCU are:
  1. Trigger: The MCU has to put a pulse of 10-to-15 usec to initiates a distance reading process
  2. Echo:    The module sends a pulse on this pin to the MCU, width of the pulse determines distance between the sensor and the obstacle in its sensing range.

# Connections Between AVR & HC-SR04
- TRIG pin can be connected to any GPIO pin, and that pin will work as output from the MCU
- ECHO pin is connected to INT0 pin (PD2), to use INT0 to detect changes in the echo output when going from LOW-to-HIGH to start counting the pulse width, and when going from HIGH-to-LOW to stop counting the pulse width and take the counted pulse_width value and translates it into a distance

![Alt text](/avr_ultrasonic_0_proteus_schematic/img.png?raw=true "ATMega328P with Ultrasonic and LCD")

# Ultrasonic module main idea
The ultrasonic module is a transceiver, it has to ultrasonic speaker, one acting as a ultrasonic transmitting speaker and the other acting as an ultrasonic receiving mic (sensor).
When a trigger is given to the module it sends a sound signal on the transmitting one, and put HIGH on the echo pin waiting until a signal is received back on the sensing mic or a time_out happens:
- If no obstacle exist, the receiving sensor won't sense any signal, and the module will time_out representing no signal retrieved.
- If an obstacle exists, the receiving sensor will sense the returning echo signal, as the sound wave will hit the obstacle and come back to the ultrasonic sensor, here the ultrasonic module will put LOW on the echo pin to represent time taken starting from sending the signal until it has hit the obstacle and came all the way back to the module again, so the time will represent time taken by the signal to pass the distance between the ultrasonic module and the obstacle twice.
Using Speed of Sound, and getting time taken by the signal, distance can be easily calculated.

As sound_speed = 34300 cm/sec

and time_one_way = pulse_time / 2;   // where time_one_way = total time calculated by the sensor (pulse_time) divided by 2

distance can be calculated as:

distance = sound_speed * time_one_way;

As time calculations will be in micro-seconds:

sound_speed = 0.0343 cm/usec

distance = 0.0343 * pulse_time / 2;
