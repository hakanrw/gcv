// vala-gcc-diagnostics.cc -- GCC implementation of vala linemap interface.
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

#ifndef VALA_LINEMAP_H
#define VALA_LINEMAP_H

// The backend must define a type named Location which holds
// information about a location in a source file.  The only thing the
// frontend does with instances of Location is pass them back to the
// backend interface.
// The type is normally passed by value rather than by reference, and
// it should support that efficiently.  The type should be defined in
// "vala-location.h".
#include "vala-location.h"
#include <stdbool.h>

struct Linemap
{
  bool _in_file;
};

typedef struct Linemap linemap_t;

extern struct Linemap* vala_be_linemap_instance;

#ifdef __cplusplus
extern "C" {
#endif

void
vala_be_linemap_init (struct Linemap* linemap);

void
vala_be_linemap_start_file (struct Linemap* linemap, const char* file_name,
                            unsigned int line_begin);

void
vala_be_linemap_start_line (struct Linemap* linemap, unsigned int line_number,
                            unsigned int line_size);

void
vala_be_linemap_stop (struct Linemap* linemap);

Location
vala_be_linemap_get_location (struct Linemap* linemap, unsigned int column,
                              unsigned int length);

const char*
vala_be_linemap_to_string (struct Linemap* linemap, Location location);

Location
vala_be_linemap_get_predeclared_location ();

Location
vala_be_linemap_get_unknown_location ();

bool
vala_be_linemap_is_predeclared (Location location);

bool
vala_be_linemap_is_unknown (Location location);

const char*
vala_be_linemap_location_to_string (Location location);

const char*
vala_be_linemap_location_to_file (Location location);

unsigned int
vala_be_linemap_location_to_line (Location location);

#ifdef __cplusplus
}
#endif

#endif // !defined(VALA_LINEMAP_H)
