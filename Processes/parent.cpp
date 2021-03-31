#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

void Processing(string File, int FragmentSize, int OperationNumb);
int fileSize(string path_to_file) {
	ifstream file(path_to_file, ios::binary | ios::ate);
	return file.tellg();
}

int main(int argc, char* argv[])
{
    if(argc < 3){
        cout << "Wrong parameters count!\nCancel" << endl;
        exit(1);
    }
    	cout << "Main programm with pid = " << getpid()<<endl;
	string INPUT_FILE = argv[1];
	const int DIVIDER = stoi(argv[2]);

	int FRAGMENT_SIZE = fileSize(INPUT_FILE) / DIVIDER;

	for (int i = 0; i < DIVIDER; i++) 
		Processing(INPUT_FILE, FRAGMENT_SIZE, i);

	return 0;
}

void Processing(string File, int FragmentSize, int OperationNumb) {
	pid_t pid = fork();
	if(pid < 0) {
		cout << "Error to run procces " << OperationNumb+1 << endl;
	 	return;
	}
	if(pid == 0) {
		int offset = OperationNumb * FragmentSize;
		string OUTPUT_FILE = "data_operation_"+to_string(OperationNumb+1)+".txt";
		char *parameters[] = {
			(char*)File.c_str(),
			(char*)to_string(offset).c_str(),
			(char*)to_string(FragmentSize).c_str(),
			(char*)OUTPUT_FILE.c_str(),
			NULL
		};
		cout << "Run " << OperationNumb + 1 << " process with pid = "<< getpid()<<endl;
		execv("child", parameters);
	}
	// else {
	    // int code;
        // wait(&code);
        // cout<<"Child process "<<OperationNumb+1<<" ended with code " << WEXITSTATUS(code) << endl;
	// }
}

