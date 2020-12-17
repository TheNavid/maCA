#include "Music.hpp"

Music::Music(vector <string> musicInfo)
{
    id = musicInfo[0];
    title = musicInfo[1];
    artist = musicInfo[2];
    releaseYear = musicInfo[3];
    link = musicInfo[4];
    likes = ZERO;
    playlists = ZERO;
}

void Music::printInfo()
{
    cout << id << " " << title << " " << artist << " " << releaseYear << endl;
}

string Music::getId()
{
    return id;
}

void Music::printCompleteInfo()
{
    cout << id << endl;
    cout << title << endl;
    cout << artist << endl;
    cout << releaseYear << endl;
    cout << "#likes: " << likes << endl;
    cout << "#Playlists: " << playlists << endl;
}

void Music::like()
{
    likes++;
}

void Music::dislike()
{
    likes--;
}

void Music::increasePlaylists()
{
    playlists++;
}

void Music::decreasePlaylists()
{
    playlists--;
}

string Music::getArtistName()
{
    return artist;
}

void Music::putComment(string time, string commentTxt, string username)
{
    comments.push_back(Comment(time, commentTxt, username));
}

void Music::showComments()
{
    if (comments.size() > 0)
    {
        for (int i = ZERO; i < comments.size(); i++)
        {
            comments[i].printComment();
        }
    }
    else if (comments.size() == ZERO)
        throw runtime_error(EMPTY_ERROR);
}











Comment::Comment(string time_, string commentTxt_, string username_)
{
    time = time_;
    commentTxt = commentTxt_;
    username = username_;
}

void Comment::printComment()
{
    cout << time << " " << username << ": " << commentTxt << endl;
}