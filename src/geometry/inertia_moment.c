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

#include "inertia_moment.h"
#include "../const_vars.h"

//
//        _______________
//      ####             |
//   ##########          |
//--############--> x    |  diameter
//   ##########          |
//      ####_____________|
//
//
// tested
double mc_shaft_crosssection_inertia_moment_x( 
    double diameter )  {

  return MC_PI * diameter * diameter * diameter * diameter / 64.0;

}

double mc_shaft_crosssection_inertia_moment_xy(
    double diameter )  {

  return MC_PI * diameter * diameter * diameter * diameter / 32.0;

}



//                             _____________
//               _______######             |
//               |    ###    ###           |
//               |   ###      ###          |
//inner diameter | -##----------##--->x    |  outer diameter
//               |   ###      ###          |
//               |____###    ###           |
//                      ######_____________|
//
//
// tested
double mc_pipe_crosssection_inertia_moment_x(
    double outer_diameter,
    double thickness )  {

  double inner_diameter = outer_diameter - ( 2 * thickness );
  double answer = outer_diameter * outer_diameter * outer_diameter * outer_diameter;
  answer -= inner_diameter * inner_diameter * inner_diameter * inner_diameter;
  answer *= MC_PI / 64.0;
  return answer;

}

double mc_pipe_crosssection_inertia_moment_xy(
    double outer_diameter,
    double thickness )  {

  double inner_diameter = outer_diameter - ( 2 * thickness );
  double answer = outer_diameter * outer_diameter * outer_diameter * outer_diameter;
  answer -= inner_diameter * inner_diameter * inner_diameter * inner_diameter;
  answer *= MC_PI / 32.0;
  return answer;

}



//
//  #####
//  ##### side_y  ---------------->x
//  #####
//    side_x
//
//   side_x == side_y

// tested
double mc_square_crosssection_inertia_moment_x( 
    double side )  {

  return side * side * side * side / 12.0;

}

double mc_square_crosssection_inertia_moment_xy(
    double side )  {

  return side * side * side * side / 6.0;

}

//  thickness
//  ||
//  #####
//  ## ## outer_side_y  ---------------->x
//  #####
//    outer_side_x
//
//   outer_side_x == outer_side_y

// tested
double mc_square_profile_crosssection_inertia_moment_x(
    double outer_side,
    double thickness )  {

  double inner_side = outer_side - ( 2.0 * thickness );
  double answer = outer_side * outer_side * outer_side * outer_side;
  answer -= inner_side * inner_side * inner_side * inner_side;
  return answer / 12.0;

}

double mc_square_profile_crosssection_inertia_moment_xy(
    double outer_side,
    double thickness )  {

  double inner_side = outer_side - ( 2.0 * thickness );
  double answer = outer_side * outer_side * outer_side * outer_side;
  answer -= inner_side * inner_side * inner_side * inner_side;
  return answer / 6.0;

}





//  #####
//  #####
//  ##### side_y  ---------------->x
//  #####
//  #####
//    side_x
//

// tested
double mc_rectangle_crosssection_inertia_moment_x(
    double side_x,
    double side_y )  {

  return side_x * side_y * side_y * side_y / 12.0;

}

double mc_rectangle_crosssection_inertia_moment_xy(
    double side_x,
    double side_y )  {

  double answer =  side_x * side_x;
  answer += side_y * side_y;
  answer *= side_x * side_y / 12.0;
  return answer;

}

//  thickness
//  ||
//  #####
//  #   #
//  #   # outer_side_y  ---------------->x
//  #   #
//  #####
//    outer_side_x
//

// tested
double mc_rectangle_profile_crosssection_inertia_moment_x( 
    double outer_side_x,
    double outer_side_y,
    double thickness )  {

  double inner_side_x = outer_side_x - ( 2.0 * thickness );
  double inner_side_y = outer_side_y - ( 2.0 * thickness );

  double answer = outer_side_x * outer_side_y * outer_side_y * outer_side_y;
  answer -= inner_side_x * inner_side_y * inner_side_y * inner_side_y;
  return answer / 12.0;

}

double mc_rectangle_profile_crosssection_inertia_moment_xy(
    double outer_side_x,
    double outer_side_y,
    double thickness )  {

  double inner_side_x = outer_side_x - ( 2.0 * thickness );
  double inner_side_y = outer_side_y - ( 2.0 * thickness );

  double outer_inertia = outer_side_x * outer_side_x;
  outer_inertia += outer_side_y * outer_side_y;
  outer_inertia *= outer_side_y * outer_side_x / 12.0;

  double inner_inertia = inner_side_x * inner_side_x;
  inner_inertia += inner_side_y * inner_side_y;
  inner_inertia *= inner_side_y * inner_side_x / 12.0;

  return outer_inertia - inner_inertia;

}




//                length_x
//          _____________
//          |        ____|__________
//          |   ######   |         |
//          | ########## |         |
//          | ########## |         |
//          |############|         |
//          |############|         |
//       ---##############--->x    |  length_y
//           ############          |
//           ############          |
//            ##########           |
//            ##########           |
//              ######_____________|
//
// tested
double mc_ovalshaft_crosssection_inertia_moment_x(
    double length_x,
    double length_y )  {

  return MC_PI * length_x * length_y * length_y * length_y / 64.0;

}

double ovalshaft_crosssection_inertia_moment_xy( double length_x, double length_y )  {

  double answer = MC_PI * length_x * length_y / 64.0;
  answer *= ( length_y * length_y ) + ( length_x * length_x );
  return answer;

}
