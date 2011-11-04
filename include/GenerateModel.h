/** @file GenerateModel.h
 *
 * @brief Model generation header file
 *
 * @author Simon Walker
 *
 * This file defines the function to call for creating a 
 * synthetic lightcurve, GenerateSynthetic.
 *
 *
 */

/** @mainpage
 *
 * @author Simon Walker
 *
 * Library for creating synthetic transit lightcurves. 
 *
 * @section Theory
 *
 * The library uses the small planet approximation (@f$p<0.1@f$) to quickly generate
 * an idealised normalised lightcurve using the following equation:
 *
 *
 * @f[
 * F = 1 - \frac{I^{*}(z)}{4\Omega}\left[p^2 \arccos \left(\frac{z-1}{p} - (z-1) \sqrt{p^2 - (z-1)^2}\right)\right]
 * @f]
 *
 * See [1] for more information. Only standard c++ is used, and there are no dependancies.
 *
 *
 * @section References
 *
 * @li [1] <em>Mandel, K., Agol, E., 2002, ApJ, 580, L171</em>
 *
 */
#ifndef GENERATEMODEL_H

#define GENERATEMODEL_H


//Lightcurve GenerateSyntheticFromParams(const vector<double> &Time, double period, double midpoint, const vector<double> &coeffs, 
        //double semi, double rPlan, double rStar, double inclination, double dr, double noise);

#include <vector>

struct Model;

/** @brief Calculates a synthetic lightcurve
 *
 * Uses equation 8 from Mandel & Agol, 2002 to generate a normalised lightcurve
 *
 * @f[
 * F = 1 - \frac{I^{*}(z)}{4\Omega}\left[p^2 \arccos \left(\frac{z-1}{p} - (z-1) \sqrt{p^2 - (z-1)^2}\right)\right]
 * @f]
 *
 * where @f$I^{*}(z) = (1-a)^{-1} \int_{z-p}^{1}I(r)2rdr@f$. @f$p = r_{p} / r_{s}2@f$ and @f$z@f$ is the normalised distance
 * between the stellar and planetary centres. The function returns the flux values associated with the time information 
 * given normalised so that the out of transit data is unity.
 *
 * @param[in] jd Time units (JD)
 * @param[in] m Model object 
 * @return Flux values normalised around unity
 */
std::vector<double> GenerateSynthetic(const std::vector<double> &jd, const Model &m);

#endif /* end of include guard: GENERATEMODEL_H */
