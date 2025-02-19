/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#ifndef WDG_CFG_2015_02_18_H
  #define WDG_CFG_2015_02_18_H

  // includes.
  #include <Bsw/Common/Std_Types.h>
  #include <Bsw/Mcal/Wdg/Wdg_ConfigTypes.h>

  // AUTOSAR-API.
  #define WDG_DEV_ERROR_DETECT_API        STD_OFF

  typedef struct struct_Wdg_ConfigType
  {
   uint8 Wdg_Setting;
  }
  Wdg_ConfigType;

  EXTERN_C const Wdg_ConfigType Wdg_ModeConfiguration;

#endif // WDG_CFG_2015_02_18_H
