# IOT-Based-Underground-Cable-Fault-Detection-using-Arduino-
The objective of this project is to determine the distance of underground cable fault from base station in kilometres. The underground cable system is a common practice followed 
in many urban areas. While a fault occurs for some reason, at that time the repairing process related to that cable is difficult due to not knowing the exact location of the cable 
fault. The proposed system is to find the exact location of the fault. The project uses the standard concept of Ohms law i.e., when a low DC voltage is applied at the feeder end 
through a series resistor (Cable lines), then current would vary depending upon the location of fault in the cable. In case there is a short circuit (Line to Ground), the voltage 
across series resistors changes accordingly, which is then fed to Arduino to develop digital data which the programmed microcontroller of 8051 family would display in 
kilometres. The project is assembled with a set of resistors representing cable length in KM’s and fault creation is made by a set of switches at every known KM to cross check 
the accuracy of the same. The fault occurring at a particular distance and the respective phase is displayed on LCD interfaced to the microcontroller.

WORKING PRINCIPLE
 
This method works on the principle of Ohms law and the relation which says that the 
resistance is directly proportional to Length. In this project we measure wire resistance at 
some particular locations. Those locations indicated through slide switches. Based on 
slide switch ON/OFF, it assumes No fault and fault. 
When a low DC voltage is applied at the feeder end through a series resistor (Cable lines), 
then current would vary depending upon the location of fault in the cable. In case there is 
a short circuit (Line to Ground), the voltage across series resistors changes accordingly, 
which is then fed to Arduino for further processing.
