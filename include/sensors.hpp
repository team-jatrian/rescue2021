#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <sensor.hpp>
#include "macros.h"

#define L_DEFAULT 120 //18
#define LI_DEFAULT 120 //17
#define M_DEFAULT 120 //16
#define RI_DEFAULT 120 //15
#define R_DEFAULT 120 //14

extern sensor L, LI, M, RI, R;

#endif