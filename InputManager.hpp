#ifndef InputManager_H
#define InputManager_H

#include "LibrariesAndDefines.hpp"
#include "Music.hpp"


class InputManager
{
    public:

        void getFromCSV(string filePath);
        void getInput();
        vector <Music*> getMusics();
        vector <string> getOptions();
        int getCommand();


    private:

        vector <Music*> fileMusics;
        int mainCoammad;
        int command;
        vector <string> options;

        vector <string> splitFileLine(string inputLine);
        vector <string> splitToWords(string inputLine);

        void addNewMusic(vector <string> musicInfo);

        int findCommand(vector <string> splitedInput);

        bool isPostSignUp(vector <string> input);
        bool isPostLogin(vector <string> input);
        bool isPostLogout(vector <string> input);
        bool isGetAllSongs(vector <string> input);
        bool isGetSongs(vector <string> input);
        bool isPostLikes(vector <string> input);
        bool isGetLikes(vector <string> input);
        bool isDeleteLikes(vector <string> input);
        bool isPostPlaylists(vector <string> input);
        bool isGetPlaylists(vector <string> input);
        bool isPostPlaylistsSongs(vector <string> input);
        bool isGetPlaylistsSongs(vector <string> input);
        bool isDeletePlaylistsSongs(vector <string> input);
        bool isGetUsers(vector <string> input);
        bool isPostArtistFilters(vector <string> input);
        bool isPostDateFilters(vector <string> input);
        bool isPostLikeFilters(vector <string> input);
        bool isDeleteFilters(vector <string> input);
        bool isPostComments(vector <string> input);
        bool isGetComments(vector <string> input);
};

#endif