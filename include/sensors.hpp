#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <sensor.hpp>
#include "macros.h"

#define L_DEFAULT 100
#define LI_DEFAULT 100
#define M_DEFAULT 100
#define RI_DEFAULT 100
#define R_DEFAULT 100

extern sensor L, LI, M, RI, R;

#endif