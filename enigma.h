#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <vector>
using namespace std;

struct node
{
	char val;
	node *nextchar;
	node *nextstep;
	bool lower = false;//If the original letter was lowercase.
					   //	node *prev;
};
struct Rotor
{
	std::vector<char> cipher;
};
class Enigma
{
public:
	Enigma();
	void setRings(string);
	void defaultRotors(bool);
	string Encrypt(string);
	string Decrypt(string);
	string DecryptH(string);
	void printEncrypt();
	void printDecrypt();
	void printRotorSettings();
	void printPlugBoard();
	void defaultPlugs(bool);
private:
	void createRotors();
	void ringMod(int, Rotor&);
	void createplugBoard();
	void createReflector();
	void segmentInput(std::string);
	void rotateRotor(Rotor&);
	char inverseMatch(char, Rotor);
	char plug(char);
	bool defaultP;
	bool defaultR;
	char letters[26];
	int count;
	std::string input;
	char cinput;
	std::string plugBoard[10];
	char ringSettings[3];
	Rotor R1, R2, R3, reflector;
	node *root;
	node *froot;
	bool * lower_array;
};
#endif
