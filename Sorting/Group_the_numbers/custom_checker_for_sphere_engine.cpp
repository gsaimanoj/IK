// Using C++14 (gcc-5 5.1.1) 

#include "spoj.h"
#include <bits/stdc++.h>

using namespace std;

class ResultStruct {
public:
	bool   result;
	float  score;
	string message;
};

string read_whole_file_into_string(FILE * f) {

	char * buffer = '\0';
	int length;
	
	if (f) {
		fseek (f, 0, SEEK_END);
		length = (int) ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = (char *) malloc (length + 1);
		if (buffer) {
			fread (buffer, 1, length, f);
			buffer[length] = '\0';
		}
	}
	if (buffer) {
		return string(buffer);
	}
	return "";
}

// ------------------------- START -------------------------

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
	ResultStruct &r_obj) {

	//Don't print anything to STDOUT in this function
	//Enter your custom checker scoring logic here

	r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";


    int n;
    input_file >> n;
    vector<int> arr(n);
    int no_of_even_elements = 0;
    for (int i = 0; i < n; i++)
    {
    	input_file >> arr[i];
    	if (arr[i] % 2 == 0)
    	{
    		no_of_even_elements++;
    	}
    }


    vector<int> ans;
    int temp;
    while(output_file >> temp)
    {
    	ans.push_back(temp);
    }
    if (ans.size() != n)
    {
    	r_obj.result = false;
        r_obj.score = 0.0f;
        r_obj.message = "Wrong answer!";
        return;
    }


    vector<int> ans_copy = ans;
    sort(arr.begin(), arr.end());
    sort(ans_copy.begin(), ans_copy.end());

    for (int i = 0; i < n; i++)
    {
    	if (arr[i] != ans_copy[i])
    	{
    		r_obj.result = false;
	        r_obj.score = 0.0f;
	        r_obj.message = "Wrong answer!";
	        return;
    	}
    }


    for (int i = 0; i < n; i++)
    {
    	if (i < no_of_even_elements && ans[i] % 2 != 0)
    	{
    		r_obj.result = false;
	        r_obj.score = 0.0f;
	        r_obj.message = "Wrong answer!";
	        return;
    	}
    }
}

// ------------------------- STOP -------------------------

int main(void) {
	spoj_init();

	string whole_input = read_whole_file_into_string(spoj_p_in);
	string whole_expected_output = read_whole_file_into_string(spoj_p_out);
	string whole_output = read_whole_file_into_string(spoj_t_out);

	cerr << "Input length: " << whole_input.length() << endl;
	// cerr << "Input:" << endl;
	// cerr << whole_input << endl;

	cerr << "Expected output length: " << whole_expected_output.length() << endl;
	// cerr << "Expected output:" << endl;
	// cerr << whole_expected_output << endl;

	cerr << "Output length: " << whole_output.length() << endl;
	// cerr << "Output:" << endl;
	// cerr << whole_output << endl;

	ResultStruct r_obj;
	r_obj.result = false;
	r_obj.score = 0.0f;
	r_obj.message = "Uninitialized";

	stringstream input_file(whole_input);
	stringstream expected_output_file(whole_expected_output);
	stringstream output_file(whole_output);


	run_custom_checker(input_file, expected_output_file, output_file, r_obj);
	if (r_obj.result) {
		return SPOJ_RV_POSITIVE;
	}

	return SPOJ_RV_NEGATIVE;
}
