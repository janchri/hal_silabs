/***************************************************************************//**
 * @file
 * @brief General Purpose IO (GPIO) peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
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
 ******************************************************************************/

#ifndef EM_GPIO_H
#define EM_GPIO_H

#include "em_device.h"
#if defined(GPIO_COUNT) && (GPIO_COUNT > 0)

#include <stdbool.h>
#include "sl_assert.h"
#include "em_bus.h"
#include "sl_common.h"
#include "sl_enum.h"

#if defined(SL_CATALOG_GPIO_PRESENT)
#include "sl_device_gpio.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

#ifdef gpioPortA
#undef gpioPortA
#endif

#ifdef gpioPortB
#undef gpioPortB
#endif

#ifdef gpioPortC
#undef gpioPortC
#endif

#ifdef gpioPortD
#undef gpioPortD
#endif

#ifdef gpioPortE
#undef gpioPortE
#endif

#ifdef gpioPortF
#undef gpioPortF
#endif

#ifdef gpioPortG
#undef gpioPortG
#endif

#ifdef gpioPortH
#undef gpioPortH
#endif

#ifdef gpioPortI
#undef gpioPortI
#endif

#ifdef gpioPortJ
#undef gpioPortJ
#endif

#ifdef gpioPortK
#undef gpioPortK
#endif

#if defined(_SILICON_LABS_32B_SERIES_0) \
  && defined(_EFM32_TINY_FAMILY) || defined(_EFM32_ZERO_FAMILY)

#define _GPIO_PORT_A_PIN_COUNT 14
#define _GPIO_PORT_B_PIN_COUNT 10
#define _GPIO_PORT_C_PIN_COUNT 16
#define _GPIO_PORT_D_PIN_COUNT 9
#define _GPIO_PORT_E_PIN_COUNT 12
#define _GPIO_PORT_F_PIN_COUNT 6
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0xF77FUL
#define _GPIO_PORT_B_PIN_MASK 0x79F8UL
#define _GPIO_PORT_C_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_D_PIN_MASK 0x01FFUL
#define _GPIO_PORT_E_PIN_MASK 0xFFF0UL
#define _GPIO_PORT_F_PIN_MASK 0x003FUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_EFM32_HAPPY_FAMILY)

#define _GPIO_PORT_A_PIN_COUNT 6
#define _GPIO_PORT_B_PIN_COUNT 5
#define _GPIO_PORT_C_PIN_COUNT 12
#define _GPIO_PORT_D_PIN_COUNT 4
#define _GPIO_PORT_E_PIN_COUNT 4
#define _GPIO_PORT_F_PIN_COUNT 6
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0x0707UL
#define _GPIO_PORT_B_PIN_MASK 0x6980UL
#define _GPIO_PORT_C_PIN_MASK 0xEF1FUL
#define _GPIO_PORT_D_PIN_MASK 0x00F0UL
#define _GPIO_PORT_E_PIN_MASK 0x3C00UL
#define _GPIO_PORT_F_PIN_MASK 0x003FUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_SILICON_LABS_32B_SERIES_0) \
  && (defined(_EFM32_GIANT_FAMILY) || defined(_EFM32_WONDER_FAMILY))

#define _GPIO_PORT_A_PIN_COUNT 16
#define _GPIO_PORT_B_PIN_COUNT 16
#define _GPIO_PORT_C_PIN_COUNT 16
#define _GPIO_PORT_D_PIN_COUNT 16
#define _GPIO_PORT_E_PIN_COUNT 16
#define _GPIO_PORT_F_PIN_COUNT 13
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_B_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_C_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_D_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_E_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_F_PIN_MASK 0x1FFFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_EFM32_GECKO_FAMILY)

#define _GPIO_PORT_A_PIN_COUNT 16
#define _GPIO_PORT_B_PIN_COUNT 16
#define _GPIO_PORT_C_PIN_COUNT 16
#define _GPIO_PORT_D_PIN_COUNT 16
#define _GPIO_PORT_E_PIN_COUNT 16
#define _GPIO_PORT_F_PIN_COUNT 10
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_B_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_C_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_D_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_E_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_F_PIN_MASK 0x03FFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_SILICON_LABS_GECKO_INTERNAL_SDID_80) && defined(_EFR_DEVICE)

#define _GPIO_PORT_A_PIN_COUNT 6
#define _GPIO_PORT_B_PIN_COUNT 5
#define _GPIO_PORT_C_PIN_COUNT 6
#define _GPIO_PORT_D_PIN_COUNT 7
#define _GPIO_PORT_E_PIN_COUNT 0
#define _GPIO_PORT_F_PIN_COUNT 8
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0x003FUL
#define _GPIO_PORT_B_PIN_MASK 0xF800UL
#define _GPIO_PORT_C_PIN_MASK 0x0FC0UL
#define _GPIO_PORT_D_PIN_MASK 0xFE00UL
#define _GPIO_PORT_E_PIN_MASK 0x0000UL
#define _GPIO_PORT_F_PIN_MASK 0x00FFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_SILICON_LABS_GECKO_INTERNAL_SDID_80) && defined(_EFM_DEVICE)

#define _GPIO_PORT_A_PIN_COUNT 6
#define _GPIO_PORT_B_PIN_COUNT 5
#define _GPIO_PORT_C_PIN_COUNT 6
#define _GPIO_PORT_D_PIN_COUNT 7
#define _GPIO_PORT_E_PIN_COUNT 0
#define _GPIO_PORT_F_PIN_COUNT 8
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0x003FUL
#define _GPIO_PORT_B_PIN_MASK 0xF800UL
#define _GPIO_PORT_C_PIN_MASK 0x0FC0UL
#define _GPIO_PORT_D_PIN_MASK 0xFE00UL
#define _GPIO_PORT_E_PIN_MASK 0x0000UL
#define _GPIO_PORT_F_PIN_MASK 0x00FFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_SILICON_LABS_GECKO_INTERNAL_SDID_84)

#define _GPIO_PORT_A_PIN_COUNT 10
#define _GPIO_PORT_B_PIN_COUNT 10
#define _GPIO_PORT_C_PIN_COUNT 12
#define _GPIO_PORT_D_PIN_COUNT 8
#define _GPIO_PORT_E_PIN_COUNT 0
#define _GPIO_PORT_F_PIN_COUNT 16
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 4
#define _GPIO_PORT_J_PIN_COUNT 2
#define _GPIO_PORT_K_PIN_COUNT 3

#define _GPIO_PORT_A_PIN_MASK 0x03FFUL
#define _GPIO_PORT_B_PIN_MASK 0xFFC0UL
#define _GPIO_PORT_C_PIN_MASK 0x0FFFUL
#define _GPIO_PORT_D_PIN_MASK 0xFF00UL
#define _GPIO_PORT_E_PIN_MASK 0x0000UL
#define _GPIO_PORT_F_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x000FUL
#define _GPIO_PORT_J_PIN_MASK 0xC000UL
#define _GPIO_PORT_K_PIN_MASK 0x0007UL

#elif defined(_SILICON_LABS_GECKO_INTERNAL_SDID_89)

#define _GPIO_PORT_A_PIN_COUNT 6
#define _GPIO_PORT_B_PIN_COUNT 5
#define _GPIO_PORT_C_PIN_COUNT 6
#define _GPIO_PORT_D_PIN_COUNT 7
#define _GPIO_PORT_E_PIN_COUNT 0
#define _GPIO_PORT_F_PIN_COUNT 8
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0x003FUL
#define _GPIO_PORT_B_PIN_MASK 0xF800UL
#define _GPIO_PORT_C_PIN_MASK 0x0FC0UL
#define _GPIO_PORT_D_PIN_MASK 0xFE00UL
#define _GPIO_PORT_E_PIN_MASK 0x0000UL
#define _GPIO_PORT_F_PIN_MASK 0x00FFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined (_SILICON_LABS_GECKO_INTERNAL_SDID_106)
#define _GPIO_PORT_A_PIN_COUNT 16
#define _GPIO_PORT_B_PIN_COUNT 16
#define _GPIO_PORT_C_PIN_COUNT 16
#define _GPIO_PORT_D_PIN_COUNT 16
#define _GPIO_PORT_E_PIN_COUNT 16
#define _GPIO_PORT_F_PIN_COUNT 15
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_B_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_C_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_D_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_E_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_F_PIN_MASK 0x7FFFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_SILICON_LABS_32B_SERIES_1) && defined(_EFM32_GIANT_FAMILY)

#define _GPIO_PORT_A_PIN_COUNT 16
#define _GPIO_PORT_B_PIN_COUNT 16
#define _GPIO_PORT_C_PIN_COUNT 16
#define _GPIO_PORT_D_PIN_COUNT 16
#define _GPIO_PORT_E_PIN_COUNT 16
#define _GPIO_PORT_F_PIN_COUNT 16
#define _GPIO_PORT_G_PIN_COUNT 16
#define _GPIO_PORT_H_PIN_COUNT 16
#define _GPIO_PORT_I_PIN_COUNT 16
#define _GPIO_PORT_J_PIN_COUNT  0
#define _GPIO_PORT_K_PIN_COUNT  0

#define _GPIO_PORT_A_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_B_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_C_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_D_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_E_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_F_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_G_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_H_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_I_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_SILICON_LABS_GECKO_INTERNAL_SDID_95)

#define _GPIO_PORT_A_PIN_COUNT 6
#define _GPIO_PORT_B_PIN_COUNT 5
#define _GPIO_PORT_C_PIN_COUNT 6
#define _GPIO_PORT_D_PIN_COUNT 7
#define _GPIO_PORT_E_PIN_COUNT 0
#define _GPIO_PORT_F_PIN_COUNT 8
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0x003FUL
#define _GPIO_PORT_B_PIN_MASK 0xF800UL
#define _GPIO_PORT_C_PIN_MASK 0x0FC0UL
#define _GPIO_PORT_D_PIN_MASK 0xFE00UL
#define _GPIO_PORT_E_PIN_MASK 0x0000UL
#define _GPIO_PORT_F_PIN_MASK 0x00FFUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined(_SILICON_LABS_GECKO_INTERNAL_SDID_103)

#define _GPIO_PORT_A_PIN_COUNT 14
#define _GPIO_PORT_B_PIN_COUNT 10
#define _GPIO_PORT_C_PIN_COUNT 16
#define _GPIO_PORT_D_PIN_COUNT 9
#define _GPIO_PORT_E_PIN_COUNT 12
#define _GPIO_PORT_F_PIN_COUNT 6
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK 0xF77FUL
#define _GPIO_PORT_B_PIN_MASK 0x79F8UL
#define _GPIO_PORT_C_PIN_MASK 0xFFFFUL
#define _GPIO_PORT_D_PIN_MASK 0x01FFUL
#define _GPIO_PORT_E_PIN_MASK 0xFFF0UL
#define _GPIO_PORT_F_PIN_MASK 0x003FUL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#elif defined (_SILICON_LABS_32B_SERIES_2)

#define _GPIO_PORT_A_PIN_COUNT GPIO_PA_COUNT
#define _GPIO_PORT_B_PIN_COUNT GPIO_PB_COUNT
#define _GPIO_PORT_C_PIN_COUNT GPIO_PC_COUNT
#define _GPIO_PORT_D_PIN_COUNT GPIO_PD_COUNT
#define _GPIO_PORT_E_PIN_COUNT 0
#define _GPIO_PORT_F_PIN_COUNT 0
#define _GPIO_PORT_G_PIN_COUNT 0
#define _GPIO_PORT_H_PIN_COUNT 0
#define _GPIO_PORT_I_PIN_COUNT 0
#define _GPIO_PORT_J_PIN_COUNT 0
#define _GPIO_PORT_K_PIN_COUNT 0

#define _GPIO_PORT_A_PIN_MASK (GPIO_PA_MASK)
#define _GPIO_PORT_B_PIN_MASK (GPIO_PB_MASK)
#define _GPIO_PORT_C_PIN_MASK (GPIO_PC_MASK)
#define _GPIO_PORT_D_PIN_MASK (GPIO_PD_MASK)
#define _GPIO_PORT_E_PIN_MASK 0x0000UL
#define _GPIO_PORT_F_PIN_MASK 0x0000UL
#define _GPIO_PORT_G_PIN_MASK 0x0000UL
#define _GPIO_PORT_H_PIN_MASK 0x0000UL
#define _GPIO_PORT_I_PIN_MASK 0x0000UL
#define _GPIO_PORT_J_PIN_MASK 0x0000UL
#define _GPIO_PORT_K_PIN_MASK 0x0000UL

#else
#warning "Port and pin masks are not defined for this family."
#endif

#define _GPIO_PORT_SIZE(port) (             \
    (port) == 0  ? _GPIO_PORT_A_PIN_COUNT   \
    : (port) == 1  ? _GPIO_PORT_B_PIN_COUNT \
    : (port) == 2  ? _GPIO_PORT_C_PIN_COUNT \
    : (port) == 3  ? _GPIO_PORT_D_PIN_COUNT \
    : (port) == 4  ? _GPIO_PORT_E_PIN_COUNT \
    : (port) == 5  ? _GPIO_PORT_F_PIN_COUNT \
    : (port) == 6  ? _GPIO_PORT_G_PIN_COUNT \
    : (port) == 7  ? _GPIO_PORT_H_PIN_COUNT \
    : (port) == 8  ? _GPIO_PORT_I_PIN_COUNT \
    : (port) == 9  ? _GPIO_PORT_J_PIN_COUNT \
    : (port) == 10 ? _GPIO_PORT_K_PIN_COUNT \
    : 0)

#define _GPIO_PORT_MASK(port) (                 \
    ((int)port) == 0  ? _GPIO_PORT_A_PIN_MASK   \
    : ((int)port) == 1  ? _GPIO_PORT_B_PIN_MASK \
    : ((int)port) == 2  ? _GPIO_PORT_C_PIN_MASK \
    : ((int)port) == 3  ? _GPIO_PORT_D_PIN_MASK \
    : ((int)port) == 4  ? _GPIO_PORT_E_PIN_MASK \
    : ((int)port) == 5  ? _GPIO_PORT_F_PIN_MASK \
    : ((int)port) == 6  ? _GPIO_PORT_G_PIN_MASK \
    : ((int)port) == 7  ? _GPIO_PORT_H_PIN_MASK \
    : ((int)port) == 8  ? _GPIO_PORT_I_PIN_MASK \
    : ((int)port) == 9  ? _GPIO_PORT_J_PIN_MASK \
    : ((int)port) == 10 ? _GPIO_PORT_K_PIN_MASK \
    : 0UL)

/** Validation of port and pin. */
#define GPIO_PORT_VALID(port)          (_GPIO_PORT_MASK(port) != 0x0UL)
#define GPIO_PORT_PIN_VALID(port, pin) ((((_GPIO_PORT_MASK(port)) >> (pin)) & 0x1UL) == 0x1UL)

#if defined(_GPIO_EXTIPINSELL_MASK)
/** Validation of interrupt number and pin. */
#define GPIO_INTNO_PIN_VALID(intNo, pin)           \
  (((intNo) & ~_GPIO_EXTIPINSELL_EXTIPINSEL0_MASK) \
   == ((pin) & ~_GPIO_EXTIPINSELL_EXTIPINSEL0_MASK))
#endif

/** Highest GPIO pin number. */
#define GPIO_PIN_MAX  15

/** Highest GPIO port number. */
#if (_GPIO_PORT_K_PIN_COUNT > 0)
#define GPIO_PORT_MAX  10
#elif (_GPIO_PORT_J_PIN_COUNT > 0)
#define GPIO_PORT_MAX  9
#elif (_GPIO_PORT_I_PIN_COUNT > 0)
#define GPIO_PORT_MAX  8
#elif (_GPIO_PORT_H_PIN_COUNT > 0)
#define GPIO_PORT_MAX  7
#elif (_GPIO_PORT_G_PIN_COUNT > 0)
#define GPIO_PORT_MAX  6
#elif (_GPIO_PORT_F_PIN_COUNT > 0)
#define GPIO_PORT_MAX  5
#elif (_GPIO_PORT_E_PIN_COUNT > 0)
#define GPIO_PORT_MAX  4
#elif (_GPIO_PORT_D_PIN_COUNT > 0)
#define GPIO_PORT_MAX  3
#else
#error "Max GPIO port number is undefined for this part."
#endif

/** Highest EXT GPIO interrupt number. */
#define GPIO_EXTINTNO_MAX   15

/***************************************************************************//**
 * @addtogroup gpio GPIO - General Purpose Input/Output
 * @{
 ******************************************************************************/

/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/** GPIO ports IDs. */
SL_ENUM(GPIO_Port_TypeDef) {
#if (_GPIO_PORT_A_PIN_COUNT > 0)
  /** Port A. */
  gpioPortA = 0,
#endif
#if (_GPIO_PORT_B_PIN_COUNT > 0)
  /** Port B. */
  gpioPortB = 1,
#endif
#if (_GPIO_PORT_C_PIN_COUNT > 0)
  /** Port C. */
  gpioPortC = 2,
#endif
#if (_GPIO_PORT_D_PIN_COUNT > 0)
  /** Port D. */
  gpioPortD = 3,
#endif
#if (_GPIO_PORT_E_PIN_COUNT > 0)
  /** Port E. */
  gpioPortE = 4,
#endif
#if (_GPIO_PORT_F_PIN_COUNT > 0)
  /** Port F. */
  gpioPortF = 5,
#endif
#if (_GPIO_PORT_G_PIN_COUNT > 0)
  /** Port G. */
  gpioPortG = 6,
#endif
#if (_GPIO_PORT_H_PIN_COUNT > 0)
  /** Port H. */
  gpioPortH = 7,
#endif
#if (_GPIO_PORT_I_PIN_COUNT > 0)
  /** Port I. */
  gpioPortI = 8,
#endif
#if (_GPIO_PORT_J_PIN_COUNT > 0)
  /** Port J. */
  gpioPortJ = 9,
#endif
#if (_GPIO_PORT_K_PIN_COUNT > 0)
  /** Port K. */
  gpioPortK = 10,
#endif
};

/** Mapping between SL_GPIO_PORT_ enums and gpioPort values. */
#if !defined(SL_CATALOG_GPIO_PRESENT)
#if (_GPIO_PORT_A_PIN_COUNT > 0)
#define SL_GPIO_PORT_A gpioPortA
#endif
#if (_GPIO_PORT_B_PIN_COUNT > 0)
#define SL_GPIO_PORT_B gpioPortB
#endif
#if (_GPIO_PORT_C_PIN_COUNT > 0)
#define SL_GPIO_PORT_C gpioPortC
#endif
#if (_GPIO_PORT_D_PIN_COUNT > 0)
#define SL_GPIO_PORT_D gpioPortD
#endif
#if (_GPIO_PORT_E_PIN_COUNT > 0)
#define SL_GPIO_PORT_E gpioPortE
#endif
#if (_GPIO_PORT_F_PIN_COUNT > 0)
#define SL_GPIO_PORT_F gpioPortF
#endif
#if (_GPIO_PORT_G_PIN_COUNT > 0)
#define SL_GPIO_PORT_G gpioPortG
#endif
#if (_GPIO_PORT_H_PIN_COUNT > 0)
#define SL_GPIO_PORT_H gpioPortH
#endif
#if (_GPIO_PORT_I_PIN_COUNT > 0)
#define SL_GPIO_PORT_I gpioPortI
#endif
#if (_GPIO_PORT_J_PIN_COUNT > 0)
#define SL_GPIO_PORT_J gpioPortJ
#endif
#if (_GPIO_PORT_K_PIN_COUNT > 0)
#define SL_GPIO_PORT_K gpioPortK
#endif
#endif  // !defined(SL_CATALOG_GPIO_PRESENT)

#if defined(_GPIO_P_CTRL_DRIVEMODE_MASK)
/** GPIO drive mode. */
SL_ENUM_GENERIC(GPIO_DriveMode_TypeDef, uint32_t) {
  /** Default 6mA. */
  gpioDriveModeStandard = GPIO_P_CTRL_DRIVEMODE_STANDARD,
  /** 0.5 mA. */
  gpioDriveModeLowest   = GPIO_P_CTRL_DRIVEMODE_LOWEST,
  /** 20 mA. */
  gpioDriveModeHigh     = GPIO_P_CTRL_DRIVEMODE_HIGH,
  /** 2 mA. */
  gpioDriveModeLow      = GPIO_P_CTRL_DRIVEMODE_LOW
};
#endif

#if defined(_GPIO_P_CTRL_DRIVESTRENGTH_MASK) && defined(_GPIO_P_CTRL_DRIVESTRENGTHALT_MASK)
/** GPIO drive strength. */
SL_ENUM_GENERIC(GPIO_DriveStrength_TypeDef, uint32_t) {
  /** GPIO weak 1mA and alternate function weak 1mA. */
  gpioDriveStrengthWeakAlternateWeak     = GPIO_P_CTRL_DRIVESTRENGTH_WEAK | GPIO_P_CTRL_DRIVESTRENGTHALT_WEAK,

  /** GPIO weak 1mA and alternate function strong 10mA. */
  gpioDriveStrengthWeakAlternateStrong   = GPIO_P_CTRL_DRIVESTRENGTH_WEAK | GPIO_P_CTRL_DRIVESTRENGTHALT_STRONG,

  /** GPIO strong 10mA and alternate function weak 1mA. */
  gpioDriveStrengthStrongAlternateWeak   = GPIO_P_CTRL_DRIVESTRENGTH_STRONG | GPIO_P_CTRL_DRIVESTRENGTHALT_WEAK,

  /** GPIO strong 10mA and alternate function strong 10mA. */
  gpioDriveStrengthStrongAlternateStrong = GPIO_P_CTRL_DRIVESTRENGTH_STRONG | GPIO_P_CTRL_DRIVESTRENGTHALT_STRONG,
};

/* Deprecated enums. */
/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */
#define gpioDriveStrengthStrong   gpioDriveStrengthStrongAlternateStrong
#define gpioDriveStrengthWeak     gpioDriveStrengthWeakAlternateWeak
/** @endcond */
#endif

/** Pin mode. For more details on each mode, refer to the
 * reference manual. */
SL_ENUM_GENERIC(GPIO_Mode_TypeDef, uint32_t) {
  /** Input disabled. Pull-up if DOUT is set. */
  gpioModeDisabled                  = _GPIO_P_MODEL_MODE0_DISABLED,
  /** Input enabled. Filter if DOUT is set. */
  gpioModeInput                     = _GPIO_P_MODEL_MODE0_INPUT,
  /** Input enabled. DOUT determines pull direction. */
  gpioModeInputPull                 = _GPIO_P_MODEL_MODE0_INPUTPULL,
  /** Input enabled with filter. DOUT determines pull direction. */
  gpioModeInputPullFilter           = _GPIO_P_MODEL_MODE0_INPUTPULLFILTER,
  /** Push-pull output. */
  gpioModePushPull                  = _GPIO_P_MODEL_MODE0_PUSHPULL,
#if defined(_GPIO_P_MODEL_MODE0_PUSHPULLDRIVE)
  /** Push-pull output with drive-strength set by DRIVEMODE. */
  gpioModePushPullDrive             = _GPIO_P_MODEL_MODE0_PUSHPULLDRIVE,
#endif
#if defined(_GPIO_P_MODEL_MODE0_PUSHPULLALT)
  /** Push-pull using alternate control. */
  gpioModePushPullAlternate       = _GPIO_P_MODEL_MODE0_PUSHPULLALT,
#endif
  /** Wired-or output. */
  gpioModeWiredOr                       = _GPIO_P_MODEL_MODE0_WIREDOR,
  /** Wired-or output with pull-down. */
  gpioModeWiredOrPullDown               = _GPIO_P_MODEL_MODE0_WIREDORPULLDOWN,
  /** Open-drain output. */
  gpioModeWiredAnd                      = _GPIO_P_MODEL_MODE0_WIREDAND,
  /** Open-drain output with filter. */
  gpioModeWiredAndFilter                = _GPIO_P_MODEL_MODE0_WIREDANDFILTER,
  /** Open-drain output with pull-up. */
  gpioModeWiredAndPullUp                = _GPIO_P_MODEL_MODE0_WIREDANDPULLUP,
  /** Open-drain output with filter and pull-up. */
  gpioModeWiredAndPullUpFilter          = _GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER,
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDDRIVE)
  /** Open-drain output with drive-strength set by DRIVEMODE. */
  gpioModeWiredAndDrive                 = _GPIO_P_MODEL_MODE0_WIREDANDDRIVE,
  /** Open-drain output with filter and drive-strength set by DRIVEMODE. */
  gpioModeWiredAndDriveFilter           = _GPIO_P_MODEL_MODE0_WIREDANDDRIVEFILTER,
  /** Open-drain output with pull-up and drive-strength set by DRIVEMODE. */
  gpioModeWiredAndDrivePullUp           = _GPIO_P_MODEL_MODE0_WIREDANDDRIVEPULLUP,
  /** Open-drain output with filter, pull-up and drive-strength set by DRIVEMODE. */
  gpioModeWiredAndDrivePullUpFilter     = _GPIO_P_MODEL_MODE0_WIREDANDDRIVEPULLUPFILTER
#endif
#if defined(_GPIO_P_MODEL_MODE0_WIREDANDALT)
  /** Open-drain output using alternate control. */
  gpioModeWiredAndAlternate             = _GPIO_P_MODEL_MODE0_WIREDANDALT,
  /** Open-drain output using alternate control with filter. */
  gpioModeWiredAndAlternateFilter       = _GPIO_P_MODEL_MODE0_WIREDANDALTFILTER,
  /** Open-drain output using alternate control with pull-up. */
  gpioModeWiredAndAlternatePullUp       = _GPIO_P_MODEL_MODE0_WIREDANDALTPULLUP,
  /** Open-drain output using alternate control with filter and pull-up. */
  gpioModeWiredAndAlternatePullUpFilter = _GPIO_P_MODEL_MODE0_WIREDANDALTPULLUPFILTER,
#endif
};

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

void GPIO_DbgLocationSet(unsigned int location);

/***************************************************************************//**
 * @brief
 *   Enable/disable serial wire clock pin.
 *
 * @note
 *   Disabling SWDClk will disable the debug interface, which may result in
 *   a lockout if done early in startup (before debugger is able to halt core).
 *
 * @param[in] enable
 *   @li false - disable serial wire clock.
 *   @li true - enable serial wire clock (default after reset).
 ******************************************************************************/
__STATIC_INLINE void GPIO_DbgSWDClkEnable(bool enable)
{
  unsigned int bit = enable ? 0x1UL : 0x0UL;

#if defined(_GPIO_ROUTE_SWCLKPEN_MASK)
  BUS_RegBitWrite(&(GPIO->ROUTE), _GPIO_ROUTE_SWCLKPEN_SHIFT, bit);
#elif defined(_GPIO_ROUTEPEN_SWCLKTCKPEN_MASK)
  BUS_RegBitWrite(&(GPIO->ROUTEPEN), _GPIO_ROUTEPEN_SWCLKTCKPEN_SHIFT, bit);
#elif defined(_GPIO_DBGROUTEPEN_SWCLKTCKPEN_MASK)
  BUS_RegBitWrite(&(GPIO->DBGROUTEPEN), _GPIO_DBGROUTEPEN_SWCLKTCKPEN_SHIFT, bit);
#else
#warning "ROUTE enable for SWCLK pin is not defined."
#endif
}

/***************************************************************************//**
 * @brief
 *   Enable/disable serial wire data I/O pin.
 *
 * @note
 *   Disabling SWDClk will disable the debug interface, which may result in
 *   a lockout if done early in startup (before debugger is able to halt core).
 *
 * @param[in] enable
 *   @li false - disable serial wire data pin.
 *   @li true - enable serial wire data pin (default after reset).
 ******************************************************************************/
__STATIC_INLINE void GPIO_DbgSWDIOEnable(bool enable)
{
  unsigned int bit = enable ? 0x1UL : 0x0UL;

#if defined(_GPIO_ROUTE_SWDIOPEN_MASK)
  BUS_RegBitWrite(&(GPIO->ROUTE), _GPIO_ROUTE_SWDIOPEN_SHIFT, bit);
#elif defined(_GPIO_ROUTEPEN_SWDIOTMSPEN_MASK)
  BUS_RegBitWrite(&(GPIO->ROUTEPEN), _GPIO_ROUTEPEN_SWDIOTMSPEN_SHIFT, bit);
#elif defined(_GPIO_DBGROUTEPEN_SWDIOTMSPEN_MASK)
  BUS_RegBitWrite(&(GPIO->DBGROUTEPEN), _GPIO_DBGROUTEPEN_SWDIOTMSPEN_SHIFT, bit);
#else
#warning "ROUTE enable for SWDIO pin is not defined."
#endif
}

#if defined(_GPIO_ROUTE_SWOPEN_MASK) || defined(_GPIO_ROUTEPEN_SWVPEN_MASK) \
  || defined(_GPIO_TRACEROUTEPEN_SWVPEN_MASK)
/***************************************************************************//**
 * @brief
 *   Enable/Disable serial wire output pin.
 *
 * @note
 *   Enabling this pin is not sufficient to fully enable serial wire output,
 *   which is also dependent on issues outside the GPIO module. Refer to
 *   DBG_SWOEnable().
 *
 * @warning
 *   If debug port is locked, SWO pin is not disabled automatically. To avoid
 *   information leakage through SWO, disable SWO pin after locking debug port.
 *
 * @param[in] enable
 *   @li false - disable serial wire viewer pin (default after reset).
 *   @li true - enable serial wire viewer pin.
 ******************************************************************************/
__STATIC_INLINE void GPIO_DbgSWOEnable(bool enable)
{
  unsigned int bit = enable ? 0x1UL : 0x0UL;

#if defined(_GPIO_ROUTE_SWOPEN_MASK)
  BUS_RegBitWrite(&(GPIO->ROUTE), _GPIO_ROUTE_SWOPEN_SHIFT, bit);
#elif defined(_GPIO_ROUTEPEN_SWVPEN_MASK)
  BUS_RegBitWrite(&(GPIO->ROUTEPEN), _GPIO_ROUTEPEN_SWVPEN_SHIFT, bit);
#elif defined(_GPIO_TRACEROUTEPEN_SWVPEN_MASK)
  BUS_RegBitWrite(&(GPIO->TRACEROUTEPEN), _GPIO_TRACEROUTEPEN_SWVPEN_SHIFT, bit);
#else
#warning "ROUTE enable for SWO/SWV pin is not defined."
#endif
}
#endif

#if defined (_GPIO_P_CTRL_DRIVEMODE_MASK)
void GPIO_DriveModeSet(GPIO_Port_TypeDef port, GPIO_DriveMode_TypeDef mode);
#endif

#if defined(_GPIO_P_CTRL_DRIVESTRENGTH_MASK)
void GPIO_DriveStrengthSet(GPIO_Port_TypeDef port, GPIO_DriveStrength_TypeDef strength);
#endif

# if defined(_GPIO_EM4WUEN_MASK)
/**************************************************************************//**
 * @brief
 *   Disable GPIO pin wake-up from EM4.
 *
 * @param[in] pinmask
 *   Bit mask containing the bitwise logic OR of which GPIO pin(s) to disable.
 *   Refer to Reference Manuals for pinmask to GPIO port/pin mapping.
 *****************************************************************************/
__STATIC_INLINE void GPIO_EM4DisablePinWakeup(uint32_t pinmask)
{
  EFM_ASSERT((pinmask & ~_GPIO_EM4WUEN_MASK) == 0UL);
#if defined(GPIO_HAS_SET_CLEAR)
  GPIO->EM4WUEN_CLR = pinmask;
#else
  GPIO->EM4WUEN &= ~pinmask;
#endif
}
#endif

# if defined(_GPIO_EM4WUEN_MASK)
void GPIO_EM4EnablePinWakeup(uint32_t pinmask, uint32_t polaritymask);
#endif

#if defined(_GPIO_EM4WUCAUSE_MASK) || defined(_GPIO_IF_EM4WU_MASK)
/**************************************************************************//**
 * @brief
 *   Check which GPIO pin(s) that caused a wake-up from EM4.
 *
 * @return
 *   Bit mask containing the bitwise logic OR of which GPIO pin(s) caused the
 *   wake-up. Refer to Reference Manuals for pinmask to GPIO port/pin mapping.
 *****************************************************************************/
__STATIC_INLINE uint32_t GPIO_EM4GetPinWakeupCause(void)
{
#if defined(_GPIO_EM4WUCAUSE_MASK)
  return GPIO->EM4WUCAUSE & _GPIO_EM4WUCAUSE_MASK;
#else
  return GPIO->IF & _GPIO_IF_EM4WU_MASK;
#endif
}
#endif

#if defined(GPIO_CTRL_EM4RET) || defined(_EMU_EM4CTRL_EM4IORETMODE_MASK)
/**************************************************************************//**
 * @brief
 *   Enable GPIO pin retention of output enable, output value, pull enable, and
 *   pull direction in EM4.
 *
 * @note
 *   On series 0 devices EM4 gpio retention can either be turned on or off. On
 *   series 1 devices there are three EM4 GPIO retention modes available. These
 *   modes are "Disabled", "EM4EXIT" and "SWUNLATCH". Use the EMU_EM4Init()
 *   to configure the GPIO retention mode on a series 1 device.
 *
 *   The behavior of this function depends on the configured GPIO retention mode.
 *   If the GPIO retention mode is configured to be "SWUNLATCH" then this
 *   function will not change anything. If the retention mode is anything else
 *   then this function will set the GPIO retention mode to "EM4EXIT" when the
 *   enable argument is true, and "Disabled" when false.
 *
 * @param[in] enable
 *   @li true - enable EM4 pin retention.
 *   @li false - disable EM4 pin retention.
 *****************************************************************************/
__STATIC_INLINE void GPIO_EM4SetPinRetention(bool enable)
{
#if defined(GPIO_CTRL_EM4RET)
  BUS_RegBitWrite(&GPIO->CTRL, _GPIO_CTRL_EM4RET_SHIFT, enable);
#else

  // Leave configuration alone when software unlatch is used.
  uint32_t mode = EMU->EM4CTRL & _EMU_EM4CTRL_EM4IORETMODE_MASK;
  if (mode == EMU_EM4CTRL_EM4IORETMODE_SWUNLATCH) {
    return;
  }

  if (enable) {
    EMU->EM4CTRL = (EMU->EM4CTRL & ~_EMU_EM4CTRL_EM4IORETMODE_MASK)
                   | EMU_EM4CTRL_EM4IORETMODE_EM4EXIT;
  } else {
    EMU->EM4CTRL = (EMU->EM4CTRL & ~_EMU_EM4CTRL_EM4IORETMODE_MASK)
                   | EMU_EM4CTRL_EM4IORETMODE_DISABLE;
  }
#endif
}
#endif

void GPIO_ExtIntConfig(GPIO_Port_TypeDef port,
                       unsigned int pin,
                       unsigned int intNo,
                       bool risingEdge,
                       bool fallingEdge,
                       bool enable);

#if _SILICON_LABS_32B_SERIES > 0
void GPIO_EM4WUExtIntConfig(GPIO_Port_TypeDef port,
                            unsigned int pin,
                            uint32_t intNo,
                            bool polarity,
                            bool enable);
#endif
/***************************************************************************//**
 * @brief
 *   Enable/disable input sensing.
 *
 * @details
 *   Disabling input sensing if not used, can save some energy consumption.
 *
 * @param[in] val
 *   Bitwise logic OR of one or more of:
 *   @li GPIO_INSENSE_INT - interrupt input sensing.
 *   @li GPIO_INSENSE_PRS - peripheral reflex system input sensing.
 *
 * @param[in] mask
 *   Mask containing bitwise logic OR of bits similar as for @p val used to
 *   indicate which input sense options to disable/enable.
 ******************************************************************************/
__STATIC_INLINE void GPIO_InputSenseSet(uint32_t val, uint32_t mask)
{
#if defined(_GPIO_INSENSE_MASK)
  BUS_RegMaskedWrite(&(GPIO->INSENSE), mask, val);
#else
  (void) val;
  (void) mask;
#endif
}

/***************************************************************************//**
 * @brief
 *   Clear one or more pending GPIO interrupts.
 *
 * @param[in] flags
 *   Bitwise logic OR of GPIO interrupt sources to clear.
 ******************************************************************************/
__STATIC_INLINE void GPIO_IntClear(uint32_t flags)
{
#if defined(GPIO_HAS_SET_CLEAR)
  GPIO->IF_CLR = flags;
#else
  GPIO->IFC = flags;
#endif
}

/***************************************************************************//**
 * @brief
 *   Disable one or more GPIO interrupts.
 *
 * @param[in] flags
 *   GPIO interrupt sources to disable.
 ******************************************************************************/
__STATIC_INLINE void GPIO_IntDisable(uint32_t flags)
{
  BUS_RegMaskedClear(&(GPIO->IEN), flags);
}

/***************************************************************************//**
 * @brief
 *   Enable one or more GPIO interrupts.
 *
 * @note
 *   Depending on the use, a pending interrupt may already be set prior to
 *   enabling the interrupt. To ignore a pending interrupt, consider using
 *   GPIO_IntClear() prior to enabling the interrupt.
 *
 * @param[in] flags
 *   GPIO interrupt sources to enable.
 ******************************************************************************/
__STATIC_INLINE void GPIO_IntEnable(uint32_t flags)
{
  BUS_RegMaskedSet(&(GPIO->IEN), flags);
}

/***************************************************************************//**
 * @brief
 *   Get enabled GPIO interrupts.
 *
 * @return
 *   Enabled GPIO interrupt sources.
 *
 ******************************************************************************/
__STATIC_INLINE uint32_t GPIO_EnabledIntGet(void)
{
  return GPIO->IEN;
}

/***************************************************************************//**
 * @brief
 *   Get pending GPIO interrupts.
 *
 * @return
 *   GPIO interrupt sources pending.
 ******************************************************************************/
__STATIC_INLINE uint32_t GPIO_IntGet(void)
{
  return GPIO->IF;
}

/***************************************************************************//**
 * @brief
 *   Get enabled and pending GPIO interrupt flags.
 *   Useful for handling more interrupt sources in the same interrupt handler.
 *
 * @note
 *   Interrupt flags are not cleared by the use of this function.
 *
 * @return
 *   Pending and enabled GPIO interrupt sources.
 *   The return value is the bitwise AND combination of
 *   - the OR combination of enabled interrupt sources in GPIO_IEN register
 *     and
 *   - the OR combination of valid interrupt flags in GPIO_IF register.
 ******************************************************************************/
__STATIC_INLINE uint32_t GPIO_IntGetEnabled(void)
{
  uint32_t tmp;

  /* Store GPIO->IEN in temporary variable in order to define explicit order
   * of volatile accesses. */
  tmp = GPIO->IEN;

  /* Bitwise AND of pending and enabled interrupts */
  return GPIO->IF & tmp;
}

/**************************************************************************//**
 * @brief
 *   Set one or more pending GPIO interrupts from SW.
 *
 * @param[in] flags
 *   GPIO interrupt sources to set to pending.
 *****************************************************************************/
__STATIC_INLINE void GPIO_IntSet(uint32_t flags)
{
#if defined (GPIO_HAS_SET_CLEAR)
  GPIO->IF_SET = flags;
#else
  GPIO->IFS = flags;
#endif
}

/***************************************************************************//**
 * @brief
 *   Lock the GPIO configuration.
 ******************************************************************************/
__STATIC_INLINE void GPIO_Lock(void)
{
  GPIO->LOCK = ~GPIO_LOCK_LOCKKEY_UNLOCK;
}

/***************************************************************************//**
 * @brief
 *   Read the pad value for a single pin in a GPIO port.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pin
 *   The pin number to read.
 *
 * @return
 *   The pin value, 0 or 1.
 ******************************************************************************/
__STATIC_INLINE unsigned int GPIO_PinInGet(GPIO_Port_TypeDef port,
                                           unsigned int pin)
{
  EFM_ASSERT(GPIO_PORT_PIN_VALID(port, pin));
  return BUS_RegBitRead(&GPIO->P[port].DIN, pin);
}

#if defined (_GPIO_P_PINLOCKN_MASK)
/***************************************************************************//**
 * @brief
 *   Lock all GPIO configuration settings for a given pin.
 *   The lock can only be cleared by a chip reset.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pin
 *   The pin number to lock.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PinLock(GPIO_Port_TypeDef port, unsigned int pin)
{
  BUS_RegBitWrite(&GPIO->P[port].PINLOCKN, pin, 0);
}
#endif

GPIO_Mode_TypeDef GPIO_PinModeGet(GPIO_Port_TypeDef port,
                                  unsigned int pin);

void GPIO_PinModeSet(GPIO_Port_TypeDef port,
                     unsigned int pin,
                     GPIO_Mode_TypeDef mode,
                     unsigned int out);

/***************************************************************************//**
 * @brief
 *   Set a single pin in GPIO data out port register to 0.
 *
 * @note
 *   To ensure that the setting takes effect on the output pad, the pin must
 *   be configured properly. If not, it will take effect whenever the
 *   pin has been properly configured.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pin
 *   The pin to set.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PinOutClear(GPIO_Port_TypeDef port, unsigned int pin)
{
  EFM_ASSERT(GPIO_PORT_PIN_VALID(port, pin));
#if defined(_GPIO_P_DOUTCLR_MASK)
  GPIO->P[port].DOUTCLR = 1UL << pin;
#elif defined(GPIO_HAS_SET_CLEAR)
  GPIO->P_CLR[port].DOUT = 1UL << pin;
#else
  BUS_RegMaskedClear(&GPIO->P[port].DOUT, 1UL << pin);
#endif
}

/***************************************************************************//**
 * @brief
 *   Get current setting for a pin in a GPIO port data out register.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pin
 *   The pin to get setting for.
 *
 * @return
 *   The DOUT setting for the requested pin, 0 or 1.
 ******************************************************************************/
__STATIC_INLINE unsigned int GPIO_PinOutGet(GPIO_Port_TypeDef port,
                                            unsigned int pin)
{
  EFM_ASSERT(GPIO_PORT_PIN_VALID(port, pin));
  return BUS_RegBitRead(&GPIO->P[port].DOUT, pin);
}

/***************************************************************************//**
 * @brief
 *   Set a single pin in GPIO data out register to 1.
 *
 * @note
 *   To ensure that the setting takes effect on the output pad, the pin must
 *   be configured properly. If not, it will take effect whenever the
 *   pin has been properly configured.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pin
 *   The pin to set.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PinOutSet(GPIO_Port_TypeDef port, unsigned int pin)
{
  EFM_ASSERT(GPIO_PORT_PIN_VALID(port, pin));
#if defined(_GPIO_P_DOUTSET_MASK)
  GPIO->P[port].DOUTSET = 1UL << pin;
#elif defined(GPIO_HAS_SET_CLEAR)
  GPIO->P_SET[port].DOUT = 1UL << pin;
#else
  BUS_RegMaskedSet(&GPIO->P[port].DOUT, 1UL << pin);
#endif
}

/***************************************************************************//**
 * @brief
 *   Toggle a single pin in GPIO port data out register.
 *
 * @note
 *   To ensure that the setting takes effect on the output pad, the pin must
 *   be configured properly. If not, it will take effect whenever the
 *   pin has been properly configured.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pin
 *   The pin to toggle.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PinOutToggle(GPIO_Port_TypeDef port, unsigned int pin)
{
  EFM_ASSERT(GPIO_PORT_PIN_VALID(port, pin));

#if defined (_GPIO_P_DOUTTGL_MASK)
  GPIO->P[port].DOUTTGL = 1UL << pin;
#elif defined(GPIO_HAS_SET_CLEAR)
  GPIO->P_TGL[port].DOUT = 1UL << pin;
#else
  GPIO->P[port].DOUT ^= 1UL << pin;
#endif
}

/***************************************************************************//**
 * @brief
 *   Read the pad values for GPIO port.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @return
 *   The pad values for the GPIO port.
 ******************************************************************************/
__STATIC_INLINE uint32_t GPIO_PortInGet(GPIO_Port_TypeDef port)
{
  EFM_ASSERT(GPIO_PORT_VALID(port));

  return GPIO->P[port].DIN;
}

/***************************************************************************//**
 * @brief
 *   Set bits in DOUT register for a port to 0.
 *
 * @note
 *   To ensure that the setting takes effect on the output pad, the pin must
 *   be configured properly. If not, it will take effect whenever the
 *   pin has been properly configured.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pins
 *   Bit mask for bits to clear in DOUT register.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PortOutClear(GPIO_Port_TypeDef port, uint32_t pins)
{
  EFM_ASSERT(GPIO_PORT_VALID(port));
#if defined(_GPIO_P_DOUTCLR_MASK)
  GPIO->P[port].DOUTCLR = pins;
#elif defined(GPIO_HAS_SET_CLEAR)
  GPIO->P_CLR[port].DOUT = pins;
#else
  BUS_RegMaskedClear(&GPIO->P[port].DOUT, pins);
#endif
}

/***************************************************************************//**
 * @brief
 *   Get the current setting for a GPIO port data out register.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @return
 *   The data out setting for the requested port.
 ******************************************************************************/
__STATIC_INLINE uint32_t GPIO_PortOutGet(GPIO_Port_TypeDef port)
{
  EFM_ASSERT(GPIO_PORT_VALID(port));

  return GPIO->P[port].DOUT;
}

/***************************************************************************//**
 * @brief
 *   Set bits GPIO data out register to 1.
 *
 * @note
 *   To ensure that the setting takes effect on the respective output pads, the
 *   pins must be configured properly. If not, it will take effect
 *   whenever the pin has been properly configured.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pins
 *   Bit mask for bits to set to 1 in DOUT register.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PortOutSet(GPIO_Port_TypeDef port, uint32_t pins)
{
  EFM_ASSERT(GPIO_PORT_VALID(port));
#if defined(_GPIO_P_DOUTSET_MASK)
  GPIO->P[port].DOUTSET = pins;
#elif defined(GPIO_HAS_SET_CLEAR)
  GPIO->P_SET[port].DOUT = pins;
#else
  BUS_RegMaskedSet(&GPIO->P[port].DOUT, pins);
#endif
}

/***************************************************************************//**
 * @brief
 *   Set GPIO port data out register.
 *
 * @note
 *   To ensure that the setting takes effect on the respective output pads, the
 *   pins must be configured properly. If not, it will take effect
 *   whenever the pin has been properly configured.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] val
 *   Value to write to port data out register.
 *
 * @param[in] mask
 *   Mask indicating which bits to modify.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PortOutSetVal(GPIO_Port_TypeDef port,
                                        uint32_t val,
                                        uint32_t mask)
{
  EFM_ASSERT(GPIO_PORT_VALID(port));

  GPIO->P[port].DOUT = (GPIO->P[port].DOUT & ~mask) | (val & mask);
}

/***************************************************************************//**
 * @brief
 *   Toggle pins in GPIO port data out register.
 *
 * @note
 *   To ensure that the setting takes effect on the output pad, the pin must
 *   be configured properly. If not, it will take effect whenever the
 *   pin has been properly configured.
 *
 * @param[in] port
 *   The GPIO port to access.
 *
 * @param[in] pins
 *   Bit mask with pins to toggle.
 ******************************************************************************/
__STATIC_INLINE void GPIO_PortOutToggle(GPIO_Port_TypeDef port, uint32_t pins)
{
  EFM_ASSERT(GPIO_PORT_VALID(port));
#if defined (GPIO_HAS_SET_CLEAR)
  GPIO->P_TGL[port].DOUT = pins;
#else
  GPIO->P[port].DOUTTGL = pins;
#endif
}

#if defined(_GPIO_P_CTRL_SLEWRATE_MASK)
/***************************************************************************//**
 * @brief
 *   Set slewrate for pins on a GPIO port.
 *
 * @param[in] port
 *   The GPIO port to configure.
 *
 * @param[in] slewrate
 *   The slewrate to configure for pins on this GPIO port.
 *
 * @param[in] slewrateAlt
 *   The slewrate to configure for pins using alternate modes on this GPIO port.
 ******************************************************************************/
__STATIC_INLINE void GPIO_SlewrateSet(GPIO_Port_TypeDef port,
                                      uint32_t slewrate,
                                      uint32_t slewrateAlt)
{
  EFM_ASSERT(GPIO_PORT_VALID(port));
  EFM_ASSERT(slewrate <= (_GPIO_P_CTRL_SLEWRATE_MASK
                          >> _GPIO_P_CTRL_SLEWRATE_SHIFT));
  EFM_ASSERT(slewrateAlt <= (_GPIO_P_CTRL_SLEWRATEALT_MASK
                             >> _GPIO_P_CTRL_SLEWRATEALT_SHIFT));

  GPIO->P[port].CTRL = (GPIO->P[port].CTRL
                        & ~(_GPIO_P_CTRL_SLEWRATE_MASK
                            | _GPIO_P_CTRL_SLEWRATEALT_MASK))
                       | (slewrate << _GPIO_P_CTRL_SLEWRATE_SHIFT)
                       | (slewrateAlt << _GPIO_P_CTRL_SLEWRATEALT_SHIFT);
}
#endif

/***************************************************************************//**
 * @brief
 *   Unlock the GPIO configuration.
 ******************************************************************************/
__STATIC_INLINE void GPIO_Unlock(void)
{
  GPIO->LOCK = GPIO_LOCK_LOCKKEY_UNLOCK;
}

/** @} (end addtogroup gpio) */

#ifdef __cplusplus
}
#endif

#endif /* defined(GPIO_COUNT) && (GPIO_COUNT > 0) */
#endif /* EM_GPIO_H */
