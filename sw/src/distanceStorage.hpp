#include <config.hpp>

class DistanceStorage
{
    static constexpr Distance_mm defaultDistance = 40;
    static constexpr size_t storageAddr = 0;
public:
    constexpr
    DistanceStorage() : mCurrentDistance{defaultDistance}
    {
    }

    constexpr Distance_mm const&
    get_mm() const
    {
        return mCurrentDistance;
    }

    constexpr void
    set(Distance_mm const& newDistance)
    {
        mCurrentDistance = newDistance;
    }

    void
    loadFromEeprom();

    void
    storeToEeprom() const;

private:
    Distance_mm mCurrentDistance;
};
