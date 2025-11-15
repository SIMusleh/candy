
/* Program name: candy.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/14/2025
 * Purpose: Implement the Candy class methods declared in candy.h.
 */

 #include "candy.h"
 #include <string>

 Candy::Candy(flavorType f, colorType c) {
    flavor = f;
    color = c;
 }

 flavorType Candy::getFlavor() const {
    return flavor;
 }

 colorType Candy::getColor() const {
    return color;
 }

 void Candy::setFlavor(flavorType f) {
    flavor = f;
 }

 void Candy::setColor(colorType c) {
    color = c;
 }

 std::string Candy::flavorToString() const; {
    switch (flavor) {
        case COTTON_CANDY: return "Cotton Candy";
        case WATERMELON_BURST: return "Watermelon Burst";
        case PAPAYA_BLISS: return "Papaya Bliss";
        case CITRUS_SPLASH: return "Citrus Splash";
        case COLA: return "Cola";
    }
    return "";
 }

 std::string Candy::colorToString() const; {
    switch (color) {
        case SCARLET_BLAZE: return "Scarlet Blaze";
        case AZURE_SKY: return "Azure Sky";
        case EMERALD_MIST: return "Emerald Mist";
        case GOLDENROD_GLOW: return "Goldenrod Glow";
        case AMETHYST_HAZE: return "Amethyst Haze";
    }
    return "";
 }