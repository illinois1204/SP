#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>
#include <mutex>
#include <thread>
using namespace std;

void TrigrammProccesing(string FragmentText, short OperationNumb);
int fileSize(string path_to_file) {
    ifstream file(path_to_file, ios::binary | ios::ate);
    return file.tellg();
}

mutex mtx;
map<string, int> Trigramms; //разделяемый ресурс
int main(int argc, char* argv[])
{
    string INPUT_FILE = argv[1];
    const int DIVIDER = stoi(argv[2]);
    cout << "Main programm started!" << endl;

    string TEXT, row;
    ifstream fin;
    ofstream fout;
    fin.open(INPUT_FILE);
    if (!fin.is_open()) {
        cout << "Error to open file" << endl;
        exit(1);
    }
    while (getline(fin, row))
        TEXT += row;
    fin.close();

    int FRAGMENT_SIZE = ceil(((float)fileSize(INPUT_FILE) / DIVIDER));
    vector<thread> Text_threads;

    for (short i = 0; i < DIVIDER; i++) {
        int offset = i * FRAGMENT_SIZE;
        Text_threads.push_back( thread(TrigrammProccesing, TEXT.substr(offset, FRAGMENT_SIZE+2), i) );
    }

    for (short th = 0; th < DIVIDER; th++)
        Text_threads[th].join();

    cout << "All threads are finished!" << endl;
    cout << "Quantity of Trigramms: " << Trigramms.size() << endl;

    fout.open("output.txt");
    fout << "Quantity of Trigramms: " << Trigramms.size() << endl << endl;
    for (auto it : Trigramms)
        fout << "Trig: " << it.first << "\tFrequency: " << it.second << endl;
    fout.close();
    return 0;
}

void TrigrammProccesing(string FragmentText, short OperationNumb)
{
    transform(FragmentText.begin(), FragmentText.end(), FragmentText.begin(), ::tolower);
    int frequency;
    
    for (int i = 1; i < FragmentText.length() - 1; i++) 
    {
        if (isalpha(FragmentText[i-1]) && isalpha(FragmentText[i]) && isalpha(FragmentText[i+1]) )  
        {
            string trio = string(1, FragmentText[i - 1]) + string(1, FragmentText[i]) + string(1, FragmentText[i + 1]);
            mtx.lock();
            auto it = Trigramms.find(trio);
            it == Trigramms.end() ? frequency = 1 : frequency = it->second+1;
            Trigramms[trio] = frequency;
            mtx.unlock();
        }
    }
}
