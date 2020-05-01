// Section 20
// Challenge 2
//  Lists

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <string>

class Song {
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  std::string name;
  std::string artist;
  int rating;

 public:
  Song() = default;
  Song(std::string name, std::string artist, int rating)
      : name{name}, artist{artist}, rating{rating} {}
  std::string get_name() const { return name; }
  std::string get_artist() const { return artist; }
  int get_rating() const { return rating; }

  bool operator<(const Song &rhs) const { return this->name < rhs.name; }

  bool operator==(const Song &rhs) const { return this->name == rhs.name; }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
  os << std::setw(20) << std::left << s.name << std::setw(30) << std::left
     << s.artist << std::setw(2) << std::left << s.rating;
  return os;
}

void display_menu() {
  std::cout << std::setw(35) << "Welcome to MP3 player"
            << "\n";
  std::cout << std::setw(48) << std::setfill('=') << "\n" << std::setfill(' ');
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next song" << std::endl;
  std::cout << "P - Play Previous song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
  std::cout << "\nPlaying: " << song << "\n\n";
}

void display_playlist(const std::list<Song> &playlist,
                      const Song &current_song) {
  play_current_song(current_song);
  for (const Song &song : playlist) std::cout << song << std::endl;
}

void add_playlist(std::list<Song>::iterator &current_song,
                  std::list<Song> &playlist) {
  std::string name;
  std::string artist;
  int rating;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Enter song's name: ";
  std::getline(std::cin, name);

  std::cout << "Enter song's artist: ";
  std::getline(std::cin, artist);

  std::cout << "Enter song's rating: ";
  std::cin >> rating;
  std::cout << std::endl;

  playlist.insert(std::next(current_song), Song{name, artist, rating});
  play_current_song(*++current_song);
}

static void get_choice(char user_input, std::list<Song>::iterator &current_song,
                       std::list<Song> &playlist) {
  switch (user_input) {
    case 'F':
      current_song = playlist.begin();
      play_current_song(*current_song);
      break;
    case 'N': {
      current_song = std::next(current_song);
      if (current_song == playlist.end()) current_song = playlist.begin();
      play_current_song(*current_song);
    } break;
    case 'P': {
      if (current_song == playlist.begin()) current_song = playlist.end();
      current_song = std::prev(current_song);
      play_current_song(*current_song);
    } break;
    case 'A': {
      add_playlist(current_song, playlist);
    } break;
    case 'L':
      display_playlist(playlist, *current_song);
      break;
    default:
      break;
  }
}

int main() {
  std::list<Song> playlist{{"God's Plan", "Drake", 5},
                           {"Never Be The Same", "Camila Cabello", 5},
                           {"Pray For Me", "The Weekend and K. Lamar", 4},
                           {"The Middle", "Zedd, Maren Morris & Grey", 5},
                           {"Wait", "Maroone 5", 4},
                           {"Whatever It Takes", "Imagine Dragons", 3}};

  std::list<Song>::iterator current_song = playlist.begin();

  char user_input;
  while (1) {
    display_menu();
    std::cin >> user_input;
    user_input = std::toupper(user_input);
    if (user_input == 'Q') break;
    get_choice(user_input, current_song, playlist);
  }

  std::cout << "Thanks for listening!" << std::endl;
  return 0;
}