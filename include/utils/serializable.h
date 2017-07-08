#pragma once


#include <fstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>


class Serializable
{
    friend class boost::serialization::access;


protected:
    virtual void serialize(boost::archive::xml_oarchive oa, const unsigned int version) = 0;

    virtual void deserialize(boost::archive::xml_iarchive ia, const unsigned int version) = 0;
};