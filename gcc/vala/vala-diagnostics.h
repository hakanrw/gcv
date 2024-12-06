// vala-gcc-diagnostics.h -- GCC implementation of vala diagnostics interface.
// Copyright (C) 2024 Free Software Foundation, Inc.
// Contributed by Hakan Candar.
// With study of code released under the same license by Than McIntosh, Google.

// This file is part of GCC.

// GCC is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3, or (at your option) any later
// version.

// GCC is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.

// You should have received a copy of the GNU General Public License
// along with GCC; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#ifndef VALA_DIAGNOSTICS_H
#define VALA_DIAGNOSTICS_H

#include "vala-location.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void
vala_be_inform_at (const Location location, const char* inform_message);

void
vala_be_error_at (const Location location, const char* inform_message);

void
vala_be_warning_at (const Location location, const char* inform_message);

void
vala_be_fatal_error_at (const Location location, const char* inform_message);

void
vala_be_assert (bool);
//#define vala_be_assert(EXPR) gcc_assert(EXPR)

#ifdef __cplusplus
}
#endif

#endif // VALA_DIAGNOSTICS_H
