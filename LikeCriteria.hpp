#ifndef LikeCriteria_H
#define LikeCriteria_H

#include "LibrariesAndDefines.hpp"
#include "Criteria.hpp"

class LikeCriteria : public Criteria
{
    public:
        LikeCriteria(string minLike_, string maxLike_, vector <Music*> musics_);

        virtual void processCriteria();

        virtual string getType();

    protected:
        string minLike;
        string maxLike;
    
        void makeCriteria();
};

#endif