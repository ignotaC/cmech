/*

Copyright (c) 2020 Piotr Trzpil  p.trzpil@protonmail.com

Permission to use, copy, modify, and distribute 
this software for any purpose with or without fee
is hereby granted, provided that the above copyright
notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR
DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE
FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
OF THIS SOFTWARE.

*/

#ifndef MC_INERTIA_MOMENT_H
#define MC_INERTIA_MOMENT_H

double mc_shaft_crosssection_inertia_moment_x( 
    double diameter );

double mc_shaft_crosssection_inertia_moment_xy(
    double diameter );

double mc_pipe_crosssection_inertia_moment_x( 
    double outer_diameter,
    double thickness );

double mc_pipe_crosssection_inertia_moment_xy( 
    double outer_diameter,
    double thickness );

double mc_square_crosssection_inertia_moment_x(
    double side );

double mc_square_crosssection_inertia_moment_xy(
    double side );

double mc_square_profile_crosssection_inertia_moment_x(
    double outer_side,
    double thickness );

double mc_square_profile_crosssection_inertia_moment_xy(
    double outer_side,
    double thickness );

double mc_rectangle_crosssection_inertia_moment_x(
    double side_x,
    double side_y );

double mc_rectangle_crosssection_inertia_moment_xy(
    double side_x,
    double side_y );

double mc_rectangle_profile_crosssection_inertia_moment_x( 
    double outer_side_x,
    double outer_side_y,
    double thickness );

double mc_rectangle_profile_crosssection_inertia_moment_xy(
    double outer_side_x,
    double outer_side_y,
    double thickness );

double mc_ovalshaft_crosssection_inertia_moment_x(
    double length_x,
    double length_y );

double mc_ovalshaft_crosssection_inertia_moment_xy(
    double length_x,
    double length_y );

#endif
