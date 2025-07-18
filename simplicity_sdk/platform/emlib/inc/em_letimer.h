/***************************************************************************//**
 * @file
 * @brief Low Energy Timer (LETIMER) peripheral API
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

#ifndef EM_LETIMER_H
#define EM_LETIMER_H

#include <stdbool.h>
#include "em_device.h"
#if defined(LETIMER_COUNT) && (LETIMER_COUNT > 0)

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup letimer LETIMER - Low Energy Timer
 * @{
 ******************************************************************************/

/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/** Repeat mode. */
typedef enum {
  /** Count until stopped by SW. */
  letimerRepeatFree     = _LETIMER_CTRL_REPMODE_FREE,
  /** Count REP0 times. */
  letimerRepeatOneshot  = _LETIMER_CTRL_REPMODE_ONESHOT,
  /**
   * Count REP0 times, if REP1 has been written to, it is loaded into
   * REP0 when REP0 is about to be decremented to 0.
   */
  letimerRepeatBuffered = _LETIMER_CTRL_REPMODE_BUFFERED,
  /**
   * Run as long as both REP0 and REP1 are not 0. Both REP0 and REP1
   * are decremented when counter underflows.
   */
  letimerRepeatDouble   = _LETIMER_CTRL_REPMODE_DOUBLE
} LETIMER_RepeatMode_TypeDef;

/** Underflow action on output. */
typedef enum {
  /** No output action. */
  letimerUFOANone   = _LETIMER_CTRL_UFOA0_NONE,
  /** Toggle output when counter underflows. */
  letimerUFOAToggle = _LETIMER_CTRL_UFOA0_TOGGLE,
  /** Hold output one LETIMER clock cycle when counter underflows. */
  letimerUFOAPulse  = _LETIMER_CTRL_UFOA0_PULSE,
  /** Set output idle when counter underflows, and active when matching COMP1. */
  letimerUFOAPwm    = _LETIMER_CTRL_UFOA0_PWM
} LETIMER_UFOA_TypeDef;

/*******************************************************************************
 *******************************   STRUCTS   ***********************************
 ******************************************************************************/

/** LETIMER initialization structure. */
typedef struct {
  bool                       enable;         /**< Start counting when initialization completes. */
  bool                       debugRun;       /**< Counter shall keep running during debug halt. */
#if defined(LETIMER_CTRL_RTCC0TEN)
  bool                       rtcComp0Enable; /**< Start counting on RTC COMP0 match. */
  bool                       rtcComp1Enable; /**< Start counting on RTC COMP1 match. */
#endif
  bool                       comp0Top;       /**< Load COMP0 register into CNT when counter underflows. */
  bool                       bufTop;         /**< Load COMP1 into COMP0 when REP0 reaches 0. */
  uint8_t                    out0Pol;        /**< Idle value for output 0. */
  uint8_t                    out1Pol;        /**< Idle value for output 1. */
  LETIMER_UFOA_TypeDef       ufoa0;          /**< Underflow output 0 action. */
  LETIMER_UFOA_TypeDef       ufoa1;          /**< Underflow output 1 action. */
  LETIMER_RepeatMode_TypeDef repMode;        /**< Repeat mode. */
  uint32_t                   topValue;       /**< Top value. Counter wraps when top value matches counter value is reached. */
} LETIMER_Init_TypeDef;

/** Default configuration for LETIMER initialization structure. */
#if defined(LETIMER_CTRL_RTCC0TEN)
#define LETIMER_INIT_DEFAULT                                                   \
  {                                                                            \
    true,              /* Enable timer when initialization completes. */       \
    false,             /* Stop counter during debug halt. */                   \
    false,             /* Do not start counting on RTC COMP0 match. */         \
    false,             /* Do not start counting on RTC COMP1 match. */         \
    false,             /* Do not load COMP0 into CNT on underflow. */          \
    false,             /* Do not load COMP1 into COMP0 when REP0 reaches 0. */ \
    0,                 /* Idle value 0 for output 0. */                        \
    0,                 /* Idle value 0 for output 1. */                        \
    letimerUFOANone,   /* No action on underflow on output 0. */               \
    letimerUFOANone,   /* No action on underflow on output 1. */               \
    letimerRepeatFree, /* Count until stopped by SW. */                        \
    0                  /* Use default top Value. */                            \
  }
#else
#define LETIMER_INIT_DEFAULT                                                   \
  {                                                                            \
    true,              /* Enable timer when initialization completes. */       \
    false,             /* Stop counter during debug halt. */                   \
    false,             /* Do not load COMP0 into CNT on underflow. */          \
    false,             /* Do not load COMP1 into COMP0 when REP0 reaches 0. */ \
    0,                 /* Idle value 0 for output 0. */                        \
    0,                 /* Idle value 0 for output 1. */                        \
    letimerUFOANone,   /* No action on underflow on output 0. */               \
    letimerUFOANone,   /* No action on underflow on output 1. */               \
    letimerRepeatFree, /* Count until stopped by SW. */                        \
    0                  /* Use default top Value. */                            \
  }
#endif

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

uint32_t LETIMER_CompareGet(LETIMER_TypeDef *letimer, unsigned int comp);
void LETIMER_CompareSet(LETIMER_TypeDef *letimer,
                        unsigned int comp,
                        uint32_t value);
uint32_t LETIMER_CounterGet(LETIMER_TypeDef *letimer);
#if !defined(_EFM32_GECKO_FAMILY)
void LETIMER_CounterSet(LETIMER_TypeDef *letimer, uint32_t value);
#endif

void LETIMER_Enable(LETIMER_TypeDef *letimer, bool enable);
#if defined(_LETIMER_FREEZE_MASK)
void LETIMER_FreezeEnable(LETIMER_TypeDef *letimer, bool enable);
#endif
void LETIMER_Init(LETIMER_TypeDef *letimer, const LETIMER_Init_TypeDef *init);

/***************************************************************************//**
 * @brief
 *   Clear one or more pending LETIMER interrupts.
 *
 * @param[in] letimer
 *   Pointer to LETIMER peripheral register block.
 *
 * @param[in] flags
 *   Pending LETIMER interrupt source to clear. Use a bitwise logic OR
 *    combination of valid interrupt flags for the LETIMER module
 *    (LETIMER_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void LETIMER_IntClear(LETIMER_TypeDef *letimer, uint32_t flags)
{
#if defined (LETIMER_HAS_SET_CLEAR)
  letimer->IF_CLR = flags;
#else
  letimer->IFC = flags;
#endif
}

/***************************************************************************//**
 * @brief
 *   Disable one or more LETIMER interrupts.
 *
 * @param[in] letimer
 *   Pointer to LETIMER peripheral register block.
 *
 * @param[in] flags
 *   LETIMER interrupt sources to disable. Use a bitwise logic OR combination of
 *   valid interrupt flags for the LETIMER module (LETIMER_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void LETIMER_IntDisable(LETIMER_TypeDef *letimer, uint32_t flags)
{
#if defined (LETIMER_HAS_SET_CLEAR)
  letimer->IEN_CLR = flags;
#else
  letimer->IEN &= ~flags;
#endif
}

/***************************************************************************//**
 * @brief
 *   Enable one or more LETIMER interrupts.
 *
 * @note
 *   Depending on the use, a pending interrupt may already be set prior to
 *   enabling the interrupt. To ignore a pending interrupt, consider using
 *   LETIMER_IntClear() prior to enabling the interrupt.
 *
 * @param[in] letimer
 *   Pointer to the LETIMER peripheral register block.
 *
 * @param[in] flags
 *   LETIMER interrupt sources to enable. Use a bitwise logic OR combination of
 *   valid interrupt flags for the LETIMER module (LETIMER_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void LETIMER_IntEnable(LETIMER_TypeDef *letimer, uint32_t flags)
{
#if defined (LETIMER_HAS_SET_CLEAR)
  letimer->IEN_SET = flags;
#else
  letimer->IEN |= flags;
#endif
}

/***************************************************************************//**
 * @brief
 *   Get pending LETIMER interrupt flags.
 *
 * @note
 *   Event bits are not cleared by the use of this function.
 *
 * @param[in] letimer
 *   Pointer to LETIMER peripheral register block.
 *
 * @return
 *   LETIMER interrupt sources pending. A bitwise logic OR combination of
 *   valid interrupt flags for the LETIMER module (LETIMER_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE uint32_t LETIMER_IntGet(LETIMER_TypeDef *letimer)
{
  return letimer->IF;
}

/***************************************************************************//**
 * @brief
 *   Get enabled and pending LETIMER interrupt flags.
 *
 * @details
 *   Useful for handling more interrupt sources in the same interrupt handler.
 *
 * @note
 *   Event bits are not cleared by the use of this function.
 *
 * @param[in] letimer
 *   Pointer to LETIMER peripheral register block.
 *
 * @return
 *   Pending and enabled LETIMER interrupt sources.
 *   Return value is the bitwise AND combination of
 *   - the OR combination of enabled interrupt sources in LETIMER_IEN_nnn
 *   register (LETIMER_IEN_nnn) and
 *   - the OR combination of valid interrupt flags of the LETIMER module
 *   (LETIMER_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE uint32_t LETIMER_IntGetEnabled(LETIMER_TypeDef *letimer)
{
  uint32_t ien;

  /* Store flags in temporary variable in order to define explicit order
   * of volatile accesses. */
  ien = letimer->IEN;

  /* Bitwise AND of pending and enabled interrupts */
  return letimer->IF & ien;
}

/***************************************************************************//**
 * @brief
 *   Set one or more pending LETIMER interrupts from SW.
 *
 * @param[in] letimer
 *   Pointer to LETIMER peripheral register block.
 *
 * @param[in] flags
 *   LETIMER interrupt sources to set to pending. Use a bitwise logic OR
 *   combination of valid interrupt flags for the LETIMER module (LETIMER_IF_nnn).
 ******************************************************************************/
__STATIC_INLINE void LETIMER_IntSet(LETIMER_TypeDef *letimer, uint32_t flags)
{
#if defined (LETIMER_HAS_SET_CLEAR)
  letimer->IF_SET = flags;
#else
  letimer->IFS = flags;
#endif
}

#if defined(_LETIMER_LOCK_MASK)
/***************************************************************************//**
 * @brief
 *   Lock LETIMER registers.
 *
 * @param[in] letimer
 *   Pointer to LETIMER peripheral register block.
 *
 * @note When LETIMER registers are locked LETIMER_EN, LETIMER_SWRST,
 *            LETIMER_CTRL, LETIMER_CMD, LETIMER_CNT, LETIMER_COMPx,
 *            LETIMER_TOP, LETIMER_TOPBUFF, LETIMER_REPx, and PRSMODE registers
 *            cannot be written to.
 ******************************************************************************/
__STATIC_INLINE void LETIMER_Lock(LETIMER_TypeDef *letimer)
{
  letimer->LOCK = ~LETIMER_LOCK_LETIMERLOCKKEY_UNLOCK;
}
#endif

#if defined(_LETIMER_LOCK_MASK)
/***************************************************************************//**
 * @brief
 *   Unlock LETIMER registers.
 *
 * @param[in] letimer
 *   Pointer to LETIMER peripheral register block.
 ******************************************************************************/
__STATIC_INLINE void LETIMER_Unlock(LETIMER_TypeDef *letimer)
{
  letimer->LOCK = LETIMER_LOCK_LETIMERLOCKKEY_UNLOCK;
}
#endif

uint32_t LETIMER_RepeatGet(LETIMER_TypeDef *letimer, unsigned int rep);
void LETIMER_RepeatSet(LETIMER_TypeDef *letimer,
                       unsigned int rep,
                       uint32_t value);
void LETIMER_Reset(LETIMER_TypeDef *letimer);
void LETIMER_SyncWait(LETIMER_TypeDef *letimer);
void LETIMER_TopSet(LETIMER_TypeDef *letimer, uint32_t value);
uint32_t LETIMER_TopGet(LETIMER_TypeDef *letimer);

/** @} (end addtogroup letimer) */

#ifdef __cplusplus
}
#endif

#endif /* defined(LETIMER_COUNT) && (LETIMER_COUNT > 0) */
#endif /* EM_LETIMER_H */
