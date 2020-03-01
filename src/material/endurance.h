
#ifndef MATERIAL_ENDURANCE_H
#define MATERIAL_ENDURANCE_H

// All values are expected to be minimum
struct material  {

  char *name;

  double yield_stress;  // MPa
  double tensile_stress;  // MPa
  double elongation;  // %
  double max_thicness;  // mm  usually less thic material will be stronger 10-20 MPa

  // Hardness can have 6 values just as shown below
  // Brinell -> HB, Vicksers -> Hv
  // Leeb -> HLE, Rockwell C -> HRC
  // Rockwell B -> HRB, hardness unknown -> NULL.
  char *harndess_type; 
  double softened_hardness;
  double enhancement_hardness;

  double young_modulus;  // MPa
  double torsional_modulus; // MPa
  double poisson_factor; // -
  double linear_thermal_expansion_factor; // 1 / deg C
  double density

};


#endif
