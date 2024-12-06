// vala-backend.h -- GCC implementation of vala diagnostics interface.
// Copyright (C) 2024 Free Software Foundation, Inc.
// Contributed by Hakan Candar.

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

#ifndef VALA_BACKEND_H
#define VALA_BACKEND_H

#include "vala-linemap.h"
#include "vala-location.h"
#include "vala-diagnostics.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Linemap*
vala_get_linemap ();

#ifdef __cplusplus
}
#endif

#endif // !defined(VALA_BACKEND_H)
