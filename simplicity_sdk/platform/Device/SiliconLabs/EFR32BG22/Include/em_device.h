/**************************************************************************//**
 * @file
 * @brief CMSIS Cortex-M Peripheral Access Layer for Silicon Laboratories
 *        microcontroller devices
 *
 * This is a convenience header file for defining the part number on the
 * build command line, instead of specifying the part specific header file.
 *
 * @verbatim
 * Example: Add "-DEFM32G890F128" to your build options, to define part
 *          Add "#include "em_device.h" to your source files

 *
 * @endverbatim
 ******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories, Inc. www.silabs.com</b>
 ******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *****************************************************************************/

#ifndef EM_DEVICE_H
#define EM_DEVICE_H
#if defined(EFR32BG22C112F352GM32)
#include "efr32bg22c112f352gm32.h"

#elif defined(EFR32BG22C112F352GM40)
#include "efr32bg22c112f352gm40.h"

#elif defined(EFR32BG22C222F352GM32)
#include "efr32bg22c222f352gm32.h"

#elif defined(EFR32BG22C222F352GM40)
#include "efr32bg22c222f352gm40.h"

#elif defined(EFR32BG22C222F352GN32)
#include "efr32bg22c222f352gn32.h"

#elif defined(EFR32BG22C224F512GM32)
#include "efr32bg22c224f512gm32.h"

#elif defined(EFR32BG22C224F512GM40)
#include "efr32bg22c224f512gm40.h"

#elif defined(EFR32BG22C224F512GN32)
#include "efr32bg22c224f512gn32.h"

#elif defined(EFR32BG22C224F512IM32)
#include "efr32bg22c224f512im32.h"

#elif defined(EFR32BG22C224F512IM40)
#include "efr32bg22c224f512im40.h"

#elif defined(EFR32BG22E224F512IM32)
#include "efr32bg22e224f512im32.h"

#elif defined(EFR32BG22E224F512IM40)
#include "efr32bg22e224f512im40.h"

#elif defined(EFR32BG22L122F352GM32)
#include "efr32bg22l122f352gm32.h"

#else
#error "em_device.h: PART NUMBER undefined"
#endif

#if defined(SL_CATALOG_TRUSTZONE_SECURE_CONFIG_PRESENT) && defined(SL_TRUSTZONE_NONSECURE)
#error "Can't define SL_CATALOG_TRUSTZONE_SECURE_CONFIG_PRESENT and SL_TRUSTZONE_NONSECURE MACRO at the same time."
#endif

#if defined(SL_TRUSTZONE_SECURE) && defined(SL_TRUSTZONE_NONSECURE)
#error "Can't define SL_TRUSTZONE_SECURE and SL_TRUSTZONE_NONSECURE MACRO at the same time."
#endif
#endif /* EM_DEVICE_H */
