#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

class Song
{
public:
  std::string songTitle;
  std::string songArtist;
  int songBPM;
  bool songLiked;

  // Constructor
  Song(std::string songT, std::string songA, int songB, bool songL = false)
      : songTitle(songT), songArtist(songA), songBPM(songB), songLiked(songL) {}

  // Display song details
  void displayUserSong() const
  {
    std::cout << "---------------------------------\n";
    std::cout << "Title:  " << songTitle << "\n";
    std::cout << "Artist: " << songArtist << "\n";
    std::cout << "BPM:    " << songBPM << "\n";
    std::cout << "Liked:  " << (songLiked ? "Yes" : "No") << "\n";
    std::cout << "---------------------------------\n";
  }
};

class Playlist
{
private:
  std::string userPlaylistName;
  std::vector<Song> songs;

public:
  // Constructor
  Playlist(std::string uPlaylistName) : userPlaylistName(uPlaylistName) {}

  // Add a song to the playlist
  void addUserSong(const Song &song)
  {
    songs.push_back(song);
  }

  // Display the playlist
  void displayPlaylist() const
  {
    std::cout << "\n=============================\n";
    std::cout << "Playlist: " << userPlaylistName << "\n";
    std::cout << "=============================\n";

    if (songs.empty())
    {
      std::cout << "This playlist is empty... add songs foo! \n";
    }
    else
    {
      for (const Song &song : songs)
      {
        song.displayUserSong();
      }
    }

    std::cout << "=============================\n";
    std::cout << "    Total Songs: " << songs.size() << "\n";
    std::cout << "=============================\n";
  }

  // Sort the playlist by BPM
  void sortByBPM()
  {
    std::sort(songs.begin(), songs.end(), [](const Song &a, const Song &b)
              { return a.songBPM < b.songBPM; });
    std::cout << "Playlist sorted by BPM!\n";
  }

  // Add a song via user input
  void addSongFromInput()
  {
    char userChoice;
    do
    {
      std::string title, artist;
      int bpm;
      char songLikeInput;
      bool liked;

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
      std::cout << "Enter the title of the song: ";
      std::getline(std::cin, title);

      std::cout << "Enter artist name: ";
      std::getline(std::cin, artist);

      std::cout << "Enter BPM: ";
      std::cin >> bpm;

      std::cout << "Add song to favorites? (y/n): ";
      std::cin >> songLikeInput;
      liked = (songLikeInput == 'y' || songLikeInput == 'Y');

      // Add the song to the playlist
      songs.push_back(Song(title, artist, bpm, liked));
      std::cout << "Song added successfully!\n";

      std::cout << "Would you like to add another song? (y/n): ";
      std::cin >> userChoice;
    } while (userChoice == 'Y' || userChoice == 'y');
  }
};

int main()
{
  Playlist myPlaylist("Default Playlist");
  bool running = true;

  while (running)
  {
    // Display the menu
    std::cout << "\n=============================\n";
    std::cout << "          MAIN MENU\n";
    std::cout << "=============================\n";
    std::cout << "1. Add a Song to the Playlist\n";
    std::cout << "2. Display the Playlist\n";
    std::cout << "3. Sort Playlist by BPM\n";
    std::cout << "4. Create a New Playlist\n";
    std::cout << "5. Exit\n";
    std::cout << "=============================\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    // Handle user input
    switch (choice)
    {
    case 1:
    {
      std::cout << "\nAdding a new song:\n";
      myPlaylist.addSongFromInput();
      break;
    }
    case 2:
    {
      std::cout << "\nDisplaying playlist:\n";
      myPlaylist.displayPlaylist();
      break;
    }
    case 3:
    {
      std::cout << "\nSorting playlist by BPM...\n";
      myPlaylist.sortByBPM();
      break;
    }
    case 4:
    {
      std::cout << "\nEnter the name of the new playlist: ";
      std::string newName;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, newName);
      myPlaylist = Playlist(newName);
      std::cout << "New playlist created: " << newName << "\n";
      break;
    }
    case 5:
    {
      std::cout << "Exiting program. Goodbye!\n";
      running = false;
      break;
    }
    default:
    {
      std::cout << "Invalid choice. Please try again.\n";
      break;
    }
    }
  }

  return 0;
}
