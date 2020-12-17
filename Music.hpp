#ifndef Music_H
#define Music_H

#include "LibrariesAndDefines.hpp"

class Comment;

class Music
{
    public:
        Music(vector <string> musicInfo);

        void printInfo();
        void printCompleteInfo();

        void putComment(string time, string commentTxt, string username);

        void showComments();

        void like();
        void dislike();

        void increasePlaylists();
        void decreasePlaylists();

        string getId();
        string getArtistName();
        int getLike();

    private:
        string id;
        string title;
        string artist;
        string releaseYear;
        string link;
        int likes;
        int playlists;
        vector <Comment> comments;
};

class Comment
{
    public:
        Comment(string time_, string commentTxt_, string username_);

        void printComment();

    private:

        string commentTxt;
        string time;
        string username;

};

#endif