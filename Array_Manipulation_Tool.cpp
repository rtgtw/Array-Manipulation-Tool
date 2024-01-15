#include <iostream>





//Create an array structure with an int pointer, and size and length of the array as member variables
struct Array {

	int* A;
	int size;
	int length;
};



//Insert Element
//--------------------------------------------------------------------------------------//

//Take the array by ADDRESS since it will modify the array
//This is pointing to the OBJECT arr, not a particular arr, just the WHOLE object
//Meaning we can modify its member variables 
void insertElement(struct Array* arr, int index, int value) {

	//Check to see if the size of the array is big enough for another element
	if (arr->length + 1 > arr->size) {

		std::cout << "Error: Array is not big enough" << '\n';

		return;
	};


	// we have to check if the index is valid, which is 0 to the length of the array
	//if you do index < arr-> then you cannot append because it will not insert at the length of the array
	//but if you do <= then it will insert at the next available slot


	if (index >= 0 && index <= arr->length) {

		//Creates a for loop that iterates from the length of the array
		//down to the value of index(where the user wants the value to go)
		for (int i = arr->length; i > index; i--) {

			//A[i] represents the next available location
			//we want to take the last element inside of the array with i-1, and equal it to A[i]
			//this will shift all of the elements up until we hit  index(location of newly inserted value), 
			arr->A[i] = arr->A[i - 1];
		};
		//then we insert our values since everything has been shifted
		arr->A[index] = value;

		//the length of our index has grown by 1 since we inserted a value, so we have to 
		//increase the legnth
		arr->length++;
	};

};


//--------------------------------------------------------------------------------------//









//Append Element
//--------------------------------------------------------------------------------------//

//Inserts a new element at the end of the array
//we will use a pointer as the parameter since we want to change the value by address
void append(struct Array* arr, int x) {


	// This verifies that there is room inside of the array
	//if length = size then there is no room inside of the array
	//Meaning we cannot perform the append logic
	if (arr->length < arr->size) {
		arr->A[arr->length++] = x;

	}
	else {
		std::cout << "Error: not enough room inside of the array. Cannot perform operation" << '\n';
	}
};

//--------------------------------------------------------------------------------------//




















int main() { 
	
	//Create an Array object
	struct Array array1;

	//Create variables
	int index;
	int element;

	//Ask user to input Array Size
	std::cout << "Enter the size you want your array to be: ";
	std::cin >> array1.size;
	
	//Initialize the value of Array Object's length to 0
	array1.length = 0;

	//Dynamically create an object array based off user input
	array1.A = new int[array1.size];


	//Ask user for index and element to insert into array
	std::cout << "Enter an Index and Element to insert into array: ";
	std::cin >> index;
	std::cin >> element;

	//Insert Element
	insertElement(&array1, index, element);





	//Ask user what value they would like to append to the existing array
	std::cout << "Enter a value that you would like to append to the array: ";
	std::cin >> element;

	//Append Element
	append(&array1, element);



	//Display Element
	for (int i = 0; i < array1.size; i++) {
		std::cout << array1.A[i] << '\n';
	};

	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0; 

};