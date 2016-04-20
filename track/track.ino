#include <Time.h> // included time libraries for Arduino
#include <TimeLib.h>
#include "Sun_position_algorithms.h" // Using the Grena ENEA Algorithm for Solar
#include <stdio.h> // for standard I/O

// declare global variables
sunpos SunPos;
double zenith;
double azimuth;
double UT;
char timestamp[32];

void setup() {
  Serial.begin(9600);

  // Syncs up the time with whatever input time
  // Currently no good way to grab system time from PC except if you use a Linux system
  setTime(6,     // hour
          0,     // minute
          0,     // second
          19,    // day
          4,     // month
          2016); // year
}

void loop() {
  // get known values

  SunPos.UT = hour() + minute()/60.0 + second()/3600.0; // UT in hours [decimal]
  SunPos.Day = day(); // day [integer]
  SunPos.Month = month(); // month [integer]
  SunPos.Year = year(); // year [integer]
  SunPos.Dt = 96.4 + 0.567*double(year()-2061); // Terrestial time - UT
  SunPos.Longitude = 77.86 * (2*PI/360.0); // State College Longitude and Latitude [radians]
  SunPos.Latitude = 40.7934 * (2*PI/360.0);
  SunPos.Pressure = 1.0; // Pressure [atm]
  SunPos.Temperature = 20.0; // Temperature [C]


  SunPos.Algorithm5();

  //zenith = spa.zenith;
  //azimuth = spa.azimuth;

  // creates string for timestamp
  sprintf(timestamp, "%d/%d/%d %d:%d:%d\t\t\t", month(), day(), year(), hour(), minute(), second());

  // prints out timestamp and zenith and azimuth angles in degrees
  Serial.print(timestamp);  
  Serial.print("Zenith:");
  Serial.print(SunPos.Zenith * (360/(2*PI)));
  Serial.print("\tAzimuth:");
  Serial.print(SunPos.Azimuth * (360/(2*PI)));
  Serial.print("\n");

  


  delay(1000);
}
