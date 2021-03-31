#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string INPUT_FILE = argv[0];
    const int OFFSET = stoi(argv[1]);
    const int FRAGMENT_SIZE = stoi(argv[2]);
    string OUTPUT_FILE = argv[3];

    string Text, row;
    ifstream fin;
	ofstream fout;
    fin.open(INPUT_FILE);
    if (!fin.is_open()) {
        cout << "Error to open file" << endl;
        exit(1);
    }
    while (getline(fin, row)) 
        Text += row;
    fin.close();

    Text = Text.substr(OFFSET, FRAGMENT_SIZE);
    transform(Text.begin(), Text.end(), Text.begin(), ::tolower);

    int frequency;
    map<string, int> Trigramms;

    for (int i = 1; i < Text.length() - 1; i++) 
    {
        if (isalpha(Text[i-1]) && isalpha(Text[i]) && isalpha(Text[i+1]) )  
        {
            string trio = string(1, Text[i - 1]) + string(1, Text[i]) + string(1, Text[i + 1]);
            auto it = Trigramms.find(trio);
            it == Trigramms.end() ? frequency = 1 : frequency = it->second+1;
            Trigramms[trio] = frequency;
        }
    }

	fout.open(OUTPUT_FILE);
    fout << "Fragment of text:" << endl<<Text<<endl<<endl;
    fout << "Quantity of Trigramms: " << Trigramms.size() << endl<<endl;
    for(auto it : Trigramms)
        fout << "Trig: " << it.first << "\tFrequency: "<< it.second << endl;
	fout.close();
    exit(0);
}
