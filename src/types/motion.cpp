#include "../../include/types/motion.h"

using namespace ades;

std::map<std::string, std::vector<double>> DMPContainer::getMotionParameters() const
{
    std::map<std::string, std::vector<double>> params;

    params.insert(std::pair<std::string, std::vector<double>>("gaussianCenters", gaussianCenters));
    params.insert(std::pair<std::string, std::vector<double>>("gaussianVariances", gaussianVariances));
    params.insert(std::pair<std::string, std::vector<double>>("weights", weights));
    params.insert(std::pair<std::string, std::vector<double>>("dmpCoeffs", dmpCoeffs));
    
    return params; 
}

MotionType DMPContainer::getMotionType() const { return MotionType::DMP; }

void DMPContainer::setTemporalScale(float scaling){ temporalScale = scaling; }

bool DMPContainer::isTemporallyScalable() const { return true; }

void DMPContainer::serialize(boost::archive::xml_oarchive & oa, const unsigned int version)
{
    oa & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Motion);

    oa & BOOST_SERIALIZATION_NVP(temporalScale);
    oa & BOOST_SERIALIZATION_NVP(name_);

    for(auto it : gaussianCenters)
    {
        oa & BOOST_SERIALIZATION_NVP(it);
    }
    for(auto it : gaussianVariances)
    {
        oa & BOOST_SERIALIZATION_NVP(it);
    }
    for(auto it : weights)
    {
        oa & BOOST_SERIALIZATION_NVP(it);
    }
    for(auto it : dmpCoeffs)
    {
        oa & BOOST_SERIALIZATION_NVP(it);
    }
}
void DMPContainer::deserialize(boost::archive::xml_iarchive & ia, const unsigned int version){}
