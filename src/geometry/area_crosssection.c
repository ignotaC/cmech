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

#include "area_crosssection.h"
#include "../const_vars.h"

//
//        _______________
//      ####             |
//   ##########          |
//  ############         |  diameter
//   ##########          |
//      ####_____________|
//
//  tested
double mc_shaft_crosssection_area( 
    double diameter )  {

  return MC_PI * diameter * diameter / 4.0 ;

}


//               _______       _____________
// thickness     _______######             |
//               |    ###    ###           |
//               |   ###      ###          |
//inner diameter | -##----------##--->x    |  outer diameter
//               |   ###      ###          |
//               |____###    ###           |
//                      ######_____________|
//
//  tested
double mc_pipe_crosssection_area( 
    double outer_diameter, 
    double thickness )  {

  double inner_diameter = outer_diameter - ( 2 * thickness );
  double answer = outer_diameter * outer_diameter;
  answer -= inner_diameter * inner_diameter;
  answer *= MC_PI / 4.0;
  return answer;

}

//
//  #####
//  ##### side_y  ---------------->x
//  #####
//    side_x
//
//   side_x == side_y
//  tested
double mc_square_crosssection_area( 
    double side )  {

  return side * side;

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
double mc_square_profile_crosssection_area( 
    double outer_side, 
    double thickness )  {

  double inner_side = outer_side - ( 2.0 * thickness );
  return ( outer_side * outer_side ) - ( inner_side * inner_side );

}




//  #####
//  #####
//  ##### side_y  ---------------->x
//  #####
//  #####
//    side_x
//

// tested
double mc_rectangle_crosssection_area(
    double side_x, 
    double side_y )  {

  return side_x * side_y;

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
double mc_rectangle_profile_crosssection_area( 
    double outer_side_x, 
    double outer_side_y, 
    double thickness )  {

  double inner_side_x = outer_side_x - ( 2.0 * thickness );
  double inner_side_y = outer_side_y - ( 2.0 * thickness );

  return outer_side_x * outer_side_y - inner_side_x * inner_side_y;

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
// tested
double mc_ovalshaft_crosssection_area( 
    double lenght_x, 
    double lenght_y )  {

  return MC_PI* lenght_x * lenght_y / 4.0;

}
