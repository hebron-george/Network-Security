#include <iostream>
#include <string>

using namespace std;

string hexToBin(string hex);

int main()
{
	//Get input block from user
	string inputBlock;
	cout << "Insert the input block: ";
	cin >> inputBlock;

	//Get key value from user
	string key;
	cout << "Insert the key: ";
	cin >> key;

	//convert input block to a binary string
	string binInputBlock = hexToBin(inputBlock);

	//Left and Right of original binary input
	string left = binInputBlock.substr(0, 32);
	string right = binInputBlock.substr(32, 32);
	return 0;
}

string hexToBin(string hex)
{
	string hexArray[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
	string temp = "";
	int index;

	for (int i = 0; i < hex.length(); i++)
	{
		if (hex[i] == 'a' || hex[i] == 'A')
			index = 10;
		else if (hex[i] == 'b' || hex[i] == 'B')
			index = 11;
		else if (hex[i] == 'c' || hex[i] == 'C')
			index = 12;
		else if (hex[i] == 'd' || hex[i] == 'D')
			index = 13;
		else if (hex[i] == 'e' || hex[i] == 'E')
			index = 14;
		else if (hex[i] == 'f' || hex[i] == 'F')
			index = 15;
		else
			index = hex[i] - '0';
		temp += hexArray[index];
	}
	return temp;
}
