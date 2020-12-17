#include "User.hpp"


User::User(string email_, string username_, string password_)
{
    email = email_;
    username = username_;
    password = password_;
    loggedIn = true;
    //usedCriteria = false;
}

string User::getEmail()
{
    return email;
}

string User::getUsername()
{
    return username;
}

string User::getPassword()
{
    return password;
}

void User::login()
{
    loggedIn = true;
}

bool User::isLogin()
{
    return loggedIn;
}

void User::logout()
{
    loggedIn = false;
}

void User::addToLikedMusic(Music* music)
{
    likedMusic.push_back(music);
}

bool User::canLike(string id)
{
    for (int i = ZERO; i < likedMusic.size(); i++)
    {
        if (likedMusic[i]->getId() == id)
            return false;
    }
    return true;
}

void User::printLikedMusic()
{
    if (likedMusic.size() == ZERO)
        throw runtime_error(EMPTY_ERROR);
    if (likedMusic.size() != ZERO)
    {
        for (int i = ZERO; i < likedMusic.size(); i++)
            likedMusic[i]->printInfo();
    }
}

void User::removeFromLikedMusic(Music* music)
{
    for (int i = ZERO; i < likedMusic.size(); i++)
    {
        if (likedMusic[i]->getId() == music->getId())
            likedMusic.erase(likedMusic.begin() + i);
    }
}

void User::addNewPlaylist(int id, string name, string privacyStatus)
{
    playlists.push_back(Playlist(id, name, privacyStatus));
}
void User::showPlaylists(string username_)
{
    if (username_ == username)
        printAllPlaylistsInfo();
    else if (username_ != username)
        printPublicPlaylistsInfo();
}

void User::printAllPlaylistsInfo()
{
    for (int i = ZERO; i < playlists.size(); i++)
    {
        playlists[i].printAllInfo();
    }
}

void User::printPublicPlaylistsInfo()
{
    for (int i = ZERO; i < playlists.size(); i++)
    {
        playlists[i].printPublicInfo();
    }
}

void User::addSongToPlayList(string playlistId, Music* music)
{
    if (isPlaylistHere(playlistId))
    {
        for(int i = ZERO; i < playlists.size(); i++)
        {
            if (playlists[i].getId() == stoi(playlistId))
                playlists[i].addMusic(music);
        }
    }
    else 
        throw runtime_error(PERMISSION_DENIED_ERROR);
}

bool User::isPlaylistHere(string playlistId)
{
    for(int i = ZERO; i < playlists.size(); i++)
    {
        if (playlists[i].getId() == stoi(playlistId))
            return true;
    }
    return false;
}

void User::showSongsInPlaylist(string playlistId, string loggedInEmail)
{   
    if (playlists.size() == ZERO)
        throw runtime_error(EMPTY_ERROR);
    else
    {
        for (int i = ZERO; i < playlists.size(); i++)
        {
            if (playlists[i].getId() == stoi(playlistId))
                playlists[i].showSongs(email, loggedInEmail);
        }
    } 
}

void User::deleteSongFromPlaylist(string playlistId, Music* music)
{
    if (isPlaylistHere(playlistId))
    {
        for(int i = ZERO; i < playlists.size(); i++)
        {
            if (playlists[i].getId() == stoi(playlistId))
                playlists[i].deleteMusic(music);
        }
    }
    else 
        throw runtime_error(PERMISSION_DENIED_ERROR);
}

void User::printInfo()
{
    cout << username << endl;
}

/*void User::putArtistCriteria(string name,  vector <Music*> allMusics)
{
    if (isArtistCriteriaUsed())
        deleteLastArtistCriteria();
    addNewArtistCriteria(name, allMusics);
    usedCriteria = true;
}

bool User::isArtistCriteriaUsed()
{
    for (int i = 0; i < criterias.size(); i++)
    {
        if (criterias[i]->getType() == ARTIST_STR)
            return true;
    }
    return false;
}

void User::deleteLastArtistCriteria()
{
    for (int i = 0; i < criterias.size(); i++)
    {
        if (criterias[i]->getType() == ARTIST_STR)
        {
            delete criterias[i];
            criterias.erase(criterias.begin() + i);
        }
    }
}

void User::addNewArtistCriteria(string name, vector <Music*> allMusics)
{
    ArtistCriteria* artistCriteria = new ArtistCriteria(name, allMusics);
    criterias.push_back(artistCriteria); 
    criterias[criterias.size() - 1]->processCriteria();
}

bool User::isCriteriaUsed()
{
    return usedCriteria;
}

void User::printCriteriaSongInfo()
{
    for(int i = ZERO; i < criterias.size(); i++)
    {
        criterias[i]->printSongInfo();
    }
}*/











Playlist::Playlist(int id_, string name_, string privacy_)
{
    id = id_;
    name = name_;
    if (privacy_ == PUBLIC_STR)
        privacy = PUBLIC;
    else
        privacy = PRIVATE;
}

void Playlist::printAllInfo()
{
    if (privacy == PUBLIC)
        cout << id << " " << name << " " << PUBLIC_STR << endl;
    else if (privacy == PRIVATE)
        cout << id << " " << name << " " << PRIVATE_STR << endl;
}
void Playlist::printPublicInfo()
{
    if (privacy == PUBLIC)
        cout << id << " " << name << " " << PUBLIC_STR << endl;
}

int Playlist::getId()
{
    return id;
}

void Playlist::addMusic(Music* music)
{
    musics.push_back(music);
    music->increasePlaylists();
    if (musics.size() > 1)
        sort(musics.begin(), musics.end());
}

void Playlist::showSongs(string email, string loggedInEmail)
{
    if (email == loggedInEmail)
    {  
        for (int i = ZERO; i < musics.size(); i++)
            musics[i]->printInfo();
    }
    else if (email != loggedInEmail && privacy == PUBLIC)
    {  
        for (int i = ZERO; i < musics.size(); i++)
            musics[i]->printInfo();
    }
    else if (email != loggedInEmail && privacy == PRIVATE)
        throw runtime_error(PERMISSION_DENIED_ERROR); 
}

void Playlist::deleteMusic(Music* music)
{
    if (isMusicHere(music))
    {
        for (int i = ZERO; i < musics.size(); i++)
        {
            if (musics[i]->getId() == music->getId())
            {
                music->decreasePlaylists();
                musics.erase(musics.begin() + i);
            }
        }
    }
    else
        throw runtime_error(BAD_REQUEST_ERROR);
}

bool Playlist::isMusicHere(Music* music)
{
    for (int i = ZERO; i < musics.size(); i++)
    {
        if (musics[i]->getId() == music->getId())  
            return true;
    }
    return false;
}