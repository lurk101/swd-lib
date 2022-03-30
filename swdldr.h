//
// swdldr.h
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#pragma once

#include <stdint.h>

// Initialize SWD driver resources
// param nClockPin GPIO pin to which SWCLK is connected
// param nDataPin GPIO pin to which SWDIO is connected
// param nResetPin Optional GPIO pin to which RESET (RUN) is connected (active LOW)
// param nClockRateKHz Requested interface clock rate in KHz
// return Operation successful?
// note GPIO pin numbers are SoC number, not header positions.
// note The actual clock rate may be smaller than the requested.
int SWDInitialize(uint32_t nClockPin, uint32_t nDataPin, uint32_t nResetPin,
                  uint32_t nClockRateKHz);

// Release resources
void SWDFinalize(void);

// Halt the RP2040, load a program image and start it
// param pProgram Pointer to program image in memory
// param nProgSize Size of the program image (must be a multiple of 4)
// param nAddress Load and start address of the program image
// return Operation successful?
int SWDLoad(const void* pProgram, uint32_t nProgSize, uint32_t nAddress);

// Halt the RP2040
// return Operation successful?
int SWDHalt(void);

// Load a chunk of a program image (or entire program)
// param pChunk Pointer to the chunk in memory
// param nChunkSize Size of the chunk (must be a multiple of 4)
// param nAddress Load address of the chunk
// return Operation successful?
int SWDLoadChunk(const void* pChunk, uint32_t nChunkSize, uint32_t nAddress);

// Start program image
// param nAddress Start address of the program image
// return Operation successful?
int SWDStart(uint32_t nAddress);
