// vala-diagnostics.cc -- GCC implementation of vala diagnostics interface.
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

#include "vala-system.h"
#include "vala-location.h"
#include "vala-diagnostics.h"

void
vala_be_error_at(const Location location, const char* errmsg)
{
  location_t gcc_loc = (location_t)location;
  error_at(gcc_loc, "%s", errmsg);
}

void
vala_be_warning_at(const Location location,
                 int opt, const char* warningmsg)
{
  location_t gcc_loc = (location_t)location;
  warning_at(gcc_loc, opt, "%s", warningmsg);
}

void
vala_be_fatal_error(const Location location,
                  const char* fatalmsg)
{
  location_t gcc_loc = (location_t)location;
  fatal_error(gcc_loc, "%s", fatalmsg);
}

void
vala_be_inform(const Location location,
             const char* infomsg)
{
  location_t gcc_loc = (location_t)location;
  inform(gcc_loc, "%s", infomsg);
}

void
vala_be_get_quotechars(const char** open_qu, const char** close_qu)
{
  *open_qu = open_quote;
  *close_qu = close_quote;
}

void
vala_be_assert(bool value)
{
  vala_assert(value);
}
