// Copyright [2015] <none>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "off.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::size_t;
using std::freopen;
using std::fflush;
using std::fclose;
using std::getline;

struct Person {
  string Name;
  string Vorname;
  string GebDatum;
};

const char kDelimiter{','};

string extract(char delimiter, string& s) {
  size_t pos = s.find(delimiter);
  if (pos == s.npos) {
    return s;
  }
  string r = s.substr(0, pos);
  s = s.substr(++pos);
  return r;
}

string br(string s) {
  return s + "<br />";
}

string b(string s) {
  return "<b>" + s + "</b>";
}

Person extrahiere_person(string eingabezeile) {
  string data[3];
  for (string& s : data) {
    s = trimme(extract(kDelimiter, eingabezeile));
  }
  return Person{ data[0], data[1], data[2] };
}

int main() {
  string eingabezeile, kurztext, langtext;
  if (!freopen("personendaten.txt", "r", stdin)) {
    return 1;
  }
  while(getline(cin, eingabezeile)) {
    Person p = extrahiere_person(eingabezeile);
    kurztext += br(
          b(p.Name) + ", " + p.Vorname
        ) + "\n";
    langtext += br(
          b(p.Vorname + " " + p.Name) +
          ", " + p.GebDatum
        ) + "\n";
  }
  fclose(stdin);

  if (!freopen("webseite.html.tmpl", "r", stdin)) {
    return 1;
  }
  if (!freopen("webseite.html", "w", stdout)) {
    return 1;
  }
  // Clear previous EOF
  cin.clear();
  
  // Not a good solution since the template file may be minified and huge
  while(getline(cin, eingabezeile)) {
    eingabezeile = ersetze(eingabezeile, '%', kurztext);
    eingabezeile = ersetze(eingabezeile, '$', langtext);
    cout << eingabezeile << "\n";
  }
  fflush(stdout);
  fclose(stdin);
  fclose(stdout);

  return 0;
}
