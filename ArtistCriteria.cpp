#include "ArtistCriteria.hpp"

string ArtistCriteria::getType()
{
    return ARTIST_STR;
}

ArtistCriteria::ArtistCriteria(string name, vector <Music*> musics_)
                                : Criteria(musics_)
{
    artistName = name;
}

void ArtistCriteria::processCriteria()
{
    if (!filterUsedBefore)
    {
        makeCriteria();
        filterUsedBefore = true;
    }
    else if (filterUsedBefore)
    {
        dateFilter.clear();
        makeCriteria();
    }
}

void ArtistCriteria::makeCriteria()
{
    for (int i = 0; i < musics.size(); i++)
    {
        if(musics[i]->getArtistName() == artistName)
            artistFilter.push_back(musics[i]);
    }
}