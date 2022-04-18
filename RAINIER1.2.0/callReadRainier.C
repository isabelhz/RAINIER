#include <iostream>
#include <fstream>
#include <sstream>

{
  const int MAXE = 10;
  const int MAXJ = 10;
  ofstream file("statEJ.csv");
  file << "E/J" << ",";
  for (int i=1; i<MAXJ; i++) {
    file << i << ",";
  }

  readRainier **a;
  a = new readRainier* [(MAXE-1)*(MAXJ-1)];
  for(int E=1; E<MAXE; E++) {
    file << "\n" << E << ",";
    for(int J=1; J<MAXJ; J++) {
      cout << "\n" << E << " " << J << "\n";
      a[E*10+J-11] = new readRainier(E*10+J);
      a[E*10+J-11]->Loop();

      //cout << a[E*10+J-11]->finalStatE << " " << a[E*10+J-11]->finalStatJ << "\n";
      file << a[E*10+J-11]->finalStatE << " " << a[E*10+J-11]->finalStatJ << ",";

    }
  }

  file.close();
}
