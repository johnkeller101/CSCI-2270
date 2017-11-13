#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[6] = { 40, 26, 15, 12, 5, 17 };
	for(int i=0;i<6;i++){
		cout << arr[i] % 7 << endl;
	}
	return 0;
}


int hashSum(int input, int hashTableSize){
	// quadratic hash sum

	int h = input % hashTableSize;
	int proble = 1;

	while()
}

int insertNumber(int input, int array[], int hashTableSize){
	int numHashSum = hashSum(input, hashTableSize);

	if(array[numHashSum] == NULL){
		array[numHashSum] = input;
	} else {
		array[numHashSum] = input;
	}
}