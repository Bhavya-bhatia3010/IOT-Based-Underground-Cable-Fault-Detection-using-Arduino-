# IOT-Based-Underground-Cable-Fault-Detection-using-Arduino-
The objective of this project is to determine the distance of underground cable fault from base station in kilometres. The underground cable system is a common practice followed 
in many urban areas. While a fault occurs for some reason, at that time the repairing process related to that cable is difficult due to not knowing the exact location of the cable 
fault. The proposed system is to find the exact location of the fault. The project uses the standard concept of Ohms law i.e., when a low DC voltage is applied at the feeder end 
through a series resistor (Cable lines), then current would vary depending upon the location of fault in the cable. In case there is a short circuit (Line to Ground), the voltage 
across series resistors changes accordingly, which is then fed to Arduino to develop digital data which the programmed microcontroller of 8051 family would display in 
kilometres. 

The project is assembled with a set of resistors representing cable length in KM’s and fault creation is made by a set of switches at every known KM to cross check 
the accuracy of the same. The fault occurring at a particular distance and the respective phase is displayed on LCD interfaced to the microcontroller.

WORKING PRINCIPLE
 
This method works on the principle of Ohms law and the relation which says that the resistance is directly proportional to Length. In this project we measure wire resistance at some particular locations. Those locations indicated through slide switches. Based on slide switch ON/OFF, it assumes No fault and fault. 

When a low DC voltage is applied at the feeder end through a series resistor (Cable lines), then current would vary depending upon the location of fault in the cable. In case there is a short circuit (Line to Ground), the voltage across series resistors changes accordingly, which is then fed to Arduino for further processing.

FLOWCHART
<p align="center"> 
<img width="500" height="600" alt="image" src="https://github.com/user-attachments/assets/2d91214e-6696-445e-8f34-666c63c560da" />
</p>
BLOCK DIAGRAM
<p align="center">
<img width="450" height="600" alt="image" src="https://github.com/user-attachments/assets/2a7817a4-c1c1-48c7-a727-074e5e7c472a" />
</p>
CIRCUIT DIAGRAM
<p align="center">
 <img width="613" height="426" alt="image" src="https://github.com/user-attachments/assets/3a183dc8-e5a5-403b-b6ea-635a7ba1b3c7" />
</p>

WORKING

Working of this project is divided into four parts – 

DC power supply Part, cable part, controlling part, display part. 

• DC power supply given to the circuit from Arduino. The set of resistors denotes the cable part along with switches. The set of resistors & switches are used as fault creators to indicate the fault at each location this shown by the current sensing part of cable. The change in current is sensed by this part by sensing the voltage drop. 

• Controlling part uses the analog to digital (ADC) to converter the input current sensing signal from the current generating circuit to the voltage drop into digital signal and supply the Microcontroller. The microcontroller makes necessary calculations regarding the distance of the fault. The driver is run by the 
microcontroller and controls the switching of the relays for proper connection of the cable at each phase. 

• Display part consists of the LCD display interfaced to the microcontroller and it shows the status of the cable of each phase and the fault distance of the cable at the phase in case of any fault and ESP01 is used to send message to the base station over the web. Buzzer is used to alerts the field workers. 

In this project we can detect the fault in three phases. Each phase of the system requires large wire 3km,4km,5km etc. Hence to represent the length of the wire, its internal resistance is used as reference parameter. We know that as the length of the copper wire increases, the resistance in the cable also increases. Hence to represent the different length of wire, we connect 1kΩ resistance for each 2 km distance. 

Here we connect 4 resistances of 1 kΩ in series so we cover 8km distance in each phase. Switch are connected to disconnect the wire in each segment. One reference cable is also present with the three-phase cable to compare with it. The Arduino board requires reference resistance of cable with the fault cable resistance. 
