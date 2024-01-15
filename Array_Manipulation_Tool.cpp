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





//Delete Element
//--------------------------------------------------------------------------------------//

//Delete an element within an array
//We use int here in order to return a success or failure
//Success will return the element deleted, failure will return 1
//This function requires a pointer for this ADT Array, and the index to be deleted
int deleteElement(struct Array* arr, int index) {

	//Deletion value, initialized
	int deletedValue = 0;


	//Check to see if the index from the input is valid, if it is between
	//0 and the length - 1, since length vacant
	if (index >= 0 && index <= arr->length - 1) {

		//this represents the actual value that we will delete after the for loop
		//this value will get printed back to the user
		deletedValue = arr->A[index];


		//This for loop starts off at the position of index, which is where the user wants to
		//make a deletion, the reason why its up to length - 1 is because:
		//there is no value at length, the last value inside of our array is length - 1
		//So if we go from userIndex < length, then our logic will copy the content
		// of length  and place it into length -1, which is incorrect, we are only worried about
		// the elements within our array, and length is not apart of our array
		for (int i = index; i < arr->length - 1; i++) {

			//transfers the content of index + 1, into index, which shifts everything to the left
			arr->A[i] = arr->A[i + 1];
		}

		//Decrease the length by 1 since we removed a value
		arr->length--;

		//return the deleted value back to user
		return deletedValue;
	};

	//if the user enters an invalid index, return 1 instead to signify an error
	return 1;
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
	std::cout << "Enter a Vlue that you would like to append to the array: ";
	std::cin >> element;

	//Append Element
	append(&array1, element);




	//Ask user at which index would they like to delete a value?
	std::cout << "Enter the Index at which you would like to delete a value: ";
	std::cin >> index;

	//Delete Element
	deleteElement(&array1, index);






	//Display Element
	for (int i = 0; i < array1.size; i++) {
		std::cout << array1.A[i] << '\n';
	};

	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0; 

};