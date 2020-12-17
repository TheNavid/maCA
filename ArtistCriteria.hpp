#ifndef ArtistCriteria_H
#define ArtistCriteria_H

#include "LibrariesAndDefines.hpp"
#include "Criteria.hpp"

class ArtistCriteria : public Criteria
{
    public:
        ArtistCriteria(string name, vector <Music*> musics_);

        virtual void processCriteria();
        virtual string getType();

    protected:
        string artistName;
        
        void makeCriteria();
};

#endif