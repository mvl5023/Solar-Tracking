#include "track.h"


void setSPA(spa_data spa, int year, int month, int day, int hour, int minute, double second, double delta_ut1, 
  double delta_t, double timezone, double longitude, double latitude, double elevation, double pressure, 
  double temperature, double slope, double azm_rotation, double atmos_refract, int function)
  {
    spa.year          = year;
    spa.month         = month;
    spa.day           = day;
    spa.hour          = hour;
    spa.minute        = minute;
    spa.second        = second;
    spa.timezone      = timezone;
    spa.delta_ut1     = delta_ut1;
    spa.delta_t       = delta_t;
    spa.longitude     = longitude;
    spa.latitude      = latitude;
    spa.elevation     = elevation;
    spa.pressure      = pressure;
    spa.temperature   = temperature;
    spa.slope         = slope;
    spa.azm_rotation  = azm_rotation;
    spa.atmos_refract = atmos_refract;
    spa.function      = SPA_ZA;
  }

void getZA(spa_data spa, double *zenith, double *azimuth)
{
  spa_calculate(&spa);
  *zenith = spa.zenith; // in degrees
  *azimuth = spa.azimuth; // eastward from north, in degrees  
}


