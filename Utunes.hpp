#ifndef Utunes_H
#define Utunes_H

#include "LibrariesAndDefines.hpp"
#include "User.hpp"
#include "Music.hpp"
#include "InputManager.hpp"
#include "ExceptionManager.hpp"
#include "ArtistCriteria.hpp"
#include "LikeCriteria.hpp"
#include "DateCriteria.hpp"

class Utunes
{
    public:

        void startUtunes(string filePath);

    private:

        InputManager input;
        vector <Music*> musics;
        vector <User*> users;
        int playlistsNumber;

        void printInfos();

        void startProcess();
        void processCommand(int command, vector <string> options);

        void processPostSignup(vector <string> options);
        void processPostLogin(vector <string> options);
        void processPostLogout();
        void processGetAllSongs();
        void processGetSongs(vector <string> options);
        void processPostLikes(vector <string> options);
        void processGetLikes();
        void processDeleteLikes(vector <string> options);
        void processPostPlaylists(vector <string> options);
        void processGetPlaylists(vector <string> options);
        void processPostPlaylistsSongs(vector <string> options);
        void processGetPlaylistsSongs(vector <string> options);
        void processDeletePlaylistsSongs(vector <string> options);
        void processGetUsers();
        void processPostArtistFilters(vector <string> options);
        void processPostLikeFilters(vector <string> options);
        void processPostDateFilters(vector <string> options);
        void processDeleteFilters();
        void processPostComments(vector <string> options);
        void processGetComments(vector <string> options);

        bool canSignup(string email, string username);
        bool isUsersEmpty(User* user);
        bool isArtistAvailable(string artist);
        bool canComment(User* user, Music* music, string time);

        void addNewUser(string email, string username, string password);
        User* findUser(string email);
        User* findLoggedInUser();
        Music* findMusicById(string id);
        User* findUserByUser(string username);
        User* findUserByPlaylistId(string playlistId);

};

#endif