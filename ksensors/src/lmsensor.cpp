/***************************************************************************
                          lmsensor.cpp  -  description
                             -------------------
    begin                : Mon Aug 6 2001
    copyright            : (C) 2001 by 
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "lmsensor.h"

#include "lmsensorschip.h"

#include "stdio.h"

LMSensor::LMSensor(SensorsList *parent): Sensor(parent)
{
  feature= -1;
}


LMSensor::~LMSensor(){
}

#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
bool LMSensor::init(const sensors_feature_data **data, int *nr1,int *nr2)
#else
bool LMSensor::init(const sensors_feature **data, int *nr1, int *nr2)
#endif
{
 double min,max;
 const sensors_chip_name *chip_name= getChipName();
 const char* main_name = (*data)->name;
 feature= (*data)->number;
 char *label;
 QString str;

#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
 bool min_found=false;
 bool max_found=false;
 while( (*data= sensors_get_all_features(*chip_name, nr1, nr2)) && (*data)->mapping!=SENSORS_NO_MAPPING) {
   int len = strlen((*data)->name);
   const char *postfix = (*data)->name + len - 4;

   if (len < 5)
     continue;

   if((!strcmp(postfix, "_min") || !strcmp(postfix, "_low")) &&
      !sensors_get_feature(*chip_name, (*data)->number, &valMin))
     min_found=true;
   
   if(!strcmp(postfix, "_max") &&
      !sensors_get_feature(*chip_name, (*data)->number, &valMax)) {
     max_found=true;
     continue;
   }

   postfix--;

   if((!strcmp(postfix, "_over") || !strcmp(postfix, "_high")) &&
      !sensors_get_feature(*chip_name, (*data)->number, &valMax))
     max_found=true;
 }

 double newVal;
 if ((sensors_get_ignored(*chip_name, feature) != 1) || (sensors_get_feature(*chip_name, feature, &newVal) != 0)) {
   return false;
 }

 if (strstr(main_name, "temp"))
 {
    setType(lmTemp);
    max= 65;
    min= 0;
 }
 else if (strstr(main_name, "fan"))
 {
    setType(lmFan);
    max= 10000;
    min= 3000;
 }
 else if (strstr(main_name, "alarm") || strstr(main_name, "sensor") || strstr(main_name, "vrm"))
 {
    return false;
 }
 else
 {
    setType(lmVoltage);
    max= 16;
    min= -16;
 }

 str.sprintf("%s.%s", chip_name->prefix, main_name);
 setName( str.latin1() );

 sensors_get_label(*chip_name,feature,&label);
 setDescription(QString(label));

 if(min_found)
   min = valMin;
   
 if(max_found)
   max = valMax;

#else /* libsensors4 code */

  const sensors_subfeature *sub_feature;
  const sensors_feature *feature_data = *data;
  
  /* Move to next feature for the loop in LMSensorsChip::createSensors() */
  *data = sensors_get_features(chip_name, nr1);
 
  switch(feature_data->type)
  {
    case SENSORS_FEATURE_IN:
      sub_feature = sensors_get_subfeature(chip_name, feature_data,
        SENSORS_SUBFEATURE_IN_INPUT);

      if (!sub_feature)
        return false;

      feature = sub_feature->number;

      if (!(sub_feature = sensors_get_subfeature(chip_name, feature_data,
            SENSORS_SUBFEATURE_IN_MIN)) ||
          sensors_get_value(chip_name, sub_feature->number, &min))
        min = -16;

      if (!(sub_feature = sensors_get_subfeature(chip_name, feature_data,
            SENSORS_SUBFEATURE_IN_MAX)) ||
          sensors_get_value(chip_name, sub_feature->number, &max))
        max = 16;
 
      setType(lmVoltage);
      break;

    case SENSORS_FEATURE_FAN:
      sub_feature = sensors_get_subfeature(chip_name, feature_data,
        SENSORS_SUBFEATURE_FAN_INPUT);

      if (!sub_feature)
        return false;

      feature = sub_feature->number;

      if (!(sub_feature = sensors_get_subfeature(chip_name, feature_data,
            SENSORS_SUBFEATURE_FAN_MIN)) ||
          sensors_get_value(chip_name, sub_feature->number, &min))
        min = 3000;

      max = 10000;

      setType(lmFan);
      break;

    case SENSORS_FEATURE_TEMP:
      sub_feature = sensors_get_subfeature(chip_name, feature_data,
        SENSORS_SUBFEATURE_TEMP_INPUT);

      if (!sub_feature)
        return false;

      feature = sub_feature->number;

      if (!(sub_feature = sensors_get_subfeature(chip_name, feature_data,
            SENSORS_SUBFEATURE_TEMP_MIN)) ||
          sensors_get_value(chip_name, sub_feature->number, &min))
        min = 0;

      if ((!(sub_feature = sensors_get_subfeature(chip_name, feature_data,
              SENSORS_SUBFEATURE_TEMP_MAX)) &&
           !(sub_feature = sensors_get_subfeature(chip_name, feature_data,
              SENSORS_SUBFEATURE_TEMP_CRIT))) ||
          sensors_get_value(chip_name, sub_feature->number, &max))
        max = 65;

      setType(lmTemp);
      break;
    
    default:
      return false;
  }

  str.sprintf("%s.%s", chip_name->prefix, main_name);
  setName( str.latin1() );

  label = sensors_get_label(chip_name, feature_data);
  if (label)
    setDescription(QString(label));
  else
    setDescription( str.latin1() );

#endif /* libsensors3 / libsensors4 code */

 if(min>max) {
   double pivot= min;
   min= max;
   max= pivot;
 }

 setValueMax(max,dgCelsius);
 setValueMin(min,dgCelsius);

 readConfig();
 updateValue();
 setValueIdeal(getValue());

 return true;
}

void LMSensor::updateValue()
{
 setValue( readSensorValue(), dgCelsius );
}

double LMSensor::readSensorValue()
{
 double newVal;
 const sensors_chip_name *chip_name= getChipName();
#if SENSORS_API_VERSION < 0x400 /* libsensor 3 code */
 sensors_get_feature(*chip_name, feature, &newVal);
#else
 sensors_get_value(chip_name, feature, &newVal);
#endif
 return newVal;
}

#define ABSOLUTE_VALUE(n)  ( (n)>=0 ? (n) : -(n) )
#define TRUNCATE_VALUE(n)  ( (double)(int)(n)    )

double LMSensor::calculateIdealValue()
{
 double value= readSensorValue();

 if(getType()==lmVoltage) {
     double decimals= 10;
     double module = ABSOLUTE_VALUE(value);
     if(module>3.0) {
       if( ABSOLUTE_VALUE( 12.0-value)<2.0 ) return  12.0;
       if( ABSOLUTE_VALUE(-12.0-value)<2.0 ) return -12.0;
       if( ABSOLUTE_VALUE(  5.0-value)<1.0 ) return   5.0;
       if( ABSOLUTE_VALUE( -5.0-value)<1.0 ) return  -5.0;
       if( ABSOLUTE_VALUE(  3.3-value)<0.3 ) return   3.3;
       if( ABSOLUTE_VALUE( -3.3-value)<0.3 ) return  -3.3;
       if(module>4.0) decimals= 1;
     }
     return TRUNCATE_VALUE((value * decimals)) / decimals;
  } else {
     return value;
  }
}

const sensors_chip_name *LMSensor::getChipName()
{
  return ((LMSensorsChip *)parent())->getChipName();
}
