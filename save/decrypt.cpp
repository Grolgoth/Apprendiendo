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

std::string encrypt(std::string name)
{
    for (unsigned int i = 0; i < name.size(); i++)
    {
        name[i] = 50 - name[i] + i%2;
    }
    return name;
}

void doDecrypt (string filename){
    ifstream in(filename + ".save");
    in.unsetf(ios_base::skipws);
    std::string full = "";
    char c;
    while(in >> c)
        full += c;
    full = decrypt(full);
    cout<<full<<endl;
    in.close();
    ofstream out(filename + ".xml");
    out.unsetf(ios_base::skipws);
    out << full;
    out.close();
}

void doEncrypt (string filename) {
    ifstream in(filename + ".xml");
    in.unsetf(ios_base::skipws);
    std::string full = "";
    char c;
    while(in >> c)
        full += c;
    full = encrypt(full);
    cout<<full<<endl;
    in.close();
    ofstream out(filename + ".save");
    out.unsetf(ios_base::skipws);
    out << full;
    out.close();
}

int main(int argc, char *argv[])
{
    cout << "Filename:" << endl;
    std::string filename;
    getline(cin, filename);
    cout << filename << endl;
    cout << "Encrypt? (0 = yes, anything else = no)" << endl;
    std::string answer;
    getline(cin, answer);
    if (answer == "0")
        doEncrypt(filename);
    else
        doDecrypt(filename);
    return 0;
}
