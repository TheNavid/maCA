#include "DateCriteria.hpp"

string DateCriteria::getType()
{
    return DATE_STR;
}

DateCriteria::DateCriteria(string minYear_, string maxYear_, vector <Music*> musics_)
                            : Criteria(musics_)
{
    if (minYear_ > "0" && minYear_ <= maxYear_ )
    {
        minYear = minYear_;
        maxYear = maxYear_;
    }
    else 
        throw runtime_error(BAD_REQUEST_ERROR);
}

void DateCriteria::processCriteria()
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

void DateCriteria::makeCriteria()
{
    for (int i = ZERO; i < musics.size(); i++)
        {
            if ((musics[i]->getLike() <= stoi(maxYear)) && (musics[i]->getLike() >= stoi(minYear)))
            {
                dateFilter.push_back(musics[i]);
            }
        }
}