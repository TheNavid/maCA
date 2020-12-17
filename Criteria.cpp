#include "Criteria.hpp"

Criteria::Criteria(vector <Music*> musics_)
{
    musics = musics_;
}

void Criteria::printSongInfo()
{
    for (int i = 0; i < afterCriteria.size(); i++)
    {
        afterCriteria[i]->printInfo();
    }
}