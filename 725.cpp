#include <iostream>
#include <math.h>
#include <string>
using namespace std;





bool digitosDiferentes(string number1, string number2){
	int i, j;
	if(number2.length() == 4)
		number2.insert(0, "0");
	for(i = 0; i < number1.length() ; i++)
		for(j = 0; j < number2.length(); j++)
			if(number1[i]==number2[j])
				return false;
		
	for(i = 0; i < number1.length() ; i++)
		for(j = 0; j < number1.length();j++)
			if(j!=i and number1[i] == number1[j])
				return false;

	for(i = 0; i < number2.length() ; i++)
		for(j = 0; j < number2.length();j++)
			if(j!=i and number2[i] == number2[j])
				return false;

	return true;

}


int main(){
	bool flag;
	int input, denominador, a, counter = 1;
	string numerador;

	while(true){
		flag = false;

		cin >> input;

		if(input == 0)
			break;

		if(counter > 1)
			cout << endl;


		for(int denominador = 1234; denominador < 50000; denominador++){
			a = denominador * input;
			numerador = to_string(a);
			if(digitosDiferentes(to_string(denominador*input), to_string(denominador)) and numerador.length() == 5){
				flag = true;
				if(not (int)(denominador/10000))
					cout << denominador*input << " / 0" << denominador << " = " << input << endl;
				else
					cout << denominador*input << " / " << denominador << " = " << input << endl;
			}
		}

		if(not flag)
			cout << "There are no solutions for " << input << "." << endl;

		counter++;
		



	
	}



	return 0;

}


