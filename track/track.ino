#include "track.h"
spa_data spa;
double zenith;
double azimuth;

void setup() {
  Serial.begin(9600);
}

void loop() {
    setSPA(spa, 
         2003,      // year
         10,        // month
         17,        // day
         12,        // hour
         30,        // minute
         30,        // second
         0,         // delta_ut1
         67,        // delta_t
         -7.0,      // timezone
         -105.1786, // longitude
         39.742476, // latitude
         1830.14,   // elevation
         820,       // pressure 
         11,        // temperature
         30,        // slope
         -10,       // azm_rotation
         0.5667,    // atmos_refract
         SPA_ALL);   // function mode

    //zenith = spa.zenith;
    //azimuth = spa.azimuth;

    Serial.print("Zenith:");
    Serial.print(spa.zenith);
    Serial.print("Azimuth:");
    Serial.print(spa.azimuth);


    delay(1000);
}
