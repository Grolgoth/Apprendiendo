#include <iostream>
#include <string>
#include <fstream>

using namespace std;

std::string decrypt(std::string name) {
    for (unsigned int i = 0; i < name.size(); i++)
    {
        name[i] = -1* name[i] + 50 +i%2;
        cout<<name[i]<<endl;
    }
    return name;
}

int main(int argc, char *argv[])
{
    std::string filename;
    getline(cin, filename);
    cout << filename << endl;
    ifstream in(filename + ".save");
    std::string full = "";
    char c;
    while(in >> c)
        full += c;
    full = decrypt(full);
    cout<<full<<endl;
    in.close();
    ofstream out(filename + ".xml");
    out << full;
    out.close();
    return 0;
}
