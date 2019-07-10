/* Copyright 2019 Pedro Costa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEYMAP_PT_PT_H
#define KEYMAP_PT_PT_H

#include "keymap_common.h"

/* Scan codes for the Portuguese (Portugal) keyboard layout */

#define PT_BSLS KC_GRV   //  \|  same scancode as `~ on US layout
#define PT_QUOT KC_MINS  //  '?  same scancode as -_ on US layout
#define PT_LGLL KC_EQL   //  «»  same scancode as =+ on US layout
#define PT_PLUS KC_LBRC  //  +*  same scancode as [{ on US layout
#define PT_ACUT KC_RBRC  //  '` dead keys, same scancode as ]} on US layout
#define PT_CCDL KC_SCLN  //  Ç   same scancode as ;: on US layout
#define PT_MORD KC_QUOT  //  ºª same scancode as '" on US layout
#define PT_TILD KC_BSLS  //  ~^ dead keys, same scancode as \| on US layout
#define PT_COMM KC_COMM  //  ,;  same scancode as ,< on US layout
#define PT_DOT  KC_DOT   //  .:  same scancode as .> on US layout
#define PT_MINS KC_SLSH  //  -_  same scancode as /? on US layout

#define PT_PIPE LSFT(PT_BSLS)   // shifted |
#define PT_QUES LSFT(PT_QUOT)   // shifted ?
#define PT_RGLL LSFT(PT_LGLL)   // shifted »
#define PT_AST  LSFT(PT_PLUS)   // shifted *
#define PT_GRV  LSFT(PT_ACUT)   // shifted ` (dead key)
#define PT_FORD LSFT(PT_MORD)   // shifted ª
#define PT_CIRC LSFT(PT_TILD)   // shifted ^ (dead key)
#define PT_SCLN LSFT(PT_COMM)   // shifted ;
#define PT_CLN  LSFT(PT_DOT)    // shifted :

// On the Portuguese the keypad comma and the keypad dot scancodes are
// switched (because in Portugal comma is used as the decimal separator)
#define PT_KPDT KC_KP_COMMA  //  keypad .
#define PT_KPCM KC_KP_DOT    //  keypad ,

#define PT_1UP    ALGR(KC_1)      // 1 superscript                 ¹   alt gr+1
#define PT_AT     ALGR(KC_2)      // At sign                       @   alt+2
#define PT_PND    ALGR(KC_3)      // Pound sign                    £   alt+3
#define PT_SECT   ALGR(KC_4)      // Section sign                  §   alt+4
#define PT_HALF   ALGR(KC_5)      // Half sign                     ½   alt+5
#define PT_NOT    ALGR(KC_6)      // Not sign                      ¬   alt+6
#define PT_LCBR   ALGR(KC_7)      // Left curly brace              {   alt+6
#define PT_LBRC   ALGR(KC_8)      // Left square brackets          [   alt+6
#define PT_RBRC   ALGR(KC_9)      // Right square brackets         ]   alt+6
#define PT_RCBR   ALGR(KC_0)      // Right curly brace             }   alt+6
#define PT_INTP   ALGR(PT_DOT)    // Interpunct sign               ·   alt gr+.
#define PT_LSTR   ALGR(KC_W)      // L with a stroke               ł   alt gr+w
#define PT_EURO   ALGR(KC_E)      // Euro sign                     €   alt gr+e
#define PT_PARA   ALGR(KC_R)      // Paragraph sign                ¶   alt gr+r
#define PT_TSTR   ALGR(KC_T)      // T with a stroke               ŧ   alt gr+t
#define PT_LARR   ALGR(KC_Y)      // Left arrow sign               ←   alt gr+y
#define PT_DARR   ALGR(KC_U)      // Down arrow sign               ↓   alt gr+u
#define PT_RARR   ALGR(KC_I)      // Right arrow sign              →   alt gr+i
#define PT_OSTR   ALGR(KC_O)      // O with a stroke               ø   alt gr+o
#define PT_THRN   ALGR(KC_P)      // Thorn letter                  þ   alt gr+p
#define PT_TRMA   ALGR(PT_PLUS)   // Trema accent (dead key)       ¨   alt gr++
#define PT_ASH    ALGR(KC_A)      // Ash letter                    æ   alt gr+a
#define PT_ESZT   ALGR(KC_S)      // Eszett letter                 ß   alt gr+s
#define PT_ETH    ALGR(KC_D)      // Eth letter                    ð   alt gr+d
#define PT_DSTR   ALGR(KC_F)      // D with a stroke               đ   alt gr+f
#define PT_ENG    ALGR(KC_G)      // Eng letter                    ŋ   alt gr+g
#define PT_HSTR   ALGR(KC_H)      // Eng letter                    ŋ   alt gr+g
#define PT_HOOK   ALGR(KC_J)      // Hook aboce accent             ỏ   alt gr+j
#define PT_KRA    ALGR(KC_K)      // Kra letter                    ĸ   alt gr+k
#define PT_CENT   ALGR(KC_C)      // Cent sign                     ¢   alt gr+c
#define PT_LQUT   ALGR(KC_V)      // Left quotation mark           “   alt gr+v
#define PT_RQUT   ALGR(KC_B)      // Right quotation mark          ”   alt gr+b
#define PT_MU     ALGR(KC_M)      // Mu letter                     µ   alt gr+m

#endif
