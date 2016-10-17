#include <iostream>
#include <string>
using namespace std;

int checkMaxPali(const string in_str){
	int pali_length = 1;
	int cur_pali_len = 1;
	int str_len = in_str.length();

	for(int mid_pos = 1; mid_pos <= str_len/2; mid_pos++) {
		int dist = 1;
		while( in_str[mid_pos-dist] == in_str[mid_pos+dist] && dist <= mid_pos) {
			dist++;
			cur_pali_len += 2;
		}
		pali_length = max(cur_pali_len, pali_length);
		cur_pali_len = 1;
	}
	
	return pali_length;
}

string stringProcess(const string in_str){
	string prepared_str;
	int str_len = in_str.length();
	int prepared_len = str_len*2 + 1;

	prepared_str[0] = 'i';
	int prepared_pos = 0;
	int in_pos = 0;
	while(in_pos < str_len) {
		prepared_str += "i";
		prepared_str += in_str[in_pos++];
	}
	prepared_str += "i";

	cout << in_str << endl << prepared_str << endl;

	return prepared_str;
}

int main(void) {
	string in_str;

	cin >> in_str;

	int max_pali = (checkMaxPali(stringProcess(in_str))-1)/2;
	cout << max_pali << endl;

	return 0;
}