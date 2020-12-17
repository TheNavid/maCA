#include "LikeCriteria.hpp"

string LikeCriteria::getType()
{
    return LIKE_STR;
}

LikeCriteria::LikeCriteria(string minLike_, string maxLike_, vector <Music*> musics_)
                                : Criteria(musics_)
{
    if (maxLike_ > minLike_ && minLike_ >= "0")//put error for integer number
    {
        minLike = minLike_;
        maxLike = maxLike_;
    }
    else 
        throw runtime_error(BAD_REQUEST_ERROR);
}

void LikeCriteria::processCriteria()
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

void LikeCriteria::makeCriteria()
{
    for (int i = ZERO; i < musics.size(); i++)
    {
        if ((musics[i]->getLike() <= stoi(maxLike)) && (musics[i]->getLike() >= stoi(minLike)))
        {
            likeFilter.push_back(musics[i]);
        }
    }   
}