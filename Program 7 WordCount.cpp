/*****************************************************************
   Name:Siddi Annas Waheed                  Z-number: Z23590937
   Course:COP3104
   Professor: Dr.Lofton Bullard
   Due Date : 07/14/2021
   Total Points :
   Assignment# : 7
   Description :in this Program 7 we will read data from a file and store it into an string and then we will count the instance of each character stored in the file.
   *************************************************************/

   //Include the following
   //Reqd Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Prototypes for your functions: input, output, process, and count_inventory will go here
string input();
void process(string word, int abc[], int& words);
void output(string s, int abc[], int words);



//function definations 

string input() {

	ifstream in;
	in.open("word_data.txt");
	string s;
	
	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}

	else {
		//While loop will give the input of our array.
		cout << "Input opened correctly\n" << endl;
		getline(in, s);
	}
	in.close();

	return s;

}

 void process(string word, int abc[], int &words) {
	 //count the word 
	 //count how many an alphabet occured in the input file
	 
	 //initializing my words count variable to 1 for no space before first word
	 words = 1;
	 //initializing my alphabet count array 
	 for (size_t i = 0; i < 26; i++)
	 {
		 abc[i] = 0;
	 }

	 //holding my tulower string temporarily
	 char temp;

	 //ASCII 97 a to 122 z 
	 for (int i = 0; i < word.length(); i++)
	 {
		 temp = tolower(word[i]);
		 if (temp >= 97 && temp <= 122)
		 {
			 abc[temp - 97] += 1; 
		 }

		 //counting space in the strings and adding it to my words count var
		 if (temp == 32)
		 {
			 words += 1;
		 }
	 }
}

 void output(string s, int abc[], int words) {
	
	 cout << s << "\n" << endl;

	 cout << words << " Words" << endl;
	 
	 for (size_t i = 0; i < 26; i++)
	 {
		 if (abc[i] != 0)
		 {
			 cout << left << setw(2) << abc[i] << "  " << right << setw(2) << static_cast<char> (97 + i) << endl;
		 }
	 }
 }


int main()
{
	ifstream in;
	int abc[26];
	int words;

	string s = input();
	process(s, abc, words);
	output(s, abc, words);
}

