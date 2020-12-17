#include "InputManager.hpp"

void InputManager::getFromCSV(string filePath)
{
    //map <string, int> columns;
    string columnInfo = EMPTY;
    ifstream CSVFile(filePath);

    //int columnIndex = ZERO;
    getline(CSVFile, columnInfo);
    vector <string> titles = splitFileLine(columnInfo);
   // for (int i = ZERO; i < titles.size(); i++)
   	//{
        //cout <<"********" <<titles[i] <<"********"<< endl;
     	//columns[titles[i]] = i;
  	//}
    columnInfo = EMPTY;
    while(getline(CSVFile, columnInfo))
    {
        vector <string> tempInfo = splitFileLine(columnInfo);
        addNewMusic(tempInfo);
        columnInfo = EMPTY;
        tempInfo.clear();

    }
}


vector <string> InputManager::splitFileLine(string inputLine)
{
	vector <string> lineInfo;
    string word;
    stringstream ss(inputLine);
	while (getline(ss, word, SPLITING_MARK))
	{
		lineInfo.push_back(word);
	}
	return lineInfo;
}

void InputManager::addNewMusic(vector <string> musicInfo)
{
    Music* music = new Music(musicInfo);
    fileMusics.push_back(music);
}

vector <Music*> InputManager::getMusics()
{
    return fileMusics;
}

int InputManager::getCommand()
{
    return command;
}

vector <string> InputManager::getOptions()
{
    return options;
}

void InputManager::getInput()
{
    string inputLine = EMPTY;
	getline(cin, inputLine);
    vector <string> splitedInput = splitToWords(inputLine);
    command = findCommand(splitedInput);
    if (splitedInput.size() > 2)
        splitedInput.erase(splitedInput.begin() , splitedInput.begin() + 3);
    else
        splitedInput.clear();
    options = splitedInput;
}

vector <string> InputManager::splitToWords(string inputLine)
{
	vector <string> splitedInput;
	stringstream S(inputLine);
	string inputWord = EMPTY;
	while (S >> inputWord)
		splitedInput.push_back(inputWord);
	return splitedInput;
}

int InputManager::findCommand(vector <string> input)
{
    int size = input.size();
    if (isPostSignUp(input))
    {
        if (size == 9)
            return POST_SIGNUP;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isPostLogin(input))
    {
        if (size == 7)
            return  POST_LOGIN;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isPostLogout(input))
    {
        if (size == 2)
            return  POST_LOGOUT;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isGetAllSongs(input) || isGetSongs(input))
    {
        if (size == 2)  
            return GET_ALL_SONGS;
        else if (size == 5)
            return GET_SONGS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isPostLikes(input))
    {
        if (size == 5)
            return POST_LIKES;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isDeleteLikes(input))
    {
        if (size == 5)
            return  DELETE_LIKES;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isGetLikes(input))
    {
        if (size == 2)
            return GET_LIKES;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isPostPlaylists(input))
    {
        if (size == 7)
            return POST_PLAYLISTS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isGetPlaylists(input))
    {
        if (size == 5)
            return  GET_PLAYLISTS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isPostPlaylistsSongs(input))
    {
        if (size == 7)
            return POST_PLAYLISTS_SONGS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);    
    }
    else if (isGetPlaylistsSongs(input))
    {
        if (size == 5)
            return GET_PLAYLISTS_SONGS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isDeletePlaylistsSongs(input))
    {
        if (size == 7)
            return  DELETE_PLAYLISTS_SONGS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isGetUsers(input))
    {
        if (size == 2)
            return GET_USERS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isPostArtistFilters(input))
    {
        if (size > 4)
            return POST_ARTIST_FILTERS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);    
    }
    else if (isPostDateFilters(input))
    {
        if (size == 7)
            return POST_DATE_FILTERS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);    
    }
    else if (isPostLikeFilters(input))
    {
        if (size == 7)
            return POST_LIKE_FILTERS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);    
    }
    else if (isDeleteFilters(input))
    {
        if (size == 2)
            return DELETE_FILTERS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isPostComments(input))
    {
        if (size == 9)
            return  POST_COMMENTS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else if (isGetComments(input))
    {
        if (size == 5)
            return GET_COMMENTS;
        else
            throw runtime_error(BAD_REQUEST_ERROR);
    }
    else
    {
        throw runtime_error(NOT_FOUND_ERROR);
    }   
}

bool InputManager::isPostSignUp(vector <string> input)
{
    return input[0] == POST_STR && input[1] == SIGNUP_STR && input[3] == EMAIL_STR && input[5] == USERNAME_STR && input[7] == PASSWORD_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isPostLogin(vector <string> input)
{
    return input[0] == POST_STR && input[1] == LOGIN_STR && input[3] == EMAIL_STR && input[5] == PASSWORD_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isPostLogout(vector <string> input)
{
    return input[0] == POST_STR && input[1] == LOGOUT_STR;
}

bool InputManager::isGetAllSongs(vector <string> input)
{
    return input[0] == GET_STR && input[1] == SONGS_STR;
}

bool InputManager::isGetSongs(vector <string> input)
{
    return input[0] == GET_STR && input[1] == SONGS_STR && input[3] == ID_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isPostLikes(vector <string> input)
{
    return input[0] == POST_STR && input[1] == LIKES_STR && input[3] == ID_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isGetLikes(vector <string> input)
{
    return input[0] == GET_STR && input[1] == LIKES_STR;
}

bool InputManager::isDeleteLikes(vector <string> input)
{
    return input[0] == DELETE_STR && input[1] == LIKES_STR && input[3] == ID_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isPostPlaylists(vector <string> input)
{
    return (input[0] == POST_STR && input[1] == PLAYLISTS_STR && input[3] == NAME_STR && input[5] == PRIVACY_STR && input[2] == SEPARATING_MARK && input[6] == PRIVATE_STR) 
        || (input[0] == POST_STR && input[1] == PLAYLISTS_STR && input[3] == NAME_STR && input[5] == PRIVACY_STR && input[2] == SEPARATING_MARK && input[6] == PUBLIC_STR);
}

bool InputManager::isGetPlaylists(vector <string> input)
{
    return input[0] == GET_STR && input[1] == PLAYLISTS_STR && input[3] == USERNAME_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isPostPlaylistsSongs(vector <string> input)
{
    return input[0] == POST_STR && input[1] == PLAYLISTS_SONGS_STR && input[3] == PLAYLIST_ID_STR && input[5] == SONG_ID_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isGetPlaylistsSongs(vector <string> input)
{
    return input[0] == GET_STR && input[1] == PLAYLISTS_SONGS_STR && input[3] == PLAYLIST_ID_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isDeletePlaylistsSongs(vector <string> input)
{
    return input[0] == DELETE_STR && input[1] == PLAYLISTS_SONGS_STR && input[3] == PLAYLIST_ID_STR && input[5] == SONG_ID_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isGetUsers(vector <string> input)
{
    return input[0] == GET_STR && input[1] == USERS_STR;
}

bool InputManager::isPostArtistFilters(vector <string> input)
{
    return input[0] == POST_STR && input[1] == FILTERS_STR && input[3] == ARTIST_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isPostDateFilters(vector <string> input)
{
    return input[0] == POST_STR && input[1] == FILTERS_STR && input[3] == MIN_YEAR_STR && input[5] == MAX_YEAR_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isPostLikeFilters(vector <string> input)
{
    return input[0] == POST_STR && input[1] == FILTERS_STR && input[3] == MIN_LIKE_STR && input[5] == MAX_LIKE_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isDeleteFilters(vector <string> input)
{
    return input[0] == DELETE_STR && input[1] == FILTERS_STR;
}

bool InputManager::isPostComments(vector <string> input)
{
    return input[0] == POST_STR && input[1] == COMMENTS_STR && input[3] == SONG_ID_STR && input[5] == TIME_STR && input[7] == COMMENT_STR && input[2] == SEPARATING_MARK;
}

bool InputManager::isGetComments(vector <string> input)
{
    return input[0] == GET_STR && input[1] == COMMENTS_STR && input[3] == SONG_ID_STR && input[2] == SEPARATING_MARK;
}