#ifndef DateCriteria_H
#define DateCriteria_H

#include "LibrariesAndDefines.hpp"
#include "Criteria.hpp"

class DateCriteria : public Criteria
{
    public:
        DateCriteria(string minYear_, string maxYear_, vector <Music*> musics_);

        virtual void processCriteria();

        virtual string getType();

    protected:

        string minYear;
        string maxYear;

        void makeCriteria();
    
};

#endif