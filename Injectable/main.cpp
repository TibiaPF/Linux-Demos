#include <fstream>
#include <iostream>

using namespace std;

__attribute__((constructor))
void loadDll()
{
  ofstream outfile;
  outfile.open("/home/josh/test.txt");
  outfile << "This is a sample string" << endl;
  outfile.close();
}