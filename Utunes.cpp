#include "Utunes.hpp"

void Utunes::startUtunes(string filePath)
{
    input.getFromCSV(filePath);
    musics = input.getMusics();
    playlistsNumber = 1;
    startProcess();
}

void Utunes::printInfos()
{
    for (int i = ZERO; i < musics.size(); i++)
    {
        musics[i]->printInfo();
    }
}

void Utunes::startProcess()
{
    string in;
    while (true) //check for finishing program
    {
        try
        {
            input.getInput();
            processCommand(input.getCommand(), input.getOptions());
        }catch (exception& excp)
        {
            cout << excp.what() << endl;
        }
    }
}

void Utunes::processCommand(int command, vector <string> options)
{
    switch (command)
    {
        case POST_SIGNUP:
            processPostSignup(options);
            break;
        case POST_LOGIN:
            processPostLogin(options);
            break;
        case POST_LOGOUT:
            processPostLogout();
            break;
        case GET_ALL_SONGS:
            processGetAllSongs();
            break;
        case GET_SONGS:
            processGetSongs(options);
            break;
        case POST_LIKES:
            processPostLikes(options);
            break;
        case GET_LIKES:
            processGetLikes();
            break;
        case DELETE_LIKES:
            processDeleteLikes(options);
            break;
        case POST_PLAYLISTS:
            processPostPlaylists(options);
            break;
        case GET_PLAYLISTS:
            processGetPlaylists(options);
            break;
        case POST_PLAYLISTS_SONGS:
            processPostPlaylistsSongs(options);
            break;
        case GET_PLAYLISTS_SONGS:
            processGetPlaylistsSongs(options);
            break;
        case DELETE_PLAYLISTS_SONGS:
            processDeletePlaylistsSongs(options);
            break;
        case GET_USERS:
            processGetUsers();
            break;
        /*case POST_ARTIST_FILTERS:
            processPostArtistFilters(options);
            break;
        case POST_LIKE_FILTERS:
            processPostLikeFilters(options);
            break;
        case POST_DATE_FILTERS:
            processPostDateFilters(options);
            break;
        case DELETE_FILTERS:
            processDeleteFilters();
            break;*/
        case POST_COMMENTS:
            processPostComments(options);
            break;
        case GET_COMMENTS:
            processGetComments(options);
            break;
    }

}

void Utunes::processPostSignup(vector <string> options)
{
    string email = options[1];
    string username = options[3];
    string password = options[5];
    if (canSignup(email ,username))
    {
        addNewUser(email, username, password);
        cout << PROCESS_DONE << endl;
    }
    else
        throw runtime_error(BAD_REQUEST_ERROR);
}

bool Utunes::canSignup(string email, string username)
{
    for (int user = ZERO; user < users.size(); user++)
    {
        if (users[user]->getUsername() == username || users[user]->getEmail() == email)
            return false;
    }
    return true;
}

void Utunes::addNewUser(string email, string username, string password)
{
    User* user = new User(email, username, password);
    users.push_back(user);
    //sort(users.begin(), users.end(), greater <User*>());
}

void Utunes::processPostLogin(vector <string> options)
{
    string email = options[1];
    string password = options[3];
    User* user = findUser(email);
    if (user->getPassword() == password && user != nullptr)
    {
        user->login();
        cout << PROCESS_DONE << endl;
    }
    else
        throw runtime_error(BAD_REQUEST_ERROR);

}

User* Utunes::findUser(string email)
{
    for (int user = ZERO; user < users.size(); user++)
    {
        if (users[user]->getEmail() == email)
            return users[user];
    }
    return nullptr;
}

void Utunes::processPostLogout()
{
    User* user = findLoggedInUser();
    if (user != nullptr)
    {
        user->logout();
        cout << PROCESS_DONE << endl;
    }
    else
        throw runtime_error(PERMISSION_DENIED_ERROR);
}

User* Utunes::findLoggedInUser()
{
    for (int user = 0; user < users.size(); user++)
    {
        if (users[user]->isLogin())
            return users[user];
    }
    return nullptr;
}

void Utunes::processGetAllSongs()//change with adding filters
{
    User* user = findLoggedInUser();
    if (user != nullptr)
    {   
        for (int music = ZERO; music < musics.size(); music++)
            musics[music]->printInfo();
    }//error of Wmpty criteria
    //if (user != nullptr && user->isCriteriaUsed())
    //{   
      //  for (int music = ZERO; music < musics.size(); music++)
        //    user->printCriteriaSongInfo();
    //}
    //else
        //throw runtime_error(PERMISSION_DENIED_ERROR);

}

void Utunes::processGetSongs(vector <string> options)
{
    string id = options[1];
    User* user = findLoggedInUser();
    Music* music = findMusicById(id);
    if (user != nullptr && music != nullptr)
        music->printCompleteInfo();
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (music == nullptr)
        throw runtime_error(NOT_FOUND_ERROR);

}
Music* Utunes::findMusicById(string id)
{
    for (int music = ZERO; music < musics.size(); music++)
    {
        if (musics[music]->getId() == id)
            return musics[music];
    }
    return nullptr;
}

void Utunes::processPostLikes(vector <string> options)
{
    string id = options[1];
    User* user = findLoggedInUser();
    Music* music = findMusicById(id);
    if (user != nullptr && music != nullptr && user->canLike(id))
    {
        music->like();
        user->addToLikedMusic(music);
        cout << PROCESS_DONE <<endl;
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (music == nullptr)
        throw runtime_error(NOT_FOUND_ERROR);
    else if (!user->canLike(id))
        throw runtime_error(BAD_REQUEST_ERROR);
}


void Utunes::processGetLikes()
{
    User* user = findLoggedInUser();
    if (user != nullptr)
        user->printLikedMusic();
    else
        throw runtime_error(PERMISSION_DENIED_ERROR);
    
}

void Utunes::processDeleteLikes(vector <string> options)
{
    string id = options[1];
    User* user = findLoggedInUser();
    Music* music = findMusicById(id);
    if (user != nullptr && music != nullptr && !user->canLike(id))
    {
        music->dislike();
        user->removeFromLikedMusic(music);
        cout << PROCESS_DONE <<endl;
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (music == nullptr)
        throw runtime_error(NOT_FOUND_ERROR);
    else if (user->canLike(id))
        throw runtime_error(BAD_REQUEST_ERROR);
}

void Utunes::processPostPlaylists(vector <string> options)
{
    User* user = findLoggedInUser();
    string name = options[1];
    string privacyStatus = options[3];
    if (user != nullptr)
    {
        user->addNewPlaylist(playlistsNumber, name, privacyStatus);
        cout << playlistsNumber << endl;
        playlistsNumber++;
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);   
}

void Utunes::processGetPlaylists(vector <string> options)
{
    User* loggedInUser = findLoggedInUser();
    string username = options[1];
    User* chosenUser = findUserByUser(username);
    if (loggedInUser != nullptr && chosenUser != nullptr)
    {
        chosenUser->showPlaylists(loggedInUser->getUsername());
    }
    else if (loggedInUser == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (chosenUser == nullptr)
        throw runtime_error(BAD_REQUEST_ERROR);
}

User* Utunes::findUserByUser(string username)
{
    for (int user = ZERO; user < users.size(); user++)
    {
        if (users[user]->getUsername() == username)
            return users[user];
    }
    return nullptr;
}

void Utunes::processPostPlaylistsSongs(vector <string> options)
{
    string playlistId = options[1];
    User* user = findLoggedInUser();
    string id = options[3];
    Music* music = findMusicById(id);
    if (user != nullptr && music != nullptr)
    {
        user->addSongToPlayList(playlistId, music);
        cout << PROCESS_DONE << endl;
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (music == nullptr)
        throw runtime_error(BAD_REQUEST_ERROR);
}

void Utunes::processGetPlaylistsSongs(vector <string> options)
{
    string playlistId = options[1];
    User* LoggedInUser = findLoggedInUser();
    User* chosenUser = findUserByPlaylistId(playlistId);
    if (LoggedInUser != nullptr && chosenUser != nullptr)
    {
        chosenUser->showSongsInPlaylist(playlistId, LoggedInUser->getEmail());
    }
    else if (LoggedInUser == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (chosenUser == nullptr)
        throw runtime_error(BAD_REQUEST_ERROR);
}

User* Utunes::findUserByPlaylistId(string playlistId)
{
    for (int user = ZERO; user < users.size(); user++)
    {
        if (users[user]->isPlaylistHere(playlistId))
            return users[user];
    }
    return nullptr;
}

void Utunes::processDeletePlaylistsSongs(vector <string> options)
{
    string playlistId = options[1];
    User* user = findLoggedInUser();
    string id = options[3];
    Music* music = findMusicById(id);
    if (user != nullptr && music != nullptr)
    {
        user->deleteSongFromPlaylist(playlistId, music);
        cout << PROCESS_DONE << endl;
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (music == nullptr)
        throw runtime_error(BAD_REQUEST_ERROR);
}

void Utunes::processGetUsers()
{
    User* user = findLoggedInUser();
    if (isUsersEmpty(user))
        throw runtime_error(EMPTY_ERROR);
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (!isUsersEmpty(user) && user != nullptr)
    {
        for (int i = ZERO; i < users.size(); i++)
        {
            if (users[i]->getUsername() != user->getUsername())
                users[i]->printInfo();
        }
    }
}

bool Utunes::isUsersEmpty(User* user)
{
    return (users.size() == 1 && users[0]->getUsername() == user->getUsername()) || (users.size() == ZERO);
}

/*void Utunes::processPostArtistFilters(vector <string> options)
{
    User* user = findLoggedInUser();
    string artist = options[1];
    if (user != nullptr && isArtistAvailable(artist))
    {
        user->putArtistCriteria(artist, musics);
        cout << PROCESS_DONE << endl;
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (!isArtistAvailable(artist))//check error
        throw runtime_error(PERMISSION_DENIED_ERROR);
}

bool Utunes::isArtistAvailable(string artist)
{
    for (int i = ZERO; i < musics.size(); i++)
    {
        if (musics[i]->getArtistName() == artist)
            return true;
    }
    return false;
}

void Utunes::processPostLikeFilters(vector <string> options)
{

}

void Utunes::processPostDateFilters(vector <string> options)
{

}

void Utunes::processDeleteFilters()
{

}*/


void Utunes::processPostComments(vector <string> options)
{
    User* user = findLoggedInUser();
    string time = options[3];
    string songId = options[1];
    string commentTxt = options[5];
    Music* music = findMusicById(songId);
    if (canComment(user, music, time))
    {
        music->putComment(time, commentTxt, user->getUsername());
        cout << PROCESS_DONE << endl;
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (music == nullptr)
        throw runtime_error(NOT_FOUND_ERROR);
}

bool Utunes::canComment(User* user, Music* music, string time)
{
    return user != nullptr && music != nullptr && time > "0";
}

void Utunes::processGetComments(vector <string> options)
{
    User* user = findLoggedInUser();
    string songId = options[1];
    Music* music = findMusicById(songId);
    if (user != nullptr && music != nullptr)
    {
        music->showComments();
    }
    else if (user == nullptr)
        throw runtime_error(PERMISSION_DENIED_ERROR);
    else if (music == nullptr)
        throw runtime_error(NOT_FOUND_ERROR);
}






































/*

#define POST_LIKES 104
#define GET_LIKES 105
#define DELETE_LIKES 106

#define POST_PLAYLISTS 107
#define GET_PLAYLISTS 108

#define POST_PLAYLISTS_SONGS 109
#define GET_PLAYLISTS_SONGS 110
#define DELETE_PLAYLISTS_SONGS 111

#define GET_USERS 112

#define POST_ARTIST_FILTERS 113
#define POST_LIKE_FILTERS 118
#define POST_DATE_FILTERS 119
#define DELETE_FILTERS 114

#define POST_COMMENTS 115
#define GET_COMMENTS 116*/