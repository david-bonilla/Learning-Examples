#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations
void addSong(vector<pair<string, string>> &playlist);
void shufflePlaylist(vector<pair<string, string>> &playlist);
void sortPlaylist(vector<pair<string, string>> &playlist);
void viewPlaylist(const vector<pair<string, string>> &playlist);

int main()
{
  vector<pair<string, string>> playlist; // Vector to store (title, artist) pairs
  char choice;                           // User choice for menu

  do
  {
    cout << "\nDJ Playlist Menu\n";
    cout << "1. Add a song\n";
    cout << "2. View playlist\n";
    cout << "3. Sort playlist\n";
    cout << "4. Shuffle playlist\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
      addSong(playlist);
      break;
    case '2':
      viewPlaylist(playlist);
      break;
    case '3':
      sortPlaylist(playlist);
      break;
    case '4':
      shufflePlaylist(playlist);
      break;
    case '5':
      cout << "Exiting program..." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != '5');

  return 0;
}

// Function definitions
void addSong(vector<pair<string, string>> &playlist)
{
  string title, artist;
  cin.ignore(); // Clear the input buffer
  cout << "Enter the title of the song: ";
  getline(cin, title); // Read title
  cout << "Enter the artist of the song: ";
  getline(cin, artist); // Read artist

  playlist.push_back(make_pair(title, artist)); // Add song to playlist
  cout << "Song added successfully!\n";
}

void viewPlaylist(const vector<pair<string, string>> &playlist)
{
  if (playlist.empty())
  {
    cout << "Playlist is empty. Add some songs first!\n";
    return;
  }
  cout << "Your Playlist:\n";
  for (const auto &song : playlist)
  {
    cout << "Title: " << song.first << " | Artist: " << song.second << endl;
  }
}

void sortPlaylist(vector<pair<string, string>> &playlist)
{
  cout << "Sorting playlist by title...\n";
  sort(playlist.begin(), playlist.end(),
       [](const pair<string, string> &a, const pair<string, string> &b)
       { return a.first < b.first; });
  cout << "Playlist sorted successfully!\n";
}

void shufflePlaylist(vector<pair<string, string>> &playlist)
{
  random_shuffle(playlist.begin(), playlist.end());
  cout << "Playlist shuffled successfully!\n";
}
