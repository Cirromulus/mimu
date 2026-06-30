#include "distanceStorage.hpp"

#include <EEPROM.h>

void
DistanceStorage::loadFromEeprom()
{
    EEPROM.get(storageAddr, mCurrentDistance);
    if (mCurrentDistance < MIN_RANGE_MM || mCurrentDistance > MAX_RANGE_MM)
    {
        mCurrentDistance = defaultDistance;
    }
}

void
DistanceStorage::storeToEeprom() const
{
    EEPROM.put(storageAddr, mCurrentDistance);
}