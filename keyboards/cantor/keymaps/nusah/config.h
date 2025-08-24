// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MASTER_RIGHT

#define SPLIT_WATCHDOG_ENABLE      // https://github.com/diepala/cantor/issues/15#event-13754273368
#define SPLIT_WATCHDOG_TIMEOUT 3000
