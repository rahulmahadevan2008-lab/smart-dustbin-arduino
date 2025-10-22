# smart-dustbin-arduino
**Overview** 
This project uses Ultrasonic sensor to detect our hand within the range of 5 cm to 20cm and opens the dustbin
**Materials required:**
        1. Arduino UNO ---- Main controller of the motor and signal function 
        2. HC-SR04 Ultrasonic Sensor
        3. SG90 Servo Motor
        4. Jumper Wires (Male–-Male) & (Male--Female).
        5. USB Cable (Type B)
        6. Power Source (Power Bank)
        7. Dustbin Lid (hinged)
        8. Mounting Materials (Tape, glue, or screws to fix components in place)
        9. Bread Board
##  How It Works
1. The ultrasonic sensor emits a 40 kHz sound pulse.
2. If an object is detected within 20 cm, the servo motor rotates to open the lid.
3. If no object is detected, the lid remains closed.

## For reference: Image 1: <img width="590" height="439" alt="image" src="https://github.com/user-attachments/assets/bc61c077-0a2e-48c4-8dcd-20abfb0e8ef6" />

## For reference: Image 2: <img width="507" height="424" alt="image" src="https://github.com/user-attachments/assets/f9107ab6-0688-4685-82fa-cf79a65545ea" />


## Project Management: 
All 7 tasks were tracked and completed using GitHub Projects. [In projects]    
  [View the Project Board](https://github.com/rahulmahadevan2008-lab/smart-dustbin-arduino/projects)

## Working sample:{Based on the information in the code}
When an object is detected between the distance range of 5 to 20cm then the lid opens up to 90 degrees and holds it for 3 seconds and closes the lid back to 0 degree.
a . The trig pin triggers the ultrasonic sensor to emit ultrasonic sound of 40KHz. This sound is received by the echo sensor upon bouncing       back from the nearby object. The time taken by the echo pin to receive the sound is used by the arduino to calculate the distance of the     object from the lid.
b. The whole process of sending and receiving happens due to some changes in the trig pin. They are:
          (i)   First, the trig pin is turned off and allowed to wait for 2 microseconds to stabilize the signal for further procedures.
          (ii)  Second, the trig pin is turned on which allows the signal uninterrupted for about 10 microseconds.
          (iii) Third, it is then turned off again to wait for the echo to be received by the echo pin.
          (iv)  The arduino receives the time taken from the echo pin and calculates the distance based on this information.
c. The whole process from detection to distance calculation is repeated after an interval of 0.5 seconds between the consecutive cycles.
