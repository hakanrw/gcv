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

#include "vala-linemap.h"
#include "vala-system.h"

struct Linemap* vala_be_linemap_instance = NULL;

void
vala_be_linemap_init (Linemap* linemap)
{
  if (vala_be_linemap_instance != NULL)
  {
    vala_assert (false);
    return;
  }

  linemap->_in_file = false;
  vala_be_linemap_instance = linemap;
}

void
vala_be_linemap_start_file (Linemap* linemap, const char* file_name,
                            unsigned int line_begin)
{
  printf ("linemap_start_file(%s, %u)\n", file_name, line_begin);
  if (linemap->_in_file)
    linemap_add (line_table, LC_LEAVE, 0, NULL, 0);
  linemap_add (line_table, LC_ENTER, 0, file_name, line_begin);
  linemap->_in_file = true;
}

void
vala_be_linemap_start_line (Linemap* linemap, unsigned int line_number,
                            unsigned int line_size)
{
  printf ("linemap_line_start(%u, %u)\n", line_number, line_size);
  linemap_line_start (line_table, line_number, line_size);
}

void
vala_be_linemap_stop (Linemap* linemap)
{
  printf ("linemap_stop\n");
}

Location
vala_be_linemap_get_location (Linemap* linemap, unsigned int column,
                              unsigned int length)
{
  printf ("linemap_get_location(%u, %u)\n", column, length);
  return linemap_position_for_column (line_table, column);
}

const char*
vala_be_linemap_to_string (Linemap* linemap, Location location);

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
