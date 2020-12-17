#ifndef User_H
#define User_H

#include "LibrariesAndDefines.hpp"
#include "Music.hpp"
#include "Criteria.hpp"
#include "ArtistCriteria.hpp"
#include "DateCriteria.hpp"
#include "LikeCriteria.hpp"


class Playlist
{
    public:
        Playlist(int id_, string name_, string privacy_);

        void printAllInfo();
        void printPublicInfo();
        void showSongs(string email, string loggedInEmail);

        void addMusic(Music* music);
        void deleteMusic(Music* music);

        int getId();

    private:

        string name;
        int privacy;
        int id;
        vector <Music*> musics;

        bool isMusicHere(Music* music);
};


class User
{
    public:
        User(string email_, string username_, string password_);
        string getEmail();
        string getUsername();
        string getPassword();

        void printInfo();

        bool isLogin();

        void login();
        void logout();

        bool canLike(string id);
        bool isPlaylistHere(string playlistId);
        //bool isCriteriaUsed();

        void addSongToPlayList(string playlistId, Music* music);
        void addNewPlaylist(int id, string name, string privacyStatus);
        void addToLikedMusic(Music* music);
        void removeFromLikedMusic(Music* music);
        void deleteSongFromPlaylist(string playlistId, Music* music);
        void putArtistCriteria(string name, vector <Music*> allMusics);

        void printLikedMusic();
        void showPlaylists(string username_);
        void showSongsInPlaylist(string playlistId, string loggedInEmail);
        void printCriteriaSongInfo();

    private:
        string username;
        string email;
        string password;
        bool loggedIn;
        vector <Music*> likedMusic;
        vector <Playlist> playlists;
        //bool usedCriteria;
        //vector <Music*> criteriaMusics;
        //Criteria* criteria;

        void printAllPlaylistsInfo();
        void printPublicPlaylistsInfo();

        void addNewArtistCriteria(string name, vector <Music*> allMusics);
        //bool isArtistCriteriaUsed();
        void deleteLastArtistCriteria();
        
    
};

#endif