#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Homework - Exercise 1
struct Song {
    string songName;
    Song *next;
    Song *prev;
    Song(string s) {
        songName = s;
        next = nullptr;
        prev = nullptr;
    }
};

struct Playlist {
    Song *first;
    Song *last;
    Song *current;
    Playlist() {
        first = nullptr;
        last = nullptr;
        current = nullptr;
    }
    void addSong(string s) {
        Song *newSong = new Song(s);
        if (first == nullptr) {
            first = last = newSong;
            last->next = first;
            first->next = last;
        } else {
            last->next = newSong;
            newSong->prev = last;
            newSong->next = first;
            first->prev = newSong;
            last = newSong;
        }
        current = first;
    }
    void removeSong(string s) {
        if (first == nullptr) return;
        Song *temp = first;
        do {
            if (temp->songName == s) {
                if (temp == first) {
                    if (first == last) {
                        delete first;
                        first = last = nullptr;
                        current = nullptr;
                    } else {
                        first = first->next;
                        first->prev = last;
                        last->next = first;
                        delete temp;
                        current = first;
                    }
                } else if (temp == last) {
                    last = last->prev;
                    last->next = first;
                    first->prev = last;
                    delete temp;
                    current = first;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
                return;
            }
            temp = temp->next;
        } while (temp != nullptr);
    }
    void nextSong() {
        if (first != nullptr)
            first = first->next;
    }
    void prevSong() {
        if (first != nullptr)
            first = first->prev;
    }
    void displaySongs() {
        if (first == nullptr) return;
        Song *currentSong = first;
        do {
            cout << currentSong->songName << " ";
            currentSong = currentSong->next;
        } while (currentSong != first);
        cout << endl;
    }
};

void MusicPlayer() {
    Playlist music;
    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;
    string operation;
    cout << "Enter your operations: " << endl;
    for (int i = 0; i < operations; i++) {
        cin >> operation;
        if (operation == "ADD") {
            string songName;
            cin >> songName;
            music.addSong(songName);
        } else if (operation == "NEXT") {
            music.nextSong();
        } else if (operation == "PREV") {
            music.prevSong();
        } else if (operation == "DISPLAY") {
            music.displaySongs();
        } else if (operation == "REMOVE") {
            string removeName;
            cin >> removeName;
            music.removeSong(removeName);
        }
    }
}

//Homework - Exercise 2
struct Tab {
    string url;
    Tab *prev;
    Tab *next;
    Tab(string webpage) {
        url = webpage;
        prev = nullptr;
        next = nullptr;
    }
};

struct BrowserHistory {
    Tab *first;
    Tab *last;
    Tab *current;
    BrowserHistory(string webpage) {
        Tab *initialTab = new Tab(webpage);
        first = last = current = initialTab;
    }
    void visitURL(string webpage) {
        Tab *newTab = new Tab(webpage);
        if (current != last) {
            current->next = nullptr;
            last = current;
        }
        last->next = newTab;
        newTab->prev = last;
        last = newTab;
        current = newTab;
    }
    void back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->prev == nullptr) break;
            current = current->prev;
        }
    }
    void forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (current->next == nullptr) break;
            current = current->next;
        }
    }
    void showCurrentTab() {
        cout << current->url << " ";
    }
};

void WebBrowser() {
    vector<string> commands;
    vector<string> webpages;
    string input;
    cout << "Input your commands (type 'done' when finished):\n";
    while (true) {
        cin >> input;
        if (input == "done") break;
        commands.push_back(input);
    }
    cout << "Input URLs and steps (type 'done' when finished):\n";
    while (true) {
        cin >> input;
        if (input == "done") break;
        webpages.push_back(input);
    }
    BrowserHistory history(webpages[0]);
    cout << "null ";
    for (int i = 1; i < commands.size(); i++) {
        if (commands[i] == "visit") {
            history.visitURL(webpages[i]);
            cout << "null ";
        } else if (commands[i] == "back") {
            history.back(stoi(webpages[i]));
            history.showCurrentTab();
        } else if (commands[i] == "forward") {
            history.forward(stoi(webpages[i]));
            history.showCurrentTab();
        }
    }
}

//Homework - Exercise 3
struct Token {
    string id;
    int expiration;
    Token *next;
    Token(string tokenID, int expTime) {
        id = tokenID;
        expiration = expTime;
        next = nullptr;
    }
};

struct AuthenticationManager {
    int timeToLive;
    Token *head;
    AuthenticationManager(int ttl) {
        timeToLive = ttl;
        head = nullptr;
    }
    void generateToken(string tokenID, int currentTime) {
        int expTime = currentTime + timeToLive;
        Token *newToken = new Token(tokenID, expTime);
        newToken->next = head;
        head = newToken;
    }
    void renewToken(string tokenID, int currentTime) {
        Token *currentToken = head;
        while (currentToken != nullptr) {
            if (currentToken->id == tokenID && currentToken->expiration > currentTime) {
                currentToken->expiration = currentTime + timeToLive;
                return;
            }
            currentToken = currentToken->next;
        }
    }
    int countValidTokens(int currentTime) {
        int validCount = 0;
        Token *currentToken = head;
        while (currentToken != nullptr) {
            if (currentToken->expiration > currentTime) {
                validCount++;
            }
            currentToken = currentToken->next;
        }
        return validCount;
    }
};

void Authentication() {
    vector<string> commands;
    string input;
    cout << "Input your commands (type 'done' when finished):\n";
    while (true) {
        cin >> input;
        if (input == "done") break;
        commands.push_back(input);
    }

    AuthenticationManager *authManager = nullptr;

    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == "AuthenticationManager") {
            int ttl;
            cin >> ttl;
            authManager = new AuthenticationManager(ttl);
            cout << "null ";
        } else if (commands[i] == "generate" || commands[i] == "renew") {
            string tokenID;
            int currentTime;
            cin >> tokenID >> currentTime;
            if (commands[i] == "generate") {
                authManager->generateToken(tokenID, currentTime);
                cout << "null ";
            } else {
                authManager->renewToken(tokenID, currentTime);
                cout << "null ";
            }
        } else if (commands[i] == "countUnexpiredTokens") {
            int currentTime;
            cin >> currentTime;
            int count = authManager->countValidTokens(currentTime);
            cout << count << " ";
        }
    }
}

void menu() {
    cout << "Enter your choice: " << endl;
    cout << "1. Music player" << endl;
    cout << "2. Web browser" << endl;
    cout << "3. AuthenticationManager Class" << endl;
    int input;
    cin >> input;
    switch (input) {
    case 1:
        MusicPlayer();
        break;
    case 2:
        WebBrowser();
        break;
    case 3:
        Authentication();
        break;
    }
}

int main() {
    menu();
}
