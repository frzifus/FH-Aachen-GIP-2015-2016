#include "off.h"

using it = std::string::iterator;
using std::find_if;
using std::reverse;
using std::size_t;
using std::string;

void trim(string& s, it from, it to) {
  it pos = find_if(from, to, [](const char c) {
    return c == ' ' ? false : true;
  });
  if (pos != s.end()) {
    s.erase(from, pos);
  }
}

string trimme(string s) {
  trim(s, s.begin(), s.end());
  std::reverse(s.begin(), s.end());
  trim(s, s.begin(), s.end());
  std::reverse(s.begin(), s.end());
  return s;
}

string ersetze(string zeile, char zu_ersetzendes_zeichen, string ersatztext) {
  size_t pos{};
  // Alle Vorkommnisse vom Zeichen ersetzen!
  while ((pos = zeile.find(zu_ersetzendes_zeichen, pos)) != zeile.npos) {
    //      Der Teil der Zeile vor dem Zeichen
    zeile = zeile.substr(0, pos) + ersatztext
    //      Der Teil der Zeile hinter dem Zeichen
          + zeile.substr(pos + 1, zeile.length() - pos);
    pos += ersatztext.length();
  }
  return zeile;
}

