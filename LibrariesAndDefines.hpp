#ifndef LibariesAndDefines_H
#define LibariesAndDefines_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <exception>
#include <map>
#include <fstream>

using namespace std;

#define ZERO 0
#define EMPTY ""
#define SPLITING_MARK ','
#define SEPARATING_MARK "?"


#define MUSIC_ID "id"
#define MUSIC_TITLE "title"
#define MUSIC_ARTIST "artist"
#define MUSIC_RELEASE_YEAR "release_year"
#define MUSIC_LINK "link"


#define GET_STR "GET"
#define POST_STR "POST"
#define DELETE_STR "DELETE"


#define SIGNUP_STR "signup"
#define LOGIN_STR "login"
#define LOGOUT_STR "logout"
#define SONGS_STR "songs"
#define LIKES_STR "likes"
#define PLAYLISTS_STR "playlists"
#define PLAYLISTS_SONGS_STR "playlists_songs"
#define USERS_STR "users"
#define FILTERS_STR "filters"
#define COMMENTS_STR "comments"


#define EMAIL_STR "email"
#define USERNAME_STR "username"
#define PASSWORD_STR "password"
#define ID_STR "id"
#define NAME_STR "name"
#define PRIVACY_STR "privacy"
#define PLAYLIST_ID_STR "playlist_id"
#define SONG_ID_STR "song_id"
#define PLAYLISTS_SONGS_STR "playlists_songs"
#define ARTIST_STR "artist"
#define MIN_YEAR_STR "min_year"
#define MAX_YEAR_STR "max_year"
#define MIN_LIKE_STR "min_like"
#define MAX_LIKE_STR "max_like"
#define TIME_STR "time"
#define COMMENT_STR "comment"

#define PUBLIC_STR "public"
#define PRIVATE_STR "private"

#define POST_SIGNUP 100
#define POST_LOGIN 101
#define POST_LOGOUT 102

#define GET_ALL_SONGS 117
#define GET_SONGS 103

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
#define GET_COMMENTS 116


#define BAD_REQUEST_ERROR "Bad Request"
#define NOT_FOUND_ERROR "Not Found"
#define PERMISSION_DENIED_ERROR "Permission Denied"
#define EMPTY_ERROR "Empty"

#define PROCESS_DONE "OK"

#define PRIVATE 10
#define PUBLIC 20

#define DATE_STR "date"
#define LIKE_STR "like"


#endif