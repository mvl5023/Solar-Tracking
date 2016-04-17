#ifdef __cplusplus
extern "C" {
#endif

#include "spa.h"
#include "fine.h"


void setSPA(spa_data spa, int year, int month, int day, int hour, int minute, double second, double delta_ut1, 
  double delta_t, double timezone, double longitude, double latitude, double elevation, double pressure, 
  double temperature, double slope, double azm_rotation, double atmos_refract, int function);

void getZA(spa_data spa, double *zenith, double *azimuth);

#ifdef __cplusplus
}
#endif
