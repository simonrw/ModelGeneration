#ifndef MODEL_H

#define MODEL_H

#include <string>

/** @brief Class holding the state of the system
 *
 * Structure that holds the parameters for the model system. Is
 * taken as a parameter in the main model generation function. The
 * parameters are given in some standard units which are explained 
 * with the description of the parameters. For example the separation
 * is in AU (Earth-Sun distance).
 *
 * Some of the parameters are not used directly in the lightcurve generation
 * code, but are by some other codes I have written. The non-required parameters are:
 *
 * @li id
 * @li name
 * @li submodel_id
 * @li mstar
 * @li teff
 *
 * These can be set to whatever.
 *
 * @section ldc Limb darkening
 *
 * The limb darkening is modeled using 4 parameters: @f$c1@f$, @f$c2@f$, @f$c3@f$ and @f$c4@f$. These are related to @f$c0@f$ by
 *
 * @f[
 * c0 = 1 - c1 - c2 - c3 - c4
 * @f]
 *
 * These are calculated separately but must all be given for a realistic model. 
 */
struct Model
{
    /** @brief Simple id parameter 
     *
     * Not really used for much! */
    int id;

    /** @brief Object name
     *
     * Can be used to name the object but is not required */
    std::string name;

    /** @brief Subtraction model id
     *
     * Used to link the current model with a subtraction 
     * model.
     */
    int submodel_id;

    /** @brief Orbital period
     *
     * Units: @b days
     */
    double period;

    /** @brief Epoch
     *
     * Time of mid transit in days since an arbitrary 
     * reference point
     *
     * Units: @b days
     */
    double epoch;

    /** @brief Orbital separation
     *
     * Distance between the star and planet in 
     * units of AU (see constants.h)
     *
     * Units: @b AU
     */
    double a;

    /** @brief Orbital inclination
     *
     * Angle between the rotation vector of the planet's
     * orbit and the normal to the plane containing the Earth
     * and star. An edge on transit is defined as an inclination 
     * of @f$90^\circ@f$
     *
     * Units: @b Degrees
     */
    double i;

    /** @brief Stellar radius
     *
     * Radius of the star
     *
     * Units: @b Solar @b radii (see constants.h)
     */
    double rs;

    /** @brief Planetary radius
     *
     * Radius of the planet
     *
     * Units: @b Jupiter @b radii (see constants.h)
     */
    double rp;

    /** @brief Stellar mass
     *
     * Mass of the star
     *
     * Units: @b Solar @b mass (see constants.h)
     */
    double mstar;


    double c1; /**< @brief Limb darkening coefficient 1 */
    double c2; /**< @brief Limb darkening coefficient 2 */
    double c3; /**< @brief Limb darkening coefficient 3 */
    double c4; /**< @brief Limb darkening coefficient 4 */

    /** @brief Stellar effective temperature
     *
     * Temperature of the star
     *
     * Units: @b Kelvin
     */
    double teff;
};


#endif /* end of include guard: MODEL_H */
