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
	//The final result will be (right concat with XOR(left,mangle(key,right)))
	string left = binInputBlock.substr(0, 32);
	string right = binInputBlock.substr(32, 32);


	char expansionArray[] = {right[31], right[0], right[1], right[2], right[3], right[4], right[3], right[4], right[5], right[6], right[7], right[8], right[7],
								right[8], right[9], right[10], right[11], right[12], right[11], right[12], right[13], right[14], right[15], right[16], right[15],
								right[16], right[17], right[18], right[19], right[20], right[19], right[20], right[21], right[22], right[23], right[24], right[23],
								right[24], right[25], right[26], right[27], right[28], right[27], right[28], right[29], right[30], right[31], right[0]};
	string expArray;

	for (int i = 0; i < 48; i++)
		expArray += expansionArray[i];

	cout << expArray << endl;


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
