#ifndef Criteria_H
#define Criteria_H

#include "LibrariesAndDefines.hpp"
#include "Music.hpp"

class Criteria
{
    public:
        Criteria(vector <Music*> musics_);

        void printSongInfo();

        virtual void processCriteria() = 0;
        virtual string getType() = 0;
        

    protected:
        vector <Music*> afterCriteria;
        vector <Music*> musics;

    
};

#endif